#include <iostream>
#include <stack>

#include <TreeTools.h>
using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum ) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    bool hasPathSum(TreeNode* root, int target_sum) {
        if (!root) return false;

        stack<TreeNode*> stk;
        stack<int> sum_stk;
        stk.push(root);
        sum_stk.push(root->val);

        bool res = false;

        while (!stk.empty()) {
            TreeNode *cur = stk.top(); stk.pop();
            int sum = sum_stk.top(); stk.pop();

            if (!cur->left && !cur->right) {
                if (sum == target_sum) res = true;
            }

            if (cur->right) {
                stk.push(cur->right);
                sum_stk.push(sum + cur->right->val);
            }
            if (cur->left) {
                stk.push(cur->left);
                sum_stk.push(sum + cur->left->val);
            }
        }

        return res;
    }
};
