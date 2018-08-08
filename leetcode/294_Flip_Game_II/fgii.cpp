#include <iostream>
#include <vector>
using namespace std;
/*
	You are playing the following Flip Game with your friend: Given a string
	that contains only these two characters: + and -, you and your friend take
	turns to flip twoconsecutive "++" into "--". The game ends when a person
	can no longer make a move and therefore the other person will be the winner.

	Write a function to determine if the starting player can guarantee a win.

	For example, given s = "++++", return true. The starting player can guarantee
	a win by flipping the middle "++" to become "+--+".

	Follow up:
	Derive your algorithm's runtime complexity.
*/
/* 題目只要我們找出先手是不是能直接勝 */
class Solution {
public:
	static bool canWin(string s) {
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '+' && s[i - 1] == '+' &&
				!canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) { // 剩下的字串
				cout << s.substr(0, i - 1) + "--" + s.substr(i + 1) << endl;
				return true;
			}
		}
		return false;
    }
};

int main()
{
	string s("++++");
	cout << Solution::canWin(s) << endl;
	return 0;
}
