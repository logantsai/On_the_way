#ifndef TREETOOLS_H
#define TREETOOLS_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void printTreePreorder(TreeNode *root);

#endif
