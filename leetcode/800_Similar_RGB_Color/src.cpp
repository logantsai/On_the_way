#include <iostream>
#include <string>

using namespace std;

/*
In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"

Explanation:
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.

Note:

    color is a string of length 7.
    color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
    Any answer which has the same (highest) similarity as the best answer will be accepted.
    All inputs and outputs should use lowercase letters, and the output is 7 characters.
*/

/*
	找字串形式為#AABBCC 且最靠近 input 的 string

	00..11..22..33.........FF
	EX：找 09 最靠近哪個數就看 00 和 11 就好
	PS：00 11 差17(10進位)
*/


class Solution {
public:
    static string similarRGB(string color) {
		return "#" + findSimilar(color.substr(1, 2)) + findSimilar(color.substr(3, 2)) + findSimilar(color.substr(5, 2));
	}

	static string findSimilar(string word) {
		string dict = "0123456789abcdef";
		int num = stoi(word, nullptr, 16);
		int idx = num / 17 + (num % 17 > 8 ? 1 : 0);
		return string(2, dict[idx]);
	}
};

int main()
{
	string a("#09f166");
	cout << Solution::similarRGB(a) << endl;
	return 0;
}
