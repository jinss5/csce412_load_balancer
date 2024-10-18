#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <iostream>

class WebServer {
private:
    int requestsProcessed;
    int serverId;
    bool isAvailable;

public:
    WebServer(int id);
    void processRequest(const Request& req);
    int getRequestCount() const;
    void requestCompleted();
};

#endif // WEBSERVER_H
