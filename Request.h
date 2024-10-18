#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
private:
    std::string ipIn;
    std::string ipOut;
    int time; // processing time in clock cycles
    char jobType; // 'P' for processing, 'S' for streaming

public:
    Request(std::string in, std::string out, int t, char type);
    std::string getIpIn() const;
    std::string getIpOut() const;
    int getTime() const;
    char getJobType() const;
};

#endif // REQUEST_H
