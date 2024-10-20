/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class.
 */

#include "WebServer.h"
#include <fstream>

extern std::ofstream logFile;


/**
 * @brief Constructs a new WebServer object with the given server ID.
 * 
 * @param id The ID of the web server.
 */
WebServer::WebServer(int id) : remainingTime(0), serverId(id), isAvailable(true) {}

/**
 * @brief Processes a request on the web server.
 * 
 * @param req The request to process.
 */
void WebServer::processRequest(const Request& req) {
    if (isAvailable) {
        logFile << "WebServer " << serverId << " processing request from " 
                  << req.getIpIn() << " to " << req.getIpOut() << " (" << req.getJobType() << ")" 
                  << " for " << req.getTime() << " clock cycles." << std::endl;
    
        remainingTime = req.getTime();
        isAvailable = false;
    }
}

/**
 * @brief Simulates the processing of one clock cycle on the server.
 */
void WebServer::processCycle() {
    if (!isAvailable && remainingTime > 0) {
        remainingTime--;
        if (remainingTime == 0) {
            requestCompleted();
        }
    }
}

/**
 * @brief Marks a request as completed.
 */
void WebServer::requestCompleted() {
    logFile << "WebServer " << serverId << " completed request." << std::endl;
    isAvailable = true; 
}

/**
 * @brief Checks if the web server is available to process a new request.
 * 
 * @return true if the server is available, false otherwise.
 */
bool WebServer::getIsAvailable() {
    return isAvailable;
}
