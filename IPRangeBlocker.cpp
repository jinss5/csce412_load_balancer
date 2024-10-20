/**
 * @file IPRangeBlocker.cpp
 * @brief Implementation of the IPRangeBlocker class.
 */

#include "IPRangeBlocker.h"
#include <iostream>

/**
 * @brief Constructs an IPRangeBlocker object with an empty list of blocked prefixes.
 */
IPRangeBlocker::IPRangeBlocker() {}

/**
 * @brief Adds an IP prefix to the list of blocked addresses.
 * 
 * This function allows you to block an entire range of IP addresses by specifying a prefix.
 * For example, blocking "192.168.0." will block all addresses that start with "192.168.0.".
 * 
 * @param prefix The IP prefix to block.
 */
void IPRangeBlocker::blockIPPrefix(const std::string& prefix) {
    blockedPrefixes.push_back(prefix);
}

/**
 * @brief Checks if the given IP address is blocked.
 * 
 * This function compares the input IP address against the list of blocked prefixes. If the
 * IP address starts with any of the blocked prefixes, it is considered blocked.
 * 
 * @param ip The IP address to check.
 * @return true if the IP address is blocked, false otherwise.
 */
bool IPRangeBlocker::isBlocked(const std::string& ip) const {
    for (const auto& prefix : blockedPrefixes) {
        if (ip.find(prefix) == 0) {  // If the IP starts with the blocked prefix
            return true;
        }
    }
    return false;
}
