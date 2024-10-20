/**
 * @file RequestQueue.h
 * @brief Declaration of the RequestQueue class.
 */

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"
#include <queue>

/**
 * @class RequestQueue
 * @brief A class that manages a queue of requests.
 */
class RequestQueue {
private:
    std::queue<Request> requests;  ///< Queue of requests.
    int maxSize;                   ///< Maximum size of the queue.

public:
    RequestQueue(int maxSize);     ///< Constructor for RequestQueue.

    /**
     * @brief Enqueues a request in the queue.
     * 
     * @param req The request to enqueue.
     * @return true if the request was added, false otherwise.
     */
    bool enqueue(const Request& req);

    /**
     * @brief Dequeues a request from the queue.
     * 
     * @return The dequeued request.
     */
    Request dequeue();
    
    /**
     * @brief Checks if the queue is empty.
     * 
     * @return true if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Checks if the queue is full.
     * 
     * @return true if the queue is full, false otherwise.
     */
    bool isFull() const;

    /**
     * @brief Gets the current size of the queue.
     * 
     * @return The number of requests in the queue.
     */
    int size();
};

#endif // REQUESTQUEUE_H
