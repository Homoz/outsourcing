#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Utils.h"

const char *RECORD_FORMAT = "%d %s %d %d %s %lf %s %s \n";

void employeeToStr(char **dest, struct Employee *employee) {
    unsigned int size = 256;
    *dest = (char *)malloc(size);
    memset(*dest, 0, size);
    snprintf(*dest, size, RECORD_FORMAT, employee->isValid,
            employee->name, employee->age, employee->sex, 
            employee->education, employee->salary, 
            employee->address, employee->phoneNumber);
}

void strToEmployee(const char *str, struct Employee **employee) {
    *employee = (struct Employee *)malloc(sizeof(struct Employee));
    memset(*employee, 0, sizeof(struct Employee));
    sscanf(str, RECORD_FORMAT, &((*employee)->isValid),
            (*employee)->name, &((*employee)->age), 
            &((*employee)->sex), (*employee)->education,
            &((*employee)->salary), (*employee)->address,
            (*employee)->phoneNumber);
}

void logger(char type, const char *msg) {
    switch (type) {
        case 'i':
            fprintf(stderr, "info: %s\n", msg);
            break;
        case 'w':
            fprintf(stderr, "warning: %s\n", msg);
            break;
        case 'e':
            fprintf(stderr, "error: %s\n", msg);
            break;
        default:
            fprintf(stderr, "default: %s\n", msg);
    }
}
