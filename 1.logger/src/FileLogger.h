#pragma once

#include <fstream>

#include "ILogger.h"

class FileLogger : public ILogger {

    string fileName;
    ofstream logFile;

public:
    FileLogger(string _fileName) : fileName(_fileName) {}
    void log(string message);
};