/**
 * @file Request.cpp
 * @brief Implementation of the Request class.
 */

#include "Request.h"

/**
 * @brief Constructs a new Request object.
 * 
 * @param in The input IP address.
 * @param out The output IP address.
 * @param t The processing time in clock cycles.
 * @param type The type of the job ('P' for processing, 'S' for streaming).
 */
Request::Request(std::string in, std::string out, int t, char type) : ipIn(in), ipOut(out), time(t), jobType(type) {}

/**
 * @brief Gets the input IP address.
 * 
 * @return std::string The input IP address.
 */
std::string Request::getIpIn() const {
    return ipIn;
}

/**
 * @brief Gets the output IP address.
 * 
 * @return std::string The output IP address.
 */
std::string Request::getIpOut() const {
    return ipOut;
}

/**
 * @brief Gets the processing time of the request.
 * 
 * @return int The processing time in clock cycles.
 */
int Request::getTime() const {
    return time;
}

/**
 * @brief Gets the job type of the request.
 * 
 * @return char The job type ('P' for processing, 'S' for streaming).
 */
char Request::getJobType() const {
    return jobType;
}
