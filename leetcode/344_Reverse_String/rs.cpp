#include <iostream>
#include <string>
#include <algorithm>
#include <funtional>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
		int left = 0, right = s.size()-1;

		while (left < right) {
			char t = s[left];
			s[left++] = s[right];
			s[right--] = t;
			// swap(s[left++], s[right--]); also can use swap
		}

		return s;
    }
};
