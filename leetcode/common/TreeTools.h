#ifndef TREETOOLS_H
#define TREETOOLS_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void printTreePreorder(struct TreeNode *root);
void printTreeLevelorder(struct TreeNode *root);
struct TreeNode *intAryToTree(std::vector<int> ary, int sizeOfAry,
    struct TreeNode *root, int index);


#endif
