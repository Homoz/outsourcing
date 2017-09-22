#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *toString(const Employee &emplyee) {
  char *name = emplyee.name;
  char *age;
  itoa(emplyee.age, age, 10);
  char sex;
  if (emplyee.sex = 0) {
    sex = "女";
  } else {
    sex = "男";
  }

  char *reslut = malloc()
}
