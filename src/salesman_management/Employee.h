#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
  char name[16];
  int age;
  bool sex;
  char education[16];
  double salary;
  char address[128];
  char phoneNumber[16];
  bool isValid;
};

void printEmployee(const Employee &);

#endif
