#include "LoadBalancer.h"
#include "RandomGenerator.h"
#include <iostream>
#include <cstdlib>  // for rand()

LoadBalancer::LoadBalancer(int numServers, int queueSize) : requestQueue(queueSize), currentTime(0) {
    for (int i = 0; i < numServers; ++i) {
        webServers.push_back(WebServer(i + 1));
    }
}

void LoadBalancer::addRequest(const Request& req) {
    if (!requestQueue.isFull()) {
        requestQueue.enqueue(req);
        std::cout << "Added request to queue: " << req.getIpIn() << " -> " << req.getIpOut() << std::endl;
    } else {
        std::cout << "Queue is full! Dropping request." << std::endl;
    }
}

void LoadBalancer::assignRequests() {
    for (auto& server : webServers) {
        if (!requestQueue.isEmpty()) {
            if (server.getIsAvailable()) {              // if server can process
                Request req = requestQueue.dequeue();
                server.processRequest(req);
            } else {                                    // if server is already running
                server.processCycle(); 
            }
        }
    }
}

void LoadBalancer::balanceLoad() { // adding/removing web servers based on load
    // maintain at least 3 servers
    // add server if queue.size > server*100
    // remove server if queue.size == server
    // if (numServers >= 4) {
    
    // }
}

void LoadBalancer::run(int timeLimit) {
    std::cout << "Starting Queue Size: " << requestQueue.size() << std::endl;

    while (currentTime < timeLimit) {
        std::cout << "Clock cycle: " << currentTime << std::endl;
        int numRequestsToAdd = rand() % 4;

        for (int i = 0; i < numRequestsToAdd; ++i) {
            addRequest(Request(RandomGenerator::generateRandomIP(), RandomGenerator::generateRandomIP(), rand() % 100, RandomGenerator::generateRandomJobType()));
        }

        assignRequests();
        balanceLoad();
        currentTime++;
    }

    std::cout << "Ending Queue Size: " << requestQueue.size() << std::endl;
}