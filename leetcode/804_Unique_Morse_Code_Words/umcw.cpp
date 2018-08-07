#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....",
						"..",".---","-.-",".-..","--","-.","---",".--.","--.-",
						".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
	static int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> result;
		unordered_set<string> s;

		for (auto word : words) {
			string tmp = "";
			for (auto chars : word) {
				tmp.append(morse_code[chars - 'a']);
			}
			s.insert(tmp);
			result.push_back(tmp);
		}

		for (auto str : result)
			cout << str << " ";
		cout << endl;

		return s.size();
	}
};


int main()
{
	for (auto s : morse_code)
		cout << s << " " << endl;
	vector<string> words = {"gin", "zen", "gig", "msg"};
	int size = Solution::uniqueMorseRepresentations(words);
	cout << "There are "<< size <<" different transformations" << endl;
	return 0;
}
