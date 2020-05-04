#include "rabin_karp.h"

int rabinKarp::search(std::string* fileData, std::string* word) {
    if (fileData->length() == 0 || word->length() == 0) {
        return -1;
    }

    size_t word_len = word->length();
    auto word_hash = rollingHash(*word, word_len);
    auto file_hash = rollingHash(*fileData, word_len);

    for (int i = 0; i < fileData->length(); i++) {
        // std::cout << word_hash.get_curr() << " " << file_hash.get_curr() << std::endl;
        if (word_hash.get_curr() == file_hash.get_curr()) {
            return i;
        }

        file_hash.next();
    }

    return -1;
}
