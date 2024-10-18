#include "LoadBalancer.h"
#include <iostream>

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
            Request req = requestQueue.dequeue();
            server.processRequest(req);
        }
    }
}

// void LoadBalancer::balanceLoad() {
//     // Placeholder for load balancing logic, e.g., adding/removing web servers based on load
//     // This is for extracredit 2
// }

void LoadBalancer::run(int timeLimit) {
    std::cout << "Starting Queue Size: " << requestQueue.size() << std::endl;

    while (currentTime < timeLimit) {
        std::cout << "Clock cycle: " << currentTime << std::endl;
        assignRequests();
        //balanceLoad();
        currentTime++;
    }

    std::cout << "Ending Queue Size: " << requestQueue.size() << std::endl;
}
