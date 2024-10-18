#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"
#include <queue>

class RequestQueue {
private:
    std::queue<Request> requests;
    int maxSize;

public:
    RequestQueue(int maxSize);
    bool enqueue(const Request& req);
    Request dequeue();
    bool isEmpty() const;
    bool isFull() const;
    int size();
};

#endif // REQUESTQUEUE_H
