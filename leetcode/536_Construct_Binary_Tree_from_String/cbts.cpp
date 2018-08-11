#include <iostream>
#include <string>
#include <stack>
#include "TreeTools.h"
using namespace std;
/*
You need to construct a binary tree from a string consisting of parenthesis
and integers.

The whole input represents a binary tree. It contains an integer followed by
zero, one or two pairs of parenthesis. The integer represents the root's value
and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   /
  3   1 5

*/

/* key : 找到成對的括號 */

class Solution {
public:
    static TreeNode* str2tree(string s) {
		cout << s << endl;
		int n = s.size();
		if (n <= 2) {
			struct TreeNode* tmp = new TreeNode(stoi(s));
			return tmp;
		}

		int pair_cnt = 1;
		int i = 2;
		while (pair_cnt > 0) {
			if (s[i] == '(') ++pair_cnt;
			if (s[i] == ')') --pair_cnt;
			++i;
		}
		--i;
		cout << "i: " << i << endl;
		/*  處理左子樹
			考慮a()(b)
				a(c)(b)
		 */
		struct TreeNode* l = nullptr;
		if (i != 2) l = str2tree(s.substr(2, i-2));
		else cout << s[1] << s[2] << endl;

		/*	處理右子樹
			考慮(a(b))
				(a(b)(c))
		 */
		struct TreeNode* r = nullptr;
		if (s[++i] == '(') r = str2tree(s.substr(i+1, n - 1 - (i + 1)));
		struct TreeNode *tmp = new TreeNode(stoi(s.substr(0, 1)));
		tmp->left = l; tmp->right = r;
		return tmp;
	}

	static TreeNode* str2tree_stack(string s) {
        if (s.empty()) return NULL;
        stack<TreeNode*> st;
        for (int i = 0; i < s.size(); ++i) {
            int j = i;
            if (s[i] == ')') st.pop();
            else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {	// 若是數字則進來
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') ++i;
                TreeNode *cur = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!st.empty()) {
                    TreeNode *t = st.top();
                    if (!t->left) t->left = cur;
                    else t->right = cur;
                }
                st.push(cur);
            }
        }
        return st.top();
    }
};

int main()
{
	string a("4(2(-3)(1))(6(5))");
	struct TreeNode* root = Solution::str2tree(a);
	printTreePreorder(root);
	cout << endl;
	return 0;
}
