#ifndef ROLLING_HASH_H
#define ROLLING_HASH_H

#include <iostream>
#include <string>
#include <cmath>

class rollingHash {
 public:
    rollingHash(std::string str, int window_size);

    int next();
    int get_curr() { return curr; }
 private:
    std::string str;
    int index;

    long curr;

    const int k;
    const int base;
};

#endif
