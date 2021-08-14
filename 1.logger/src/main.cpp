#include <iostream>
#include <ctime>

#include "StdLogger.h"
#include "FileLogger.h"
#include "LogManager.h"

using namespace std;



int main() {
    cout << "Demo for a logger class" << endl;

    StdLogger stdLogger;

    std::time_t unixTimeStampNow = std::time(0);
    string logFileName = "logs/" + to_string(unixTimeStampNow) + ".log";
    FileLogger fileLogger(logFileName);

    LogManager logManager;
    logManager.addLogger(&stdLogger);
    logManager.addLogger(&fileLogger);
    logManager.startListener(7171);
    logManager.startListener(7172);

    logManager.log("First log");
    logManager.log("Second log");

    logManager.waitLogs();

    return 0;
}
