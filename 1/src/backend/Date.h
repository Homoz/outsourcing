#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

class Date {
    public:
        int year;
        int month;
        
        Date(int year, int month);
        Date(const Date &date);
        // 格式例子: 1970-2 或者 1975-11
        Date(const char *date);
        bool operator <(const Date &rValue) const;
        bool operator ==(const Date &rValue) const;
        bool operator <=(const Date &rValue) const;
        bool operator >(const Date &rValue) const;
        bool operator >=(const Date &rValue) const;
        bool operator !=(const Date &rValue) const;

        string toString() const;
};

#endif
