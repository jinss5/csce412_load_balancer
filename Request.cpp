#include "Request.h"

Request::Request(std::string in, std::string out, int t, char type) : ipIn(in), ipOut(out), time(t), jobType(type) {}

std::string Request::getIpIn() const {
    return ipIn;
}

std::string Request::getIpOut() const {
    return ipOut;
}

int Request::getTime() const {
    return time;
}

char Request::getJobType() const {
    return jobType;
}
