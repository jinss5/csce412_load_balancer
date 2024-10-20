/**
 * @file RandomGenerator.h
 * @brief Declaration of random generation methods.
 */

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <string>

/**
 * @class RandomGenerator
 * @brief A utility class to generate random IPs and job types.
 */
class RandomGenerator {
public:
    static std::string generateRandomIP();   ///< Generates a random IP address.
    static char generateRandomJobType();     ///< Generates a random job type ('P' or 'S').
};

#endif // RANDOMGENERATOR_H
