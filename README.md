# Text Search Algorithm Comparison
The aim of this program is to find a string of characters within a “.txt” file. In simple terms, it is a text based search program. However, the ultimate goal of this project was to compare the efficiency of several different text-search algorithms, the following paragraph will go more in depth about the algorithms and their implementations. To run the program, the user must provide at least 2 command line arguments. The first argument being the “.txt” file the user would like to search, the second being the word the user would like to search for, the third command line argument that the user may add is the algorithm they would like to implement. Additionally, if the user would like to generate data on the search algorithm, they need to add a “-g” command line argument immediately following “./search”. If there is no algorithm given then the program will default to the naive search. Each search algorithm is implemented as a subclass of the searchAlgo class that contains a virtual search function. If the search algorithm can’t find the character it will return “-1”; however, if the search algorithm finds the word, it will return the index of the first character in the word. 
 
The algorithms to be implemented in this project are a naive search, KMP, Boyer-Moore, and Rabin-Karp. The naive algorithm uses a brute-force pattern check on the entire text file. This complexity scales jointly and linearly with respect to the text and pattern lengths. The Knuth-Morris-Pratt (KMP) algorithm is able to skip comparisons of partially-matching character sequences by preprocessing the pattern into an integer array storing the length of the longest prefix in order to determine the skip unnecessary comparisons while searching. If a prefix, or sequence from the first character of the pattern, is repeated, the value of the array at the character gets incremented or is otherwise zero, thus allowing it to store the length of the longest prefix. For a pattern of length m, preprocessing takes O(m) time, as it traverses the pattern only once. As it searches the text for the pattern, if part of the pattern aligns with the string and 1.) the next character is a mismatch, the algorithm skips the length of the matched portion, or 2.) subsequent characters match and the pattern is found. The searching portion takes time proportional to O(n), the length of the string, as it would with the naive algorithm. So the total time complexity is O(m+n). Being able to skip known parts of the text that match the pattern saves the time of having to compare every single character in the pattern to the text like in the Naive algorithm. Boyer-Moore is a common benchmark for string searches. It preprocesses the pattern string by determining the last index of each character present in it. While scanning a text file, character discrepancies are searched for starting at the end of the string. When one is found, the string can be shifted such that the discrepancy 1) aligns with a character in the string or 2) is completely passed. The Rabin-Karp algorithm effectively performs naive comparisons, but does so between hashes rather than characters. The algorithm usually makes use of a rolling hash whose value is partially generatable from the value at a previous index in the string. The search window can therefore be progressed by means of a lower complexity operation than recomparison.
