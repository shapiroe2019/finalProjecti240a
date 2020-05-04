#ifndef KMP_H
#define KMP_H

#include "search_algo.h"

class KMP : public searchAlgo {
 public:
    int search(std::string* fileData, std::string* word);

 private:
    void preProcess(const char* pattern, int* lps, int M);
};

#endif
