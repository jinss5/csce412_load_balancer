/**
 * @file WebServer.h
 * @brief Declaration of the WebServer class.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <iostream>

/**
 * @class WebServer
 * @brief A class that simulates a web server processing requests.
 */
class WebServer {
private:
    int remainingTime;     ///< Time remaining for the current request.
    int serverId;          ///< ID of the web server.
    bool isAvailable;      ///< Availability status of the web server.

public:
    WebServer(int id);     ///< Constructor for WebServer.
    /**
     * @brief Processes a request.
     * 
     * @param req The request to be processed.
     */
    void processRequest(const Request& req);

    /**
     * @brief Processes one clock cycle on the server.
     */
    void processCycle();

    /**
     * @brief Completes the request currently being processed.
     */
    void requestCompleted();

    /**
     * @brief Checks if the server is available for a new request.
     * 
     * @return true if the server is available, false otherwise.
     */
    bool getIsAvailable();
};

#endif // WEBSERVER_H
