#include "rolling_hash.h"

rollingHash::rollingHash(std::string str, int window_size)
    : str(str), k(window_size - 1), base(57) {
    curr = 0;
    for (index = 0; index <= k; index++) {
        // std::cout << 'f' << str[index] << " " << int(str[index]-'a') << " " << k-index << std::endl;
        curr += (str[index]-'a') * pow(base, k-index);
    }
}

int rollingHash::next() {
    // std::cout << "old: " << str[index-k-1] << std::endl;
    curr -= (str[index-k-1]-'a') * pow(base, k);
    curr *= base;
    curr += (str[index]-'a');
    index++;
    return curr;
}
