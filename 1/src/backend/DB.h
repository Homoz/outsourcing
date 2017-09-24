#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <map>
#include "sqlite3.h"
#include "Staff.h"

using std::string;
using std::vector;
using std::map;

class DB {

    private:
        static sqlite3 *db;
        static string TABLIE_NAME;
        static string FILE_NAME;
        DB();

    public:
        ~DB();
        static DB& instance();
        void insertOne(const Staff &staff);
        void remove(int id);
        void update(const Staff &staff);
        vector<Staff> findAll(map<string, string> *filter);
};

#endif
