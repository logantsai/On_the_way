#include <iostream>

#include <TreeTools.h>
#include <stack>


using namespace std;
class Solution {
public:
    bool isBothNULLorBothTrue(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (a && b) return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1, stk2;
        stk1.push(p); stk2.push(q);
        while (!stk.empty()) {
            struct TreeNode *cur_1 = stk1.top(); stk1.pop();
            struct TreeNode *cur_2 = stk2.top(); stk2.pop();
            if (cur_1->val != cur_2->val) return false;

            if (cur_1->left) stk1.push(cur_1->left);
            if (cur_2->left) stk2.push(cur_2->left);
            if (stk1.size() != stk2.size()) return false;

            if (cur_1->right) stk1.push(cur_1->right);
            if (cur_2->right) stk2.push(cur_2->right);
            if (stk1.size() != stk2.size()) return false;

        }
        return true;
    }
};

