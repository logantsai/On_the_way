#include <iostream>
#include <vector>

#include <TreeTools.h>
using namespace std;
class Solution {
public:
    struct TreeNode* increasingBST(struct TreeNode* root) {
        vector<struct TreeNode *> ary;
        inorder(root, ary);

        auto endary = ary.end() - 1;
        (*endary)->left = nullptr;
        (*endary)->right = nullptr;

        for (int i = ary.size() - 1; i >=1; --i) {
            ary[i-1]->right = ary[i];
            ary[i-1]->left = nullptr;
        }
        return ary[0];
    }

    void inorder(struct TreeNode *root,
        vector<struct TreeNode *> &ary) {
        if (root->left) inorder(root->left, ary);
        ary.push_back(root);
        if (root->right) inorder(root->right, ary);
    }

    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};

int main()
{
    struct TreeNode *n1 = new struct TreeNode(1);
    struct TreeNode *n2 = new struct TreeNode(2);
    struct TreeNode *n3 = new struct TreeNode(3);
    struct TreeNode *n4 = new struct TreeNode(4);
    struct TreeNode *n5 = new struct TreeNode(5);
    struct TreeNode *n6 = new struct TreeNode(6);
    struct TreeNode *n7 = new struct TreeNode(7);
    struct TreeNode *n8 = new struct TreeNode(8);
    struct TreeNode *n9 = new struct TreeNode(9);
    n5->left = n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n2->left = n1;
    n6->right = n8;
    n8->left = n7;
    n8->right = n9;

    Solution a;
    struct TreeNode *res = a.increasingBST(n5);
    for (;res; res = res->right)
        cout << res->val << endl;
    return 0;
}
