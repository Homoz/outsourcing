#include <string.h>
#include <stdlib.h>
#include "Utils.h"
#include "Archive.h"

void init(struct Archive *, const char *path);
void add(struct Archive *, struct Employee *);
void update(struct Archive *, struct Employee *);
void delete(struct Archive *, struct Employee *);
void find(struct Archive *, struct Employee *);
void save(struct Archive *);

void initArchive(struct Archive *arch, const char *path) {
    arch->MAX_BUFFER_SIZE = 64;
    if (strlen(path) >= arch->MAX_BUFFER_SIZE) {
        fprintf(stderr, "error: exceed max buffer size");
        logger('e', "exceed max buffer size");
        exit(1);
    }
    int i = 0;
    for (; i < strlen(path); ++i) {
        arch->path[i] = path[i];
    }
    arch->archiveFile = fopen(arch->path, "r+");
    if (!arch->archiveFile) {
        fprintf(stderr, "error: failed to open %s\n", 
                arch->path);
        // TODO: 指出文件名
        logger('e', "failed to open data file");
        exit(1);
    }
}

// 文件结尾追加一条记录
void add(struct Archive *arch, struct Employee *emplyee) {
    // 设置文件读写头
    fseek(arch->archiveFile, 0, SEEK_END);
    char *buffer = NULL;
    employeeToStr(&buffer, emplyee);
    fprintf(arch->archiveFile, "%s", buffer);
    free(buffer);

}
