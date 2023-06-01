// pipeline_st.cpp
#include "st_pipeline.hpp"
#include "prime_util.hpp"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

PipelineST::PipelineST() {
    ao1 = new ActiveObject([this](void *task) {
        size_t number = *(static_cast<int *>(task));
        cout << number << endl;
        bool is_prime_number = primeUtil::is_prime(number);
        cout << (is_prime_number ? "true" : "false") << endl;
        number += 11;
        ao2->get_queue()->enqueue(new size_t(number)); // Pass to ao2
    });

    ao2 = new ActiveObject([this](void *task) {
        size_t number = *(static_cast<size_t *>(task));
        cout << number << endl;
        bool is_prime_number = primeUtil::is_prime(number);
        cout << (is_prime_number ? "true" : "false") << endl;
        number -= 13;
        ao3->get_queue()->enqueue(new size_t(number)); // Pass to ao3
    });

    ao3 = new ActiveObject([](void *task) {
        size_t number = *(static_cast<size_t *>(task));
        cout << number << endl;
        bool is_prime_number = primeUtil::is_prime(number);
        cout << (is_prime_number ? "true" : "false") << endl;
        number += 2;
        cout << number << endl;
        delete static_cast<size_t *>(task); // Clean up
    });
}

void PipelineST::execute(int N, unsigned int seed, bool use_seed) {
    mt19937 generator(seed);
    uniform_int_distribution<int> distribution(100000, 999999);

    for (int i = 0; i < N; i++) {
        int number;
        if (use_seed) {
            number = seed;
            number = distribution(generator);

        } else {
            number = distribution(generator);
        }
        ao1->get_queue()->enqueue(new int(number));
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}


PipelineST::~PipelineST() {
    ao1->stop();
    ao2->stop();
    ao3->stop();
    delete ao1;
    delete ao2;
    delete ao3;
}
