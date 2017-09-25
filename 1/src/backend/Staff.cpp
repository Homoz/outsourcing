#include <cstdlib>
#include "Staff.h"
#include "Utils.h"
#include "Constans.h"
#include "Log.h"

Staff::Staff(int id, string name, string gender, int type,
        int department, Date birthDay, string title,
        string education, double salary, bool isMarried) 
    :birthDay(birthDay)
{
    
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->type = type;
    this->department = department;
    this->title = title;
    this->education = education;
    this->salary = salary;
    this->isMarried = isMarried;
}

Staff::Staff(const Staff &staff) 
    : birthDay(staff.birthDay)
{
    this->id = staff.id;
    this->name = staff.name;
    this->gender = staff.gender;
    this->type = staff.type;
    this->department = staff.department;
    this->title = staff.title;
    this->education = staff.education;
    this->salary = staff.salary;
    this->isMarried = staff.isMarried;
}

void Staff::set(string attrName, const char *attrValue) {
    if (attrName == "id") {
        this->id = atoi(attrValue);
    } else if (attrName == "name") {
        this->name = string(attrValue);
    } else if (attrName == "gender") {
        this->gender = string(attrValue);
    } else if (attrName == "type") {
        this->type = atoi(attrValue);
    } else if (attrName == "department") {
        this->department = atoi(attrValue);
    } else if (attrName == "birthDay") {
        this->birthDay = Date(attrValue);
    } else if (attrName == "title") {
        this->title = string(attrValue);
    } else if (attrName == "education") {
        this->education = string(attrValue);
    } else if (attrName == "salary") {
        this->salary = atof(attrValue);
    } else if (attrName == "isMarried") {
        this->isMarried = (bool)atoi(attrValue);
    } else {
        Log::e(string("attempt to set a not existing attribute!!!"));
    }
}

string Staff::toString() const {
    string result = "";
    string delimiter = " ";
    result += (this->getId() + delimiter);
    result += (this->getName() + delimiter);
    result += (this->getGender() + delimiter);
    result += (this->getType() + delimiter);
    result += (this->getDepartment() + delimiter);
    result += (this->getBirthDay() + delimiter);
    result += (this->getTitle() + delimiter);
    result += (this->getEducation() + delimiter);
    result += (this->getSalary() + delimiter);
    result += (this->getMarry() + delimiter);
    return result;
}

string Staff::getId() const {
    return Utils::to_string(this->id);
}

string Staff::getName() const {
    return this->name;
}

string Staff::getGender() const {
    return this->gender;
}

string Staff::getType() const {
    return StaffType::getTypeString(this->type);
}

string Staff::getDepartment() const {
    return Department::getTypeString(this->department);
}

string Staff::getBirthDay() const {
    return this->birthDay.toString();
}

string Staff::getTitle() const {
    return this->title;
}

string Staff::getEducation() const {
    return this->education;
}

string Staff::getSalary() const {
    return Utils::to_string(this->salary);
}

string Staff::getMarry() const {
    if (this->isMarried) {
        return string("已婚");
    } else {
        return string("未婚");
    }
}
