#include <iostream>
#include <vector>
#include <TreeTools.h>

using namespace std;


class Solution {
public:
    struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
        if (!root) return nullptr;
        struct TreeNode *templeft = trimBST(root->left, L, R);
        struct TreeNode *tempright = trimBST(root->right, L, R);
        if (!templeft) root->left = nullptr;
        if (!tempright) root->right = nullptr;
        if (root->val < L) return tempright;
        if (root->val > R) return templeft;
        root->left = templeft;
        root->right = tempright;
        return root;
    }

    struct TreeNode* trimBST_leetcode(TreeNode* root, int L, int R) {
        if(!root) return root;
        //if (root->val > R) return trimBST(root->left, L, R);
        //if (root->val < L) return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if(root->val < L) return root->right;
        if(root->val > R) return root->left;
        return root;
    }
};

int main()
{
    struct TreeNode *n0 = new TreeNode(0);
    struct TreeNode *n1 = new TreeNode(1);
    struct TreeNode *n2 = new TreeNode(2);
    struct TreeNode *n3 = new TreeNode(3);
    struct TreeNode *n4 = new TreeNode(4);
    n3->left = n0;
    n3->right = n4;
    n0->right = n2;
    n2->left = n1;
    Solution a;
    struct TreeNode *res = a.trimBST(n3, 1, 3);
    cout << endl;
    printTreePreorder(res);
    cout << endl;
    return 0;
}
