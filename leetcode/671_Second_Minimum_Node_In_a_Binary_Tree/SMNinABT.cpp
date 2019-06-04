#include <iostream>
#include <vector>
#include <stack>
#include <climits>

#include <TreeTools.h>
using namespace std;
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left && !root->right) return -1;
        if (root->left->val == root->right->val) return -1;

        int second_min = INT_MAX;    //tree only non-negative
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {

            struct TreeNode *cur = stk.top(); stk.pop();
            if (!cur->left && !cur->right) continue;
            if (cur->left->val == cur->right->val) {
                stk.push(cur->right);
                stk.push(cur->left);
            }
            if (cur->left->val > cur->right->val) {
                second_min = cur->left->val < second_min ? cur->left->val : second_min;
                stk.push(cur->right);
            }
            if (cur->left->val < cur->right->val) {
                second_min = cur->right->val < second_min ? cur->right->val : second_min;
                stk.push(cur->left);
            }
        }

        return second_min;
    }

};
