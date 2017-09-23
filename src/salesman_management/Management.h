#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Employee.h"

// 唯一全局档案
struct Archive *g_arch;

// run
void run();
//增加
void addEmployee(struct Employee *);
//删除
void removeEmployee(struct Employee *);
//查找
void selectEmployee(struct Employee *);
//更新
void updateEmployee(struct Employee *);
//打印all
void printAll();

// 初始化
void init();
// 扫尾工作
void finit();

#endif
