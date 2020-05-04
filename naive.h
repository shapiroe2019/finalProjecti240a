#ifndef NAIVE_H
#define NAIVE_H

#include "search_algo.h"

class naive : public searchAlgo {
 public:
    int search(std::string* fileData, std::string* word);
};

#endif
