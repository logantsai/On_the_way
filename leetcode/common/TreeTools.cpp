#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

void printTreePreorderIterative(struct TreeNode *root)
{
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        struct TreeNode *node = stk.top();
        stk.pop();
        cout << node->val << " ";
        if (node->left) stk.push(node->left);
        if (node->right) stk.push(node->right);
    }
}
#if 0
/* This method push only right child to stack */
void printTreePreorderIterative2(struct TreeNode *root)
{
    stack<TreeNode*> stk;
    stk.push(root);
    struct TreeNode *cur = root;

    while (!stk.empty()) {
        if (cur) {
            cout << cur->val << " ";
            if (cur->right) stk.push(cur->right);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
        }
    }
}
#endif
void printTreeInorderIterative(struct TreeNode *root)
{
    stack<TreeNode*> stk;
    struct TreeNode *cur = root;
    while (cur || !stk.empty()) {
        if (cur) {
            stk.push(cur);
            cur = cur->left;
        } else {
            struct TreeNode *node = stk.top();
            stk.pop();
            cout << node->val << " ";
            cur = node->right;
        }
    }
}

void printTreePostorderIterative(struct TreeNode *root)
{
    stack<TreeNode*> stk;
    stk.push(root);
    struct TreeNode *pre_pop = root;
    while (!stk.empty()) {
        struct TreeNode *node = stk.top();
        if ((!node->right && !node->left) ||
            node->left != pre_pop || node->right != pre_pop) {
            stk.pop();
            cout << node->val << " ";
            pre_pop = node;
        } else {
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }

    }
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
