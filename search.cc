#include <iostream>
#include <string>
#include <fstream>

#include "dummySearch.cc"

/**returns index of argv[2] if it exists
 * if it doesn't exist it returns -1**/
int go(int argc, char* argv[]){

    if(argc != 3){
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

    std::string word {argv[1]};

    //INSERT SEARCH ALGO CODE HERE
    dummySearch search;

    int x = search.search(&content, &word);

    inFile.close(); //CLOSE

    return x;
}



int main(int argc, char* argv[]){

    int retVal = go(argc, argv);

    if(retVal == -1){
      std::cout<< "The word is not in the text file" << << std::endl;
    }
    else if(retVal == -2){
      std::cerr << "usage: ./search FILE 'word'" << std::endl;
    }
    else{
      std::cout << "The word can be found at character location " << retVal << std::endl;
    }
    
    return 0;
}
