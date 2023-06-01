//
// Created by malaklinux on 5/31/23.
//

#ifndef MULTITHREADED_PIPELINE_ACTIVE_OBJECT_HPP
#define MULTITHREADED_PIPELINE_ACTIVE_OBJECT_HPP

#include "thread_queue.hpp"
#include <functional>
#include <thread>
#include <atomic>

using namespace std;

class ActiveObject {
private:
    function<void(void *)> func;
    ThreadQueue queue;
    atomic<bool> stop_flag;
    thread worker_thread;
    void process_tasks();

public:
    ActiveObject(function<void(void *)> func);
    ThreadQueue *get_queue();
    void stop();
};

#endif //MULTITHREADED_PIPELINE_ACTIVE_OBJECT_HPP
