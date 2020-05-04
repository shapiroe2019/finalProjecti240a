#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void preProcess(const char* pattern, int* lps, int M) {
	//preprocessing
	int len = 0;
	lps[0] = 0; //first place is always zero
	for (int i = 1; i < M; i++) {
		//If a prefix is found in another position, increment its length.
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
		}
		//If not,
		else {
			//If the character immediately follows another instance of the prefix, 
			//shift len back to 0. This will make the KMP algorithm faster
			if (len != 0) {
				len = lps[len - 1];
				i--;
			}
			//If not, then the value at the index of the mismatched character is 0
			else lps[i] = 0;
		}
	}
}
void KMP(const char* pat, const char* txt) {
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	preProcess(pat, lps, M);
	int i = 0;
	int j = 0;
	while(i < N){
		if(pat[j] == txt[i]){
			j++;
			i++;
		}
		if(j == M){
			cout << "Found pattern at index " << i-j << endl;
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i]){
			if(j != 0) j = lps[j-1];
			else i++;
		}
	}
}