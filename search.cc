#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <unordered_map>

#include "rabin_karp.h"
#include "boyer_moore.h"
#include "naive.h"
#include "kmp.h"
#include "data_generator.h"

/**returns index of argv[2] if it exists
 * if it doesn't exist it returns -1**/
int go(int argc, char* argv[]){

    if(argc < 3){
        return -2;
    }

    //std::string inFileName {argv[1]}; //get file name in string form

    std::ifstream inFile (argv[1]); //OPEN

    if (!inFile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        exit(1); // terminate with error
    }

    std::string content( (std::istreambuf_iterator<char>(inFile) ),
                         (std::istreambuf_iterator<char>()    ) ); //entire text file will be one giant string

    std::string word {argv[2]};

    int x;
    if (argc > 3) {
        if (std::strcmp(argv[3], "rabinkarp") == 0) {
            rabinKarp search;
            x = search.search(&content, &word);
        }
        else if (std::strcmp(argv[3], "boyermoore") == 0) {
            boyerMoore search;
            x = search.search(&content, &word);
        }
        else if (std::strcmp(argv[3], "naive") == 0) {
            naive search;
            x = search.search(&content, &word);
        }
        else if (std::strcmp(argv[3], "kmp") == 0) {
            KMP search;
            x = search.search(&content, &word);
        }
        else {
            std::cerr << "Unknown algorithm \"" << argv[3] << "\"\n";
            std::exit(1);
        }
    }
    else {
        naive search;
        x = search.search(&content, &word);
    }

    inFile.close(); //CLOSE

    return x;
}



int main(int argc, char* argv[]){
    if (argc > 1 && (std::strcmp(argv[1], "-g") == 0)) {
        dataGenerator gen;

        rabinKarp rabin_karp;
        gen.generate("rabinkarp", rabin_karp);

        boyerMoore boyer_moore;
        gen.generate("boyermoore", boyer_moore);

        naive naive;
        gen.generate("naive", naive);

        KMP kmp;
        gen.generate("kmp", kmp);

        return 0;
    }

    int retVal = go(argc, argv);

    if(retVal == -1){
      std::cout<< "The word is not in the text file " << argv[1] << std::endl;
    }
    else if(retVal == -2){
      std::cerr << "usage: ./search FILE 'word' [naive/kmp/rabinkarp/boyermoore]" << std::endl;
    }
    else{
      std::cout << "The word can be found at character location " << retVal << std::endl;
    }

    return 0;
}
