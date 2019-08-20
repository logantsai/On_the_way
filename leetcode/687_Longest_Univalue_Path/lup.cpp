#include <iostream>
#include <stack>
#include <TreeTools.h>

using namespace std;

class Solution {
public:
    int longValue = 0;
    /* 回傳左子樹長或是右子樹長*/
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int returnValue = 0;
        if (root->left && root->val == root->left->val) {
            left++;
        } else left = 0;
        if (root->right && root->val == root->right->val) {
            right++;
        } else right = 0;
        longValue = max(longValue, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return longValue;
    }
};
