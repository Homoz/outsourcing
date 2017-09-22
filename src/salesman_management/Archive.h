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
void add(struct Archive *, struct Employee *);
void update(struct Archive *, struct Employee *);
void delete(struct Archive *, struct Employee *);
void find(struct Archive *, struct Employee *);
void save(struct Archive *);

#endif
