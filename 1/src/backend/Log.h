#ifndef LOG_H
#define LOG_H

#include <string>
using std::string;

class Log {
    public:
        static void i(const string &msg);
        static void w(const string &msg);
        static void e(const string &msg);
};

#endif
