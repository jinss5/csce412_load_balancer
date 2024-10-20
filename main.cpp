/**
 * @file main.cpp
 * @brief Main entry point for the LoadBalancer simulation.
 */

#include "LoadBalancer.h"
#include "Request.h"
#include "RandomGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

std::ofstream logFile;

/**
 * @brief Main function to run the load balancer simulation.
 * 
 * @return int Returns 0 if the program completes successfully.
 */
int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numServers, timeLimit;
    std::cout << "Enter number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter simulation time limit (in clock cycles): ";
    std::cin >> timeLimit;

    logFile.open("loadbalancer_log.txt");
    if (!logFile) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }

    logFile << numServers << " servers are running for " << timeLimit << " clock sycles.\n" << std::endl;

    LoadBalancer lb(numServers, numServers * 100);

    for (int i = 0; i < numServers * 100; ++i) { // add first n*10 requests as te server is initialized and then add random requests.
        lb.addRequest(Request(RandomGenerator::generateRandomIP(), RandomGenerator::generateRandomIP(), rand() % 10 + 1, RandomGenerator::generateRandomJobType()));
    }

    lb.run(timeLimit);

    logFile.close();
    return 0;
}
