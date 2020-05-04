#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#define N_TESTS 10

#include "search_algo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <chrono>

const int file_lens[] = {10, 100, 1000, 10000, 100000};
const int pat_lens[] = {5, 50, 500, 5000, 25000};

class dataGenerator {
 public:
    dataGenerator();
    void generate(std::string name, searchAlgo &algo);

 private:
    static std::string rand_str(int len);
    std::string generate_str(std::string str, int len, bool match);

    std::unordered_map<int, std::string> test_strs;
};

#endif
