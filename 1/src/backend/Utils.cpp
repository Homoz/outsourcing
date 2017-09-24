#include <sstream>
#include "Utils.h"

string Utils::to_string(int value) {
    std::ostringstream strs;
    strs << value;
    return strs.str();
}
string Utils::to_string(double value) {
    std::ostringstream strs;
    strs << value;
    return strs.str();
}
string Utils::surroundWith(string str, string wrapper,
        string ending) {
    return wrapper + str + wrapper + ending;
}
