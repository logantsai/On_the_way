#include <iostream>
#include <string>
#include <alogrithm>
using namespace std;
/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital if it has more than one letter, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
	bool detectCapitalUse(string word) {
		int cnt = 0, n = word.size();
		for (char c : word)
            if (c <= 'Z') ++cnt;

/*
		if (cnt == n || cnt == 0) return true;
		if (cnt == 1 && word[0] <= 'Z') return true;
		return false;
*/
		return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
	}

	bool detectCapitalUse(string word) {
        int cnt = count_if(word.begin(), word.end(), [](char c){return c <= 'Z';});
        return cnt == 0 || cnt == word.size() || (cnt == 1 && word[0] <= 'Z');
    }
};
