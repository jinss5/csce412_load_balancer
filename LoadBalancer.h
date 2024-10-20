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
 * 
 * The LoadBalancer class is responsible for distributing incoming requests to available web servers.
 * It maintains a queue of requests and a list of servers, ensuring that requests are processed efficiently.
 */
class LoadBalancer {
private:
    std::vector<WebServer> webServers;  ///< List of available web servers.
    RequestQueue requestQueue;          ///< Queue of pending requests.
    int currentTime;                    ///< Current simulation time.

public:
    /**
     * @brief Constructs a new LoadBalancer object.
     * 
     * Initializes the load balancer with a specified number of servers and a queue size for requests.
     * 
     * @param numServers Number of web servers to initialize.
     * @param queueSize Maximum size of the request queue.
     */
    LoadBalancer(int numServers, int queueSize);

    /**
     * @brief Adds a request to the load balancer's request queue.
     * 
     * Enqueues a new request to be processed by the load balancer.
     * 
     * @param req The request to be added to the queue.
     */
    void addRequest(const Request& req);

    /**
     * @brief Assigns requests to available web servers.
     * 
     * Distributes requests from the queue to the available web servers.
     * If a server is busy, it will continue processing its current request.
     */
    void assignRequests();

    /**
     * @brief Adds more web servers to the load balancer.
     * 
     * Increases the number of web servers available to handle requests.
     * 
     * @param count The number of servers to add.
     */
    void addServer(int count);

    /**
     * @brief Removes web servers from the load balancer.
     * 
     * Decreases the number of web servers, removing the specified number from the pool.
     * 
     * @param count The number of servers to remove.
     */
    void removeServer(int count);

    /**
     * @brief Balances the load between servers.
     * 
     * Dynamically adjusts the number of web servers based on the load in the request queue.
     * It adds or removes servers depending on the current request volume.
     */
    void balanceLoad();

    /**
     * @brief Runs the load balancer for a specified time limit.
     * 
     * Simulates the load balancing process for a given number of clock cycles.
     * 
     * @param timeLimit The number of clock cycles for which the load balancer will run.
     */
    void run(int timeLimit);
};

#endif // LOADBALANCER_H
