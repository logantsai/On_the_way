#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*
	A sentence S is given, composed of words separated by spaces. Each word
	consists of lowercase and uppercase letters only.

	We would like to convert the sentence to "Goat Latin" (a made-up language
	similar to Pig Latin.)

	The rules of Goat Latin are as follows:

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end
	of the word. For example, the word 'apple' becomes 'applema'.

    If a word begins with a consonant (i.e. not a vowel), remove the first
	letter and append it to the end, then add "ma". For example, the word "goat"
	becomes "oatgma".

    Add one letter 'a' to the end of each word per its word index in the sentence,
	starting with 1. For example, the first word gets "a" added to the end, the
	second word gets "aa" added to the end and so on.

	Return the final sentence representing the conversion from S to Goat Latin.
*/

class Solution {
public:

	static string toGoatLatin_github(string S) {
		stringstream iss(S), oss;
    	string vowels("aeiouAEIOU"), word, a;
		int word_index = 0;
		while (iss >> word) {
			a.push_back('a');
			if (word[0].find_first_of(vowels) != string::npos) {
				oss << ' ' << word << "ma" << a;
			} else {
				oss << ' ' << word.substr(1) << word[0] << "ma" << a;
			}
		}
		return oss.str().substr(1);
	}
	static string toGoatLatin(string S) {
		int i, word_s, n = S.size();
		word_s = 0;
		string tmp_s("");
		int word_index = 0;
		for (i = 0; i < n; ++i) {
			if (S[i] == ' ') {
				++word_index;
				cout << word_s << " " << i << endl;
				cout << S.substr(word_s, i - word_s) << endl;
				tmp_s = tmp_s + " "+ GoatLatinJudge(S.substr(word_s, i - word_s), word_index);
				word_s = i+1;
			}
		}
		tmp_s.erase(tmp_s.begin());
		return tmp_s;
    }

	static string GoatLatinJudge(string s, int word_index) {
		switch(s[0]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				s.append("ma");
				break;
			default:
				s = s + s[0] + "ma";
				s.erase(s.begin());
		};
		string s2(word_index, 'a');
		s = s + s2;
		return s;
	}

};


int main()
{
	string s1("The quick brown fox jumped over the lazy dog");
	cout << Solution::toGoatLatin(s1) << endl;

	return 0;
}
