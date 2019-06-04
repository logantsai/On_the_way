#include <iostream>
#include <stack>

#include <TreeTools.h>

using namespace std;


class Solution {
public:
#if 1
    void recusion(TreeNode* node_a, TreeNode* node_b, bool &res) {
        if ((!node_a && node_b) ||
            (!node_b && node_a)) {
            res = false; return;
        }
        if (!node_a && !node_b) return;
        if (node_a->val != node_b->val) {
            res = false; return;
        }

        recusion(node_a->left, node_b->right, res);
        recusion(node_a->right, node_b->left, res);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        bool res = true;
        recusion(root->left, root->right, res);
        return res;
    }

#else
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> ltree_stk;
        stack<TreeNode*> rtree_stk;

        if (root->left) ltree_stk.push(root->left);
        if (root->right) rtree_stk.push(root->right);
        if (ltree_stk.size() != rtree_stk.size()) return false;

        while (!ltree_stk.empty() && !rtree_stk.empty()) {
            TreeNode* cur_l = ltree_stk.top(); ltree_stk.pop();
            TreeNode* cur_r = rtree_stk.top(); rtree_stk.pop();

            if (cur_l->val != cur_r->val) return false;

            if (cur_l->left) ltree_stk.push(cur_l->left);
            if (cur_r->right) rtree_stk.push(cur_r->right);
            if (ltree_stk.size() != rtree_stk.size()) return false;

            if (cur_l->right) ltree_stk.push(cur_l->right);
            if (cur_r->left) rtree_stk.push(cur_r->left);
            if (ltree_stk.size() != rtree_stk.size()) return false;

        }
        return true;

    }
#endif
};
