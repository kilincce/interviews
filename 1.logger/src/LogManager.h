#include <vector>
#include <thread>

#include "ILogger.h"

using namespace std;

class LogManager {

private:
    vector<ILogger *> loggers;
    int listeningPort;
    vector<thread *> logReceivers;

    static void receiveLogMessages(int port, LogManager *_this);

public:
    //LogManager(int _listeningPort, vector<ILogger *> _loggers) : listeningPort(_listeningPort), loggers(_loggers); 
    void addLogger(ILogger * logger);
    int startListener(int port);
    void log(string message);
    void waitLogs();
};