//
// Created by malaklinux on 5/31/23.
//

#include "thread_queue.hpp"

void ThreadQueue::enqueue(void* element) {
    std::unique_lock<std::mutex> lock(mtx);
    data.push(element);
    cond.notify_one();
}

void* ThreadQueue::dequeue() {
    std::unique_lock<std::mutex> lock(mtx);

    // Wait until the queue is not empty
    cond.wait(lock, [this](){ return !data.empty(); });

    if (data.empty()) {
        throw std::runtime_error("Queue is empty.");
    }

    void* result = data.front();
    data.pop();

    return result;
}
