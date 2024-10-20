/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 */

#include "LoadBalancer.h"
#include "RandomGenerator.h"
#include "IPRangeBlocker.h"
#include <iostream>
#include <cstdlib>  // for rand()
#include <set>
#include <fstream>

extern std::ofstream logFile;
IPRangeBlocker ipBlocker;

/**
 * @brief Constructs a new LoadBalancer object.
 * 
 * @param numServers Number of servers to initialize.
 * @param queueSize Maximum size of the request queue.
 */
LoadBalancer::LoadBalancer(int numServers, int queueSize) : requestQueue(queueSize), currentTime(0) {
    ipBlocker.blockIPPrefix("192.168.0."); 
    ipBlocker.blockIPPrefix("10.0.0.");
    ipBlocker.blockIPPrefix("125.23.23.");   
    ipBlocker.blockIPPrefix("162.87.187.");
    ipBlocker.blockIPPrefix("221.35.244.");
    ipBlocker.blockIPPrefix("201.31.207.");
    ipBlocker.blockIPPrefix("185.199.37.");
    ipBlocker.blockIPPrefix("150.192.5.");
    ipBlocker.blockIPPrefix("59.187.209.");
    ipBlocker.blockIPPrefix("84.168.78.");
    ipBlocker.blockIPPrefix("144.71.32.");
    ipBlocker.blockIPPrefix("190.205.38.");
    ipBlocker.blockIPPrefix("103.7.21.");
  

    for (int i = 0; i < numServers; ++i) {
        webServers.push_back(WebServer(i + 1));
    }
}

/**
 * @brief Adds a request to the load balancer's request queue.
 * 
 * @param req The request to be added.
 */
void LoadBalancer::addRequest(const Request& req) {
    std::string clientIP = req.getIpIn();
    std::string serverIP = req.getIpOut();
    if (ipBlocker.isBlocked(clientIP)){
        logFile << "Blocked request from: " << clientIP << std::endl;
    } else if (ipBlocker.isBlocked(serverIP)) {
        logFile << "Blocked request from: " << clientIP << std::endl;
    } else {
        if (!requestQueue.isFull()) {
            requestQueue.enqueue(req);
            logFile << "Added request to queue: " << req.getIpIn() << " -> " << req.getIpOut() << std::endl;
        } else {
            logFile << "Queue is full! Dropping request." << std::endl;
        }
    }    
}

/**
 * @brief Assigns requests to servers.
 * 
 * Processes requests from the queue and assigns them to available servers.
 */
void LoadBalancer::assignRequests() {
    std::set<int> taskTime; 
    for (auto& server : webServers) {
        if (!requestQueue.isEmpty()) {
            if (server.getIsAvailable()) {              // if server can process
                Request req = requestQueue.dequeue();
                server.processRequest(req);
                taskTime.insert(req.getTime());         // add task time
            } else {                                    // if server is already running
                server.processCycle(); 
            }
        }
    }

    logFile << "Task time between " << *taskTime.begin() << " and " << *taskTime.rbegin() << "\n" <<std::endl;
}

/**
 * @brief Adds more servers to the load balancer.
 * 
 * @param count The number of servers to add.
 */
void LoadBalancer::addServer(int count) {
    int n = webServers.size();

    for (int i = 0; i < count; ++i) {
        webServers.push_back(WebServer(n + 1 + i));
    }
}

/**
 * @brief Removes servers from the load balancer.
 * 
 * @param count The number of servers to remove.
 */
void LoadBalancer::removeServer(int count) {
    for (int i = 0; i < count; ++i) {
       webServers.pop_back();
    }
}

/**
 * @brief Balances the load by adding or removing servers.
 *  maintain at least 3 servers
 *  add server if queue.size > server * 100
 *  remove server if queue.size == server
 */
void LoadBalancer::balanceLoad() {

    int numServers = webServers.size();
    if (numServers >= 4) {
        if (requestQueue.size() > numServers * 100) {
            addServer(requestQueue.size() - numServers * 100);
        }

        if (requestQueue.size() * 10 <= numServers) {
            removeServer(1);
        }
    }
    logFile << "Number of servers: " << webServers.size() << std::endl;
}

/**
 * @brief Runs the load balancer for assigned clock cycle
 */
void LoadBalancer::run(int timeLimit) {
    logFile << "Starting Queue Size: " << requestQueue.size() << std::endl;

    while (currentTime < timeLimit) {
        logFile << "Clock cycle: " << currentTime << std::endl;
        int numRequestsToAdd = rand() % 2;

        for (int i = 0; i < numRequestsToAdd; ++i) { // random requests
            addRequest(Request(RandomGenerator::generateRandomIP(), RandomGenerator::generateRandomIP(), rand() % 10 + 1, RandomGenerator::generateRandomJobType()));
        }

        balanceLoad();
        assignRequests();
        currentTime++;
    }

    logFile << "Ending Queue Size: " << requestQueue.size() << std::endl;
}