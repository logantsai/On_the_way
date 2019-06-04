#include <iostream>
#include <stack>

#include <TreeTools.h>
using namespace std;



/*  先算出根節點到目前的總和，
 *  再依序移除路徑上的點，來找到子路徑滿足題意
 */
class Solution {
public:
    stack<TreeNode*> out;
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        helper(root, sum, 0, out, res);
        return res;
    }

    void helper(TreeNode* node, int sum, int curSum, stack<TreeNode*>& out, int& res) {
        if (!node) return;
        curSum = += node->val;
        out.push(node);
        if (curSum == sum) ++res;
        int t = curSum;
        for (int i = 0; i < out.size() - 1; ++i) {
            t -= out[i]->val;
            if (t == sum) ++res;
        }
        helper(node->left, sum, curSum, out, res);
        helper(node->right, sum, curSum, out, res);
        out.pop();
    }
};


