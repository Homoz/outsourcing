#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "Employee.h"
#include <stdio.h>

struct Archive {
    int MAX_BUFFER_SIZE;
    char path[32]; 
    FILE * archiveFile;
};

void initArchive(struct Archive *, const char *);
void finitArchive(struct Archive *);
void add(struct Archive *, struct Employee *);
void update(struct Archive *, struct Employee *);
void deleteByName(struct Archive *, const char *);
void findByName(struct Archive *, const char *, 
        struct Employee **);
void save(struct Archive *);

#endif
