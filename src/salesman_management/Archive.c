#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "Utils.h"
#include "Archive.h"

void initArchive(struct Archive *, const char *path);
void finitArchive(struct Archive *);
void add(struct Archive *, struct Employee *);
void update(struct Archive *, struct Employee *);
int deleteByName(struct Archive *, const char *);
int findByName(struct Archive *, const char *, 
        struct Employee **);
void save(struct Archive *);
void printAllValid(struct Archive *);

void initArchive(struct Archive *arch, const char *path) {
    arch->MAX_BUFFER_SIZE = 64;
    if (strlen(path) >= arch->MAX_BUFFER_SIZE) {
        /* fprintf(stderr, "error: exceed max buffer size"); */
        logger('e', "exceed max buffer size");
        exit(1);
    }
    int i = 0;
    for (; i < strlen(path); ++i) {
        arch->path[i] = path[i];
    }
    /* TODO: 文件不存在时会报错 */
    arch->archiveFile = fopen(arch->path, "r+");
    if (!arch->archiveFile) {
        logger('e', strerror(errno));
        exit(1);
    }
}

void finitArchive(struct Archive *arch) {
    if (arch->archiveFile) {
        if (fclose(arch->archiveFile)) { // 文件关闭出错
            logger('e', strerror(errno));
        }
    } else {
        logger('w', "no open file, so not close");
    }
}

// 文件结尾追加一条记录
void add(struct Archive *arch, struct Employee *employee) {
    // 设置文件读写头到文件结尾
    fseek(arch->archiveFile, 0, SEEK_END);
    char *buffer = NULL;
    employeeToStr(&buffer, employee);
    fprintf(arch->archiveFile, "%s", buffer);
    free(buffer);
}

// 调用者需要释放 employee
int findByName(struct Archive *arch, const char *name, 
        struct Employee **employee) {
    // 设置文件读写头到文件开头
    fseek(arch->archiveFile, 0, SEEK_SET);
    char buffer[256];
    struct Employee *iter = NULL;
    while (!feof(arch->archiveFile) 
            && fgets(buffer, 255, arch->archiveFile)) {
        
        strToEmployee(buffer, &iter);
        if (iter->isValid && !strcmp(name, iter->name)) { // 匹配到
            *employee = iter;
            return 0;
        }
        free(iter);
    }
    *employee = NULL; // 未匹配到
    return 1;
}

int deleteByName(struct Archive *arch, const char *name) {
    // 设置文件读写头到文件开头
    fseek(arch->archiveFile, 0, SEEK_SET);
    char buffer[256];
    struct Employee *iter = NULL;
    while (!feof(arch->archiveFile)
            && fgets(buffer, 255, arch->archiveFile)) {

        strToEmployee(buffer, &iter);
        if (iter->isValid && !strcmp(name, iter->name)) { // 匹配到
            size_t recodeLength = strlen(buffer);
            // 设置文件读写头到本条记录开始
            fseek(arch->archiveFile, -recodeLength, SEEK_CUR);
            // 设置记录中的是否有效字段为无效
            fprintf(arch->archiveFile, "%d", 0);
            return 0;
        }
        free(iter);
    }
    return 1; // 无 name 对应的有效记录, 删除失败
}

void printAllValid(struct Archive *arch) {
    // 设置文件读写头到文件开头
    fseek(arch->archiveFile, 0, SEEK_SET);
    char buffer[256];
    struct Employee *iter = NULL;
    while (!feof(arch->archiveFile) 
            && fgets(buffer, 255, arch->archiveFile)) {
        
        strToEmployee(buffer, &iter);
        if (iter->isValid) { 
            printf("%s", buffer);
        }
        free(iter);
    }
}
