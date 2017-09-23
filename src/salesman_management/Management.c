#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Archive.h"
#include "Management.h"

// run
void run();
//增加
void addEmployee(struct Employee *employee) {
    printf("请输入姓名:"); 
}
//删除
void removeEmployee(struct Employee *);
//查找
void selectEmployee(struct Employee *);
//更新
void updateEmployee(struct Employee *);
//打印all
void printAll();

void init() {
    g_arch = (struct Archive *)malloc(
            sizeof(struct Archive));
    initArchive(g_arch, "data/archive.txt");
}

void finit() {
    finitArchive(g_arch);
}
