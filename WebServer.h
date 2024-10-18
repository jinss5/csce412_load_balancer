#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <iostream>

class WebServer {
private:
    int remainingTime;
    int serverId;
    bool isAvailable;

public:
    WebServer(int id);
    void processRequest(const Request& req);
    void processCycle();
    // int getRequestCount() const;
    void requestCompleted();
    bool getIsAvailable();
};

#endif // WEBSERVER_H
