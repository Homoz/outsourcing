#ifndef UTILS_H
#define UTILS_H

// 营销员转化为字符串
void employeeToStr(char **dest, struct Employee *employee);
// 字符串构造营销员
void strToEmployee(const char *str, struct Employee **employee);

#endif
