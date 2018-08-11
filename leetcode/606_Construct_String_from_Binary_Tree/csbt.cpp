#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
You need to construct a string consists of parenthesis and integers
from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()".
And you need to omit all the empty parenthesis pairs that don't affect
the one-to-one mapping relationship between the string and the original binary tree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static string tree2str(TreeNode* t) {
		return to_string(t->val) + helper_mark(t->left) + helper_mark(t->right);
    }

	static string helper_mark(TreeNode* t) {
		if (t == nullptr) return "";
		string s_l = helper_mark(t->left);
		string s_r = helper_mark(t->right);
		if (s_l == "" && s_r != "") return "(" + to_string(t->val) + "()" + s_r + ")";
		return "(" + to_string(t->val) + s_l + s_r + ")";
	}

	static string tree2str_edyy(TreeNode* t) {
        if (!t) return "";
        string res = to_string(t->val);
        if (!t->left && !t->right) return res;
        res += "(" + tree2str(t->left) + ")";	// 不管如何一定要有左
        if (t->right) res += "(" + tree2str(t->right) + ")";	// 不一定需要右
        return res;
    }
};

int main()
{
	struct TreeNode *r = new TreeNode(1);
	r->left = new TreeNode(2);
	r->right = new TreeNode(3);
	r->left->right = new TreeNode(4);

	cout << Solution::tree2str(r) << endl;
	return 0;
}
