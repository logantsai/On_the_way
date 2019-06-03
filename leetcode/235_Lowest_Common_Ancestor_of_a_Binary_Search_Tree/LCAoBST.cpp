#include <iostream>

#include <vector>
#include <stack>

#include <TreeTrools.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> tree_stk;
        stack<vector<TreeNode*>> path_stk;
        vector<TreeNode*> tpath{root};

        tree_stk.push(root);
        path_stk.push(tpath);

        vector<TreeNode*> visit_to_p;
        vector<TreeNode*> visit_to_q;

        while (!tree_stk.empty()) {
            TreeNode *cur_visit = tree_stk.top(); tree_stk.pop();
            vector<TreeNode*> path_visit = path_stk.top(); path_stk.pop();

            if (cur_visit == p) visit_to_p = path_visit;
            if (cur_visit == q) visit_to_q = path_visit;
            if (!visit_to_p.empty() && !visit_to_q.empty()) break;

            if (cur_visit->left) {
                tree_stk.push(cur_visit->left);
                path_visit.push_back(cur_visit->left);

                path_stk.push(path_visit);

                path_visit.pop_back();
            }

            if (cur_visit->right) {
                tree_stk.push(cur_visit->right);
                path_visit.push_back(cur_visit->right);

                path_stk.push(path_visit);

                path_visit.pop_back();
            }
            int size = visit_to_p.size() < visit_to_q.size() ? visit_to_p.size() : visit_to_q.size();
            int i;
            for ( i = 0; i < size; ++i) {
                if (visit_to_p[i] != visit_to_q[i]) break;
            }
            return (visit_to_p[i-1]);

        }
    }

    /* 利用 BST 的特性，看兩個點是不是都屬於左or右子樹，是的話進左右子樹，
     * 如果各自屬於某父節點的左右，說明這個父節點就是LCA。
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }



};
