/**
 * @file IPRangeBlocker.h
 * @brief Header file for the IPRangeBlocker class, which implements IP blocking functionality.
 */

#ifndef IPRANGEBLOCKER_H
#define IPRANGEBLOCKER_H

#include <string>
#include <vector>

/**
 * @class IPRangeBlocker
 * @brief A class that manages blocking of IP addresses by prefix.
 * 
 * The IPRangeBlocker class allows for blocking specific IP address prefixes, checking if 
 * incoming requests are from blocked addresses, and rejecting them if necessary.
 */
class IPRangeBlocker {
public:
    /**
     * @brief Default constructor for IPRangeBlocker.
     */
    IPRangeBlocker();
    
    /**
     * @brief Adds an IP prefix to the list of blocked addresses.
     * 
     * @param prefix The IP prefix to block (e.g., "192.168.0.").
     */
    void blockIPPrefix(const std::string& prefix);
    
    /**
     * @brief Checks if the given IP address is blocked.
     * 
     * @param ip The IP address to check.
     * @return true if the IP address is blocked, false otherwise.
     */
    bool isBlocked(const std::string& ip) const;

private:
    /**
     * @brief A list of blocked IP prefixes.
     */
    std::vector<std::string> blockedPrefixes;
};

#endif // IPRANGEBLOCKER_H
