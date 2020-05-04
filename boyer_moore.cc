#include "boyer_moore.h"

int boyerMoore::search(std::string* fileData, std::string* word) {
    const int file_len = fileData->length();
    const int word_len = word->length();

    for (int i = 0; i < file_len; i++) {
        bad_char[(*fileData)[i]] = i;
    }

    int i = 0; // Index in text
    while (i <= (file_len - word_len)) {
        int j; // Index of the first mismatched char in pattern
        for (j = word_len-1; (j >= 0) && ((*word)[j] == (*fileData)[i+j]); j--);

        if (j < 0) {
            return i; // No mismatches <=> Match
        }
        else {
            // Shift along to align the mismatch with the pattern
            char c = (*fileData)[i+j];
            int x = (bad_char.count(c)) ? bad_char[c] : -1;
            i += std::max(1, j-x);
        }
    }
    return -1;
}
