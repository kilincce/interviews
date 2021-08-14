#pragma once

#include <string>

using namespace std;

class ILogger {
public:
    virtual void log(string message) = 0;
    virtual string getLogTimeString();
};