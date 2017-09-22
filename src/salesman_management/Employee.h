#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
  char name[16];
  int age;
  int sex;
  char education[16];
  double salary;
  char address[128];
  char phoneNumber[16];
  int isValid;
};

void printEmployee(struct Employee *);

#endif
