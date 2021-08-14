#include <chrono>
#include <ctime>

#include "FileLogger.h"

void FileLogger::log(string message) {
    logFile.open(fileName, ios::app);
    logFile << getLogTimeString() << " " << message << endl;
    logFile.close();
}
