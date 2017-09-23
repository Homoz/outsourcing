#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Utils.h"

const char *RECORD_FORMAT = "%d %s %d %d %s %lf %s %s\n";

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

void printAllValid(struct Archive *arch) {
    // 设置文件读写头到文件开头
    fseek(arch->archiveFile, 0, SEEK_SET);
    char buffer[256];
    struct Employee *employee = NULL;
    while (!feof(arch->archiveFile) 
            && fgets(buffer, 255, arch->archiveFile)) {
        
        strToEmployee(buffer, &employee);
        if (employee->isValid) { 
            const char *gender = NULL;
            if (employee->sex) {
                gender = "男";
            } else {
                gender = "女";
            }
            const char *format = "%s %d %s %s %.2lf %s %s\n";
            printf(format, employee->name, employee->age, gender,
                    employee->education, employee->salary, 
                    employee->address, employee->phoneNumber);

        }
        free(employee);
    }
}

void printEmployee(struct Employee *employee) {
    const char *gender = NULL;
    if (employee->sex) {
        gender = "男";
    } else {
        gender = "女";
    }
    const char *format = "姓名: %s\n年龄: %d\n性别: %s\n"
        "学历: %s\n薪水: %.2lf\n地址: %s\n电话: %s\n";
    printf(format, employee->name, employee->age, gender,
            employee->education, employee->salary, 
            employee->address, employee->phoneNumber);
}
