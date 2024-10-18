#include "WebServer.h"

WebServer::WebServer(int id) : requestsProcessed(0), serverId(id), isAvailable(true) {}

void WebServer::processRequest(const Request& req) {
    if (isAvailable) {
        std::cout << "WebServer " << serverId << " processing request from " 
                  << req.getIpIn() << " to " << req.getIpOut() << " (" << req.getJobType() << ")" 
                  << " for " << req.getTime() << " clock cycles." << std::endl;
    
        requestsProcessed++;
        isAvailable = false;

        requestCompleted();
    } else {
        std::cout << "WebServer " << serverId << " is currently busy." << std::endl;
    }
}

int WebServer::getRequestCount() const {
    return requestsProcessed;
}

void WebServer::requestCompleted() {
    std::cout << "WebServer " << serverId << " completed request." << std::endl;
    isAvailable = true; 
}
