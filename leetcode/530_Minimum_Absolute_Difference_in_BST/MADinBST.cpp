#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <math>

#include <TreeTools.h>
using namespace std;


class Solution {
public:

    void inorder(TreeNode* root, int &pre, int &mini) {
        int (!root) return;
        inorder(root->left, pre, mini);
        if (pre != -1) mini = min(mini, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }

    void getMinimumDifference(struct TreeNode *root) {
        stack<TreeNode*> stk;
        struct TreeNode *cur = root;
        int pre = -1;
        int mini = INT_MAX;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                struct TreeNode *node = stk.top();
                stk.pop();
                if (pre != -1) mini = min(mini, node->val - pre);
                pre = node->val;
                cur = node->right;
            }
        }
    }
};

