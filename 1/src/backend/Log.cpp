#include <iostream>
#include "Log.h"

using std::cerr;
using std::endl;

void Log::i(const string &msg) {
    cerr << string("info: ") + msg << endl;
}

void Log::w(const string &msg) {
    cerr << string("warning: ") + msg << endl;

}

void Log::e(const string &msg) {
    cerr << string("error: ") + msg << endl;
}
