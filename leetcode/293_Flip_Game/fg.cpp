#include <iostream>
#include <vector>
using namespace std;
/*
	You are playing the following Flip Game with your friend:
	Given a string that contains only these two characters: + and -,
	you and your friend take turns to flip twoconsecutive "++" into "--".
	The game ends when a person can no longer make a move and therefore
	the other person will be the winner.

	Write a function to compute all possible states of the string after
	one valid move.

	For example, given s = "++++", after one move, it may become one of
	the following states:

	[
	  "--++",
	  "+--+",
	  "++--"
	]

	If there is no valid move, return an empty list [].

*/

class Solution {
public:
	/* substr is [a, b] */
	static vector<string> generatePossibleNextMoves(string s) {
		vector<string> result;
		for (int i = 1; i < s.size(); ++i) {
			if (s.at(i) == '+' && s.at(i-1) == '+') {
				result.push_back(s.substr(0, i-1) + "--" + s.substr(i+1));
			}
		}
		return result;
	}
};

int main()
{

	string a("++++---+++++++-+++");
	cout << a << endl << endl;
	vector<string> v = Solution::generatePossibleNextMoves(a);
	for (string s : v)
		cout << s << endl;

	return 0;

}
