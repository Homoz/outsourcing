#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "Constans.h"
#include "Date.h"

using std::string;

class Staff {

    public:
        int id;             // 编号
        string name;
        string gender;
        int type;           // 类别
        int department;     // 部门
        Date birthDay;      // 出生年月
        string title;       // 职称
        string education;
        double salary;
        bool isMarried;

        Staff(int id=0, string name="", string gender="",
              int type=0, int department=0, 
              Date birthDay=Date(1970,1), string title="",
            string education="", double salary=0.0,
            bool isMarried=false);
        Staff(const Staff &staff);

        string toString() const;

        void set(string attrName, const char *attrValue);

        string getId() const;
        string getName() const;
        string getGender() const;
        string getType() const;
        string getDepartment() const;
        string getBirthDay() const;
        string getTitle() const;
        string getEducation() const;
        string getSalary() const;
        string getMarry() const;
};

#endif
