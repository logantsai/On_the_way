#include <iostream>


#include <TreeTools.h>
using namespace std;
class Solution {
public:
    //12ms
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> stk;
        TreeNode* parent = new TreeNode(-1);
        parent->right = root;

        stk.push(root);
        int sum = 0;

        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();

            if (!cur->left && !cur->right && cur == parent->left)
                sum += cur->val;

            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
            parent = cur;
        }
        return 0;
    }
    //4ms
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left && !t->left->left && !t->left->right) res += t->left->val;
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }

};
