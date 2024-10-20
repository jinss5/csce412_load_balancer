/**
 * @file RequestQueue.cpp
 * @brief Implementation of the RequestQueue class.
 */

#include "RequestQueue.h"

/**
 * @brief Constructs a new RequestQueue object with a given maximum size.
 * 
 * @param maxSize The maximum size of the queue.
 */
RequestQueue::RequestQueue(int maxSize) : maxSize(maxSize) {}

/**
 * @brief Enqueues a request in the request queue.
 * 
 * @param req The request to enqueue.
 * @return true if the request was added, false if the queue is full.
 */
bool RequestQueue::enqueue(const Request& req) {
    if (requests.size() < maxSize) {
        requests.push(req);
        return true;
    }
    return false; // Queue is full
}

/**
 * @brief Dequeues a request from the request queue.
 * 
 * @return The request that was removed from the queue.
 */
Request RequestQueue::dequeue() {
    if (!requests.empty()) {
        Request req = requests.front();
        requests.pop();
        return req;
    }
    return Request("", "", 0, ' '); // Return a default request if empty
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @return true if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() const {
    return requests.empty();
}

/**
 * @brief Checks if the queue is full.
 * 
 * @return true if the queue is full, false otherwise.
 */
bool RequestQueue::isFull() const {
    return requests.size() >= maxSize;
}

/**
 * @brief Gets the current size of the queue.
 * 
 * @return The number of requests in the queue.
 */
int RequestQueue::size() {
    return requests.size();
}