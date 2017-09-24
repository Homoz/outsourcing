#ifndef UTILS_H
#define UTILS_H

#include <string>
using std::string;

class Utils {
    public:
        static string to_string(int value);
        static string to_string(double value);
        // 返回 wrapper + str + wrapper + ending
        static string surroundWith(string str, string wrapper,
                string ending);
};

#endif
