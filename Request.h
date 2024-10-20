/**
 * @file Request.h
 * @brief Declaration of the Request class.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class Request
 * @brief A class representing a request with an input/output IP, time, and job type.
 */
class Request {
private:
    std::string ipIn;    ///< Input IP address.
    std::string ipOut;   ///< Output IP address.
    int time;            ///< Processing time in clock cycles.
    char jobType;        ///< 'P' for processing, 'S' for streaming.

public:
    /**
     * @brief Constructs a new Request object.
     * 
     * @param in Input IP address.
     * @param out Output IP address.
     * @param t Processing time in clock cycles.
     * @param type Job type ('P' for processing, 'S' for streaming).
     */
    Request(std::string in, std::string out, int t, char type);

    /**
     * @brief Gets the input IP address.
     * 
     * @return std::string Input IP address.
     */
    std::string getIpIn() const;

    /**
     * @brief Gets the output IP address.
     * 
     * @return std::string Output IP address.
     */
    std::string getIpOut() const;

    /**
     * @brief Gets the processing time of the request.
     * 
     * @return int Processing time in clock cycles.
     */
    int getTime() const;

    /**
     * @brief Gets the job type of the request.
     * 
     * @return char Job type ('P' for processing, 'S' for streaming).
     */
    char getJobType() const;
};

#endif // REQUEST_H
