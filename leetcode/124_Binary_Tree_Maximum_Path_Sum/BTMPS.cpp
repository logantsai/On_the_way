#include <iostream>
#include <vector>


#include <TreeTools.h>


using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = max(helper(node->left, res), 0);     //如果子樹之合為負，寧可不取
        int right = max(helper(node->right, res), 0);
        res = max(res, left + right + node->val);       //更新最大值
        return max(left, right) + node->val;
    }
};
