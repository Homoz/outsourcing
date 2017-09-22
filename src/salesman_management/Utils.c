#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Employee.h"

void employeeToStr(char **dest, struct Employee *employee) {
    unsigned int size = 256;
    *dest = (char *)malloc(size);
    memset(*dest, 0, size);
    snprintf(*dest, size, "%s %d %d %s %lf %s %s %d", 
            employee->name, employee->age, employee->sex, employee->education,
            employee->salary, employee->address, employee->phoneNumber, employee->isValid);
}

void strToEmployee(const char *str, struct Employee **employee) {
    *employee = (struct Employee *)malloc(sizeof(struct Employee));
    memset(*employee, 0, sizeof(struct Employee));
    sscanf(str, "%s %d %d %s %lf %s %s %d",
            (*employee)->name, &((*employee)->age), &((*employee)->sex),
            (*employee)->education,&((*employee)->salary),(*employee)->address,
            (*employee)->phoneNumber,&((*employee)->isValid));
}
