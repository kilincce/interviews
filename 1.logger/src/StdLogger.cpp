#include <iostream>
#include <ctime>

#include "StdLogger.h"

using namespace std;

void StdLogger::log(string message) {
    cout << getLogTimeString() << " " << message << endl;
}
