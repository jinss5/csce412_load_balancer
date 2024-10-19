#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <string>

class RandomGenerator {
public:
    static std::string generateRandomIP();   // Declaration for random IP generator
    static char generateRandomJobType();     // Declaration for random job type generator
};

#endif // RANDOMGENERATOR_H
