#include "naive.h"
#include<iostream>

using namespace std;

int naive::search(std::string* fileData, std::string* word) {
    for (int i = 0; i <= fileData->size() - word->size(); i++) {
        for (int j = 0; j < word->size(); j++) {
            if ((*word)[j] != (*fileData)[i + j]) break;
            else if (j == word->size()-1) return i;
        }
    }

    return -1;
}
