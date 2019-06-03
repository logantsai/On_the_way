#include <iostream>

#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int diameter = 0;
    int helper (TreeNode* root) {
        if (!root) return 0;
        int ltreeH = helper(root->left);
        int rtreeH = helper(root->right);
        diameter = diameter > (ltreeH + rtreeH) ? diameter : (ltreeH + rtreeH );
        return ltreeH > rtreeH ? ltreeH + 1 : rtreeH + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return diameter;
    }

};
