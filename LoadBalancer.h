#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "RequestQueue.h"
#include "WebServer.h"
#include <vector>

class LoadBalancer {
private:
    RequestQueue requestQueue;
    std::vector<WebServer> webServers;
    int currentTime;

public:
    LoadBalancer(int numServers, int queueSize);
    void addRequest(const Request& req);
    void assignRequests();
    void balanceLoad();
    void run(int timeLimit);
};

#endif // LOADBALANCER_H
