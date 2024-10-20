/**
 * @file RandomGenerator.cpp
 * @brief Implementation of random IP and job type generation.
 */

#include "RandomGenerator.h"
#include <cstdlib>  // for rand()
#include <sstream>  // for stringstream

/**
 * @brief Generates a random IP address.
 * 
 * @return std::string Randomly generated IP address in the form of xxx.xxx.xxx.xxx.
 */
std::string RandomGenerator::generateRandomIP() {
    return std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
}

/**
 * @brief Generates a random job type.
 * 
 * @return char 'P' for processing or 'S' for storage.
 */
char RandomGenerator::generateRandomJobType() {
    return (rand() % 2 == 0) ? 'P' : 'S';
}