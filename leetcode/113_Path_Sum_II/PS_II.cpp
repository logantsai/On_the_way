#include <iostream>
#include <stack>
#include <vector>

#include <TreeTools.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> vv;
    void helper(TreeNode* node, int CurSum, int TarSum, vector<int> &v) {
        if (!node) return;

        v.push_back(node);
        CurSum += node->val;

        if (!node->left && !node->right && (CurSum  == TarSum))
            vv.push_back(v);

        helper(node->left, CurSum, TarSum, v);
        helper(node->right, CurSum, TarSum, v);

        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return vv;
        vector<int> v;
        helper(root, 0, sum, v);
        return vv;
    }
};
