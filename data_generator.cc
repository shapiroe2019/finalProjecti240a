#include "data_generator.h"

dataGenerator::dataGenerator() {
    for (auto file_len : file_lens) {
        test_strs[file_len] = rand_str(file_len);
        std::ofstream file("test_" + std::to_string(file_len) + ".txt");
        file << test_strs[file_len];
        file.close();
    }
}

void dataGenerator::generate(std::string name, searchAlgo &algo) {
    for (auto pat_len : pat_lens) {
        for (auto match : {true, false}) {
            // {algo}_{pat_len}_{int(match)}.dat
            std::ofstream out_file(name
                    + "_" + std::to_string(pat_len)
                    + "_" + std::to_string(int(match)) +
                    + ".dat");
            out_file << "n\ttime\n";


            for (auto file_len : file_lens) {
                if (file_len < pat_len) continue;
                std::cout << "Testing " << name
                    << " file_len=" << file_len
                    << " pat_len=" << pat_len << std::endl;

                std::string str;
                int acc = 0;
                // Take average of N_TESTS tests
                for (int i = 0; i < N_TESTS; i++) {
                     str = generate_str(test_strs[file_len], pat_len, match);

                     using namespace std::chrono;
                     auto start = high_resolution_clock::now();
                     algo.search(&test_strs[file_len], &str);
                     auto stop = high_resolution_clock::now();
                     acc += duration_cast<microseconds>(stop - start).count();
                }
                out_file << file_len << "\t" << acc/N_TESTS << "\n";
            }
            out_file.close();
        }
    }
}

std::string dataGenerator::rand_str(int len) {
    std::string out = "";
    for (int i = 0; i < len; i++) {
        out += std::rand() % 256;
    }
    return out;
}

std::string dataGenerator::generate_str(std::string str, int len, bool match) {
    if (!match) {
        return rand_str(len);
    }
    else {
        int i = std::rand() % (str.length()-len+1);
        return str.substr(i, len);
    }
}
