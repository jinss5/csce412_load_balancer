#include "RequestQueue.h"

RequestQueue::RequestQueue(int maxSize) : maxSize(maxSize) {}

bool RequestQueue::enqueue(const Request& req) {
    if (requests.size() < maxSize) {
        requests.push(req);
        return true;
    }
    return false; // Queue is full
}

Request RequestQueue::dequeue() {
    if (!requests.empty()) {
        Request req = requests.front();
        requests.pop();
        return req;
    }
    return Request("", "", 0, ' '); // Return a default request if empty
}

bool RequestQueue::isEmpty() const {
    return requests.empty();
}

bool RequestQueue::isFull() const {
    return requests.size() >= maxSize;
}

int RequestQueue::size() {
    return requests.size();
}