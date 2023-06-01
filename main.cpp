//
// Created by malaklinux on 5/31/23.
//
#include "st_pipeline.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: " << argv[0] << " N [seed]" << endl;
        return 1;
    }

    int N = stoi(argv[1]);
    unsigned int seed = (argc == 3) ? stoi(argv[2]) : time(nullptr);
    bool use_seed = (argc == 3);

    PipelineST pipeline;
    pipeline.execute(N, seed, use_seed);

    return 0;
}
