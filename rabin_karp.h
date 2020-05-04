#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <iostream>

#include "search_algo.h"
#include "rolling_hash.h"

class rabinKarp : public searchAlgo {
 public:
    int search(std::string* fileData, std::string* word);
};

#endif
