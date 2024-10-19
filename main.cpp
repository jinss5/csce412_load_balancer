#include "LoadBalancer.h"
#include "Request.h"
#include "RandomGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numServers, timeLimit;
    std::cout << "Enter number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter simulation time limit (in clock cycles): ";
    std::cin >> timeLimit;

    LoadBalancer lb(numServers, numServers * 100);

    for (int i = 0; i < numServers*10; ++i) { // add first n*10 requests as te server is initialized and then add random requests.
        lb.addRequest(Request(RandomGenerator::generateRandomIP(), RandomGenerator::generateRandomIP(), rand() % 100, RandomGenerator::generateRandomJobType()));
    }

    lb.run(timeLimit);

    return 0;
}
