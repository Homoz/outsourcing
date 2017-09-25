#include <cstdlib>
#include <algorithm>
#include "DB.h"
#include "Log.h"
#include "Utils.h"

string DB::FILE_NAME = string("StaffInfo.db");
string DB::TABLIE_NAME = string("staff_info");
sqlite3* DB::db = NULL;

DB::DB() {
    int rc = sqlite3_open(DB::FILE_NAME.c_str(), &DB::db);
    if (rc) {
        Log::e(string(sqlite3_errmsg(DB::db)));
        Log::e(string("failed to open database, exit"));
        sqlite3_close(this->db);
        exit(1);
    }

}

DB::~DB() {
    sqlite3_close(DB::db);
}

DB & DB::getInstance() {
    static DB db;
    return db;
}

void DB::insertOne(const Staff &staff) const {
    string comma = ",";
    string apostrophe = "'";
    string nullStr = "";
    string sql = string("INSERT INTO ") + DB::TABLIE_NAME 
        + string(" (name, gender, type, department, birthDay, "
                "title, education, salary, isMarried) values(")
        + Utils::surroundWith(staff.getName(), apostrophe, comma)
        + Utils::surroundWith(staff.getGender(), apostrophe, comma)
        + Utils::surroundWith(Utils::to_string(staff.type),
                nullStr, comma)
        + Utils::surroundWith(Utils::to_string(staff.department),
                nullStr, comma)
        + Utils::surroundWith(staff.getBirthDay(),
                apostrophe, comma)
        + Utils::surroundWith(staff.getTitle(),
                apostrophe, comma)
        + Utils::surroundWith(staff.getEducation(),
                apostrophe, comma)
        + Utils::surroundWith(staff.getSalary(),
                nullStr, comma)
        + Utils::surroundWith(Utils::to_string(staff.isMarried),
                nullStr, string(");"));
    Log::i(string("sql: ") + sql);

    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), NULL,
            NULL, &zErrMsg);
    DB::handleErrorMessageIfAny(rc, zErrMsg,
            string("add"));
}

void DB::remove(int id) const {
    string sql = string("DELETE FROM ") + DB::TABLIE_NAME 
        + string(" where id=") + Utils::to_string(id);
    Log::i(string("sql: ") + sql);
    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), NULL,
            NULL, &zErrMsg);
    DB::handleErrorMessageIfAny(rc, zErrMsg,
            string("delete"));
}

void DB::update(const Staff &staff) const {
    string sql = string("UPDATE ") + DB::TABLIE_NAME
        + string(" set name = '") + staff.getName()
        + string("', gender = '") + staff.getGender()
        + string("', type = ") + Utils::to_string(staff.type)
        + string(", department = ") 
        + Utils::to_string(staff.department)
        + string(", birthDay = '") + staff.getBirthDay()
        + string("', title = '") + staff.getTitle()
        + string("', education = '") + staff.getEducation()
        + string("', salary = ") + Utils::to_string(staff.salary)
        + string(", isMarried = ")
        + Utils::to_string(staff.isMarried)
        + string(" where id=") + staff.getId() + string(";");
    Log::i(string("sql: ") + sql);

    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), NULL,
            NULL, &zErrMsg);
    DB::handleErrorMessageIfAny(rc, zErrMsg,
            string("update"));
}

static int recordToStaff(void *data, int argc, char **argv,
        char **azColName) {
    vector<Staff> *result = (vector<Staff> *)data;
    Staff staff;
    for (int i = 0; i < argc; ++i) {
        staff.set(string(azColName[i]), argv[i]);
    }
    result->insert(result->end(), staff);
    return 0;
}

vector<Staff> DB::fetchAll() const {
    vector<Staff> result;

    string sql = string("SELECT * FROM ") + DB::TABLIE_NAME;
    Log::i(string("sql: ") + sql);
    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), recordToStaff, 
            (void *)&result, &zErrMsg);
    DB::handleErrorMessageIfAny(rc, zErrMsg,
            string("findAll"));

    return result;
}

void DB::handleErrorMessageIfAny(int rc, char *zErrMsg,
        string hint) const {

    if (rc != SQLITE_OK) {
        Log::e(string("SQL error: ") + string(zErrMsg));
        sqlite3_free(zErrMsg);
    } else {
        Log::i(hint + string(" succeed!"));
    }
}

bool DB::filter(map<string, string> *conditions,
        const Staff &staff) const {

    map<string, string>::iterator iter;
    for (iter = conditions->begin(); iter != conditions->end();
            ++iter) {

        string key = iter->first;
        string value = iter->second;

        if (key == "department") {
            if (value != Utils::to_string(staff.department))
                return false;
        } else if (key == "title"){
            if (value != staff.getTitle())
                return false;
        } else if (key == "birthDay+") {
            // Date 按年月字面值比较
            if (Date(value.c_str()) >= staff.birthDay)
                return false;
        } else if (key == "birthDay-") {
            if (Date(value.c_str()) <= staff.birthDay)
                return false;
        } else if (key == "isMarried") {
            bool isMarried = (atoi(value.c_str()) != 0);
            if (isMarried != staff.isMarried)
                return false;
        } else {
            Log::e(string("invalid key used to filter"));
            return false;
        }
    }

    return true;
}

// 先查询数据库, 再过滤, 性能问题
vector<Staff> DB::findAllSatisfies(
        map<string, string> *conditions) const {

    vector<Staff> allStaff = fetchAll();
    if (!conditions || conditions->empty())
        return allStaff;

    vector<Staff> result;

    for (unsigned long i = 0; i < allStaff.size(); ++i) {
        if (this->filter(conditions, allStaff[i])) {
            result.push_back(allStaff[i]);
        }
    }

    return result;
}
