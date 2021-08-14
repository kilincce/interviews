#include <ctime>

#include "ILogger.h"

string ILogger::getLogTimeString() {
    time_t timeNow = time(nullptr);
    char timeNowStr[32] = {0};
    strftime(timeNowStr, sizeof(timeNowStr), "%F %T", localtime(&timeNow));
    return timeNowStr;
}