//
// Created by psilves1 on 5/2/20.
//

#ifndef SEARCHALGO_H
#define SEARCHALGO_H

#include <string>

class searchAlgo{
public:

    /** returns index of first char in the word **/
    virtual int search(std::string* fileData, std::string* word) = 0;



};


#endif //TMPDIR_GP_SEARCHALGO_H
