#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
  char name[8];
  int age;
  bool sex;
  char education;
  double salary;
  char address[128];
  char phoneNumber[16];
};

const char *toString(const Employee &);

#endif
