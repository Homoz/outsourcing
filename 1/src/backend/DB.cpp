#include <cstdlib>
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

DB & DB::instance() {
    static DB db;
    return db;
}

void DB::insertOne(const Staff &staff) {
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
    if (rc != SQLITE_OK) {
        Log::e(string("SQL error: ") + string(zErrMsg));
        sqlite3_free(zErrMsg);
    } else {
        Log::i(string("insert succeed!"));
    }
}

void DB::remove(int id) {
    string sql = string("DELETE FROM ") + DB::TABLIE_NAME 
        + string(" where id=") + Utils::to_string(id);
    Log::i(string("sql: ") + sql);
    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), NULL,
            NULL, &zErrMsg);
    if (rc != SQLITE_OK) {
        Log::e(string("SQL error: ") + string(zErrMsg));
        sqlite3_free(zErrMsg);
    } else {
        Log::i(string("delete succeed!"));
    }
}

void DB::update(const Staff &staff) {
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
    if (rc != SQLITE_OK) {
        Log::e(string("SQL error: ") + string(zErrMsg));
        sqlite3_free(zErrMsg);
    } else {
        Log::i(string("update succeed!"));
    }
}

static int recordToStaff(void *data, int argc, char **argv,
        char **azColName) {
    vector<Staff> result = *(vector<Staff> *)data;
    Staff staff;
    for (int i = 0; i < argc; ++i) {
        staff.set(string(azColName[i]), argv[i]);
    }
    result.insert(result.end(), staff);
    return 0;
}

vector<Staff> DB::findAll(map<string, string> *filter) {
    vector<Staff> result;
    if (!filter) {
        Log::w(string("empty filter, so nothing filtered"));
    } else {
        map<string, string>::iterator iter;
        for (iter=filter->begin(); iter!=filter->end(); ++iter) {
        }
    }

    string sql = string("SELECT * FROM ") + DB::TABLIE_NAME;
    Log::i(string("sql: ") + sql);
    char *zErrMsg = NULL;
    int rc = sqlite3_exec(DB::db, sql.c_str(), recordToStaff, 
            (void *)&result, &zErrMsg);
    if (rc != SQLITE_OK) {
        Log::e(string("SQL error: ") + string(zErrMsg));
        sqlite3_free(zErrMsg);
    } else {
        Log::i(string("findAll succeed!"));
    }
    
    return result;
}

