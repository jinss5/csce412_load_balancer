#include "WebServer.h"

WebServer::WebServer(int id) : remainingTime(0), serverId(id), isAvailable(true) {}

void WebServer::processRequest(const Request& req) {
    if (isAvailable) {
        std::cout << "WebServer " << serverId << " processing request from " 
                  << req.getIpIn() << " to " << req.getIpOut() << " (" << req.getJobType() << ")" 
                  << " for " << req.getTime() << " clock cycles." << std::endl;
    
        remainingTime = req.getTime();
        isAvailable = false;
    }
}

void WebServer::processCycle() {
    if (!isAvailable && remainingTime > 0) {
        remainingTime--;
        if (remainingTime == 0) {
            requestCompleted();
        }
    }
}

void WebServer::requestCompleted() {
    std::cout << "WebServer " << serverId << " completed request." << std::endl;
    isAvailable = true; 
}

bool WebServer::getIsAvailable() {
    return isAvailable;
}
