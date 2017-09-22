#include "Management.h"
#include "Emplyee.h"
#include <stdio.h>

// run
void run();
//增加
void addEmployee(Employee *employee) { printf("请输入姓名:"); }
//删除
void removeEmployee(Employee *);
//查找
void selectEmployee(Employee *);
//更新
void updateEmployee(Employee *);
//打印all
void printAll();
