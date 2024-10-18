#include "LoadBalancer.h"
#include "Request.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
}

char generateRandomJobType() {
    return (rand() % 2 == 0) ? 'P' : 'S';
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numServers, timeLimit;
    std::cout << "Enter number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter simulation time limit (in clock cycles): ";
    std::cin >> timeLimit;

    LoadBalancer lb(numServers, numServers * 100);

    for (int i = 0; i < numServers * 100; ++i) {
        lb.addRequest(Request(generateRandomIP(), generateRandomIP(), rand() % 10, generateRandomJobType()));
    }

    lb.run(timeLimit);

    return 0;
}
