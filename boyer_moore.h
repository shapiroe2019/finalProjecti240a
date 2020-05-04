#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <algorithm>
#include <unordered_map>

#include "search_algo.h"

class boyerMoore : public searchAlgo {
 public:
    int search(std::string* fileData, std::string* word);

 private:
    // Indices of last of each char in pattern
    std::unordered_map<char, int> bad_char;
};

#endif
