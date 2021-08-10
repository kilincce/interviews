#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "LogManager.h"

using namespace std;

void LogManager::addLogger(ILogger *logger) {
    loggers.push_back(logger);
}

void LogManager::log(string message) {
    for (auto logger: loggers) {
        logger->log(message);
    }
}

int LogManager::startListener(int port) {
    logReceivers.push_back(new thread(receiveLogMessages, port, this));
}

void LogManager::waitLogs() {
    for (auto receiver : logReceivers) {
        receiver->join();
    }
}

void LogManager::receiveLogMessages(int port, LogManager *_this) {

    int server_fd;
    int opt = 1;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        return;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        return;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
       
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        return;
    }
    
    if (listen(server_fd, 3) < 0) {
        return;
    }

    int new_socket;
    int addrlen = sizeof(address);
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        char buffer[1024] = {0};
        while(read( new_socket, buffer, 1024)) {
            _this->log(buffer);
        }
    }
}

