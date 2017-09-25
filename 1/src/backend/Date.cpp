#include <cstdlib>
#include "Date.h"
#include "Utils.h"

Date::Date(int year, int month) {
    this->year = year;
    this->month = month;
}

Date::Date(const Date &date) {
    this->year  = date.year;
    this->month = date.month;
}

Date::Date(const char *date) {
    string dateStr = date;
    string delimiter = "-";
    size_t pos = dateStr.find(delimiter, 0);
    string yearStr = dateStr.substr(0, pos);
    string monthStr = dateStr.substr(pos+1);
    this->year = atoi(yearStr.c_str());
    this->month = atoi(monthStr.c_str());
}

bool Date::operator <(const Date &rValue) const {
    return this->year  < rValue.year || 
               (this->year == rValue.year &&
               this->month <  rValue.month);
}

bool Date::operator ==(const Date &rValue) const {
    return this->year == rValue.year &&
           this->month == rValue.month;
}

bool Date::operator <=(const Date &rValue) const {
    return *this < rValue || *this == rValue;
}

bool Date::operator >(const Date &rValue) const {
    return !(*this <= rValue);
}

bool Date::operator >=(const Date &rValue) const {
    return !(*this < rValue);
}
bool Date::operator !=(const Date &rValue) const {
    return !(*this == rValue);
}

string Date::toString() const {
    return Utils::to_string(this->year) + string("-") 
        + Utils::to_string(this->month);
}
