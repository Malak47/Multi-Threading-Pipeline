//
// Created by malaklinux on 5/31/23.
//

#ifndef MULTITHREADED_PIPELINE_ST_PIPELINE_HPP
#define MULTITHREADED_PIPELINE_ST_PIPELINE_HPP

#include "active_object.hpp"

using namespace std;

class PipelineST {
private:
    ActiveObject *ao1;
    ActiveObject *ao2;
    ActiveObject *ao3;
public:
    PipelineST();
    void execute(int N, unsigned int seed, bool use_seed);
    ~PipelineST();
};


#endif //MULTITHREADED_PIPELINE_ST_PIPELINE_HPP
