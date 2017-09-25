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
        bool filter(map<string, string> *conditions,
                const Staff &staff) const;
        void handleErrorMessageIfAny(int rc, char *zErrMsg,
                string hint) const;
        vector<Staff> fetchAll() const;

    public:
        ~DB();
        static DB& getInstance();
        void insertOne(const Staff &staff) const;
        void remove(int id) const;
        void update(const Staff &staff) const;

        /* 用法:
         *   注: 键值对都是 std::string 类型
         *       以下条件不矛盾的可以混合传入多个键值对
         * 
         *      1. 获取全体, 则传入空指针
         *      2. 获取某部门职工:
         *          传入 "department" -> "department number"
         *          department number 定义在 Constans.h 中
         *      3. 获取某职称职工:
         *          传入 "title" -> "具体title"
         *      4. 某年月以后出生的职工
         *          传入 "birthDay+" -> "xxxx-xx"
         *          月份一位数只传一位数
         *      5. 某年月以前出生的职工
         *          传入 "birthDay-" -> "xxxx-xx"
         *      6. 未婚职工
         *          传入 "isMarried" -> "0" */
        vector<Staff> findAllSatisfies(
                map<string, string> *conditions) const ;
};

#endif
