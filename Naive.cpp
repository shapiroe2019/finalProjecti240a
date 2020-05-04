#include<iostream>
using namespace std;
void naiveSearch(string pattern, string text) {
	for (int i = 0; i <= text.size() - pattern.size(); i++) {
		for (int j = 0; j < pattern.size(); j++) {
			if (pattern[j] != text[i + j]) break;
			else if (j == pattern.size()-1) cout << "Pattern found at index " << i << endl;
		}
	}
}