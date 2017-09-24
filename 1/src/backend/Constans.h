#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using std::string;


class StaffType {
    public:
        static const int ADMINISTRATION = 0;  // 行政人员
        static const int EDUCATION = 1;       // 教学人员
        static const int ASSISTANT = 2;       // 教辅人员
        static const int LOGISTICS = 3;       // 后勤人员
        static const int RETIRED = 4;         // 已退休

        static string getTypeString(int index) {
            switch (index) {
                case StaffType::ADMINISTRATION:
                    return string("行政人员");
                case StaffType::EDUCATION:
                    return string("教学人员");
                case StaffType::ASSISTANT:
                    return string("教辅人员");
                case StaffType::LOGISTICS:
                    return string("后勤人员");
                case StaffType::RETIRED:
                    return string("已退休");
                default:
                    return string("");
            }
        }
};

class Department {
    public:
        static const int PARTY = 0;           // 党群部门
        static const int ADMINISTRATION = 1;  // 行政机构
        static const int EDUCATION = 2;       // 教学部门
        static string getTypeString(int index)  {
            switch (index) {
                case Department::PARTY:
                    return string("党群部门");
                case Department::ADMINISTRATION:
                    return string("行政机构");
                case Department::EDUCATION:
                    return string("教学部门");
                default:
                    return string("");
            }
        }
};

#endif
