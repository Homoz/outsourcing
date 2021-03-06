#ifndef UTILS_H
#define UTILS_H

#include "Employee.h"
#include "Archive.h"

// 营销员转化为字符串
void employeeToStr(char **, struct Employee *);
// 字符串构造营销员
void strToEmployee(const char *, struct Employee **);

// 报错函数
void logger(char, const char *);

// 记录打印函数
void printAllValid(struct Archive *);
// 打印 Employee 信息
void printEmployee(struct Employee *);

#endif
