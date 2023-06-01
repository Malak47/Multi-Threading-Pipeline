// active_object.cpp
#include "active_object.hpp"
#include <stdexcept>

ActiveObject::ActiveObject(function<void(void*)> func) : func(func), stop_flag(false) {
    if (!func) {
        throw runtime_error("Null function pointer.");
    }
    worker_thread = thread([this] { process_tasks(); });
}

void ActiveObject::process_tasks() {
    while (true) {
        void* task = queue.dequeue();
        // If "stop" task is received and stop flag is set to true, break the loop.
        if (task == nullptr && stop_flag.load()) {
            break;
        }
        // Else, process the task.
        func(task);
    }
}

ThreadQueue* ActiveObject::get_queue() {
    return &queue;
}

void ActiveObject::stop() {
    if (worker_thread.joinable()) {
        stop_flag.store(true);
        // Enqueue a "stop" task, in this case nullptr.
        queue.enqueue(nullptr);
        // Join the worker thread to main.
        worker_thread.join();
    }
}

