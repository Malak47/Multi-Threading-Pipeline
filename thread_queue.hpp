//
// Created by malaklinux on 5/31/23.
//

#ifndef MULTITHREADED_PIPELINE_THREAD_QUEUE_HPP
#define MULTITHREADED_PIPELINE_THREAD_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdexcept>

using namespace std;

class ThreadQueue {
private:
    queue<void *> data;
    mutex mtx;
    condition_variable cond;
public:
    void enqueue(void *element);
    void *dequeue();
};

#endif //MULTITHREADED_PIPELINE_THREAD_QUEUE_HPP
