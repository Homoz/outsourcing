#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "Employee.h"
#include <stdio.h>

struct Archive {
    int MAX_BUFFER_SIZE;
    char path[32]; 
    FILE * archiveFile;
};

// 初始化 Archive
void initArchive(struct Archive *, const char *);
// 资源释放
void finitArchive(struct Archive *);
void add(struct Archive *, struct Employee *);
// 返回 0 表示修改成功, 否则修改失败
int update(struct Archive *, struct Employee *);
// 返回 0 表示删除成功, 否则删除失败
int deleteByName(struct Archive *, const char *);
// 返回 0 表示 Archive 有对应的有效记录, 否则没有
int findByName(struct Archive *, const char *, 
        struct Employee **);

#endif
