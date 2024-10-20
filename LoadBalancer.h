/**
 * @file LoadBalancer.h
 * @brief Declaration of the LoadBalancer class.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "RequestQueue.h"
#include "WebServer.h"
#include <vector>

/**
 * @class LoadBalancer
 * @brief A class that simulates a load balancer managing server requests.
 */
class LoadBalancer {
private:
    std::vector<WebServer> webServers;  ///< List of available web servers.
    RequestQueue requestQueue;          ///< Queue of pending requests.
    int currentTime;                    ///< Current simulation time.

public:
    LoadBalancer(int numServers, int queueSize);  // Constructor
    void addRequest(const Request& req);          // Adds request to queue
    void assignRequests();                        // Assigns requests to servers
    void addServer(int count);                    // Adds more servers
    void removeServer(int count);                 // Removes servers
    void balanceLoad();                           // Balances load between servers
    void run(int timeLimit);
};

#endif // LOADBALANCER_H
