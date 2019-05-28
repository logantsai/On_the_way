#include <iostream>
#include <vector>
#include <queue>
#include "TreeTools.h"

using namespace std;

/**
  * Preorder : root left right
  * Postorder : left right root
  * Inorder : left root right
  */

void printTreePreorder(struct TreeNode *root)
{
	if (!root) return;
	std::cout << root->val << " ";
	printTreePreorder(root->left);
	printTreePreorder(root->right);
}

void printTreeLevelorder(struct TreeNode *root)
{
    queue<struct TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        struct TreeNode *tmp = q.front();
        cout << tmp->val << " ";
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
    }
}

#if 0
struct TreeNode *intAryToTree(vector<int> ary, int size_ary, struct TreeNode *node, int index)
{
    if (ary[index] == -1) return NULL;

    struct TreeNode *tmpNode = new TreeNode(ary[index]);
    if (index != 0) {   // root
        if (node->left) {
            node->right = tmpNode;
        } else {
            node->left = tmpNode;
        }
    }
    if (index*2+1 < size_ary)
        intAryToTree(ary, tmpNode, index*2+1);

    if (index*2+2 < size_ary)
        intAryToTree(ary, tmpNode, index*2+2);

    return tmpNode;
}
#endif

/*
    The value of node must be larger than or equal to 0.
*/
struct TreeNode *intAryToTree(
    vector<int> ary,
    int sizeOfAry,
    struct TreeNode *root,
    int index)
{
    if (ary[index] < 0) return nullptr;
    if (index < sizeOfAry) {
        struct TreeNode *tmpNode = new TreeNode(ary[index]);
        root = tmpNode;
        root->left = intAryToTree(
                        ary, sizeOfAry, root->left, index*2+1);
        root->right = intAryToTree(
                        ary, sizeOfAry, root->right, index*2+2);
    }

    return root;
}

#if 0
int main()
{
    vector<int> ary{1, 3, 2, 5};
    struct TreeNode *root;
    root = intAryToTree(ary, ary.size(), root, 0);
    printTreePreorder(root);
    return 0;
}
#endif
