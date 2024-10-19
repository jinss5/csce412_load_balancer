#include "RandomGenerator.h"
#include <cstdlib>  // for rand()
#include <sstream>  // for stringstream

std::string RandomGenerator::generateRandomIP() {
    return std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
}

char RandomGenerator::generateRandomJobType() {
    return (rand() % 2 == 0) ? 'P' : 'S';
}