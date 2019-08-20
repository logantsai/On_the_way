#include <stack>
#include <iosteram>

#include <TreeTools.h>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!TreeNode) return 0;
        stack<TreeNode*> stk;
        stack<int> depth;
        stk.push(root);
        depth.push(1);

        int minDepthOfLeave = 1;
        TreeNode* pre_pop = root;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            int cur_depth = depth.top();
            if (minDepthOfLeave == 0) minDepthOfLeave = cur_depth;
            else minDepthOfLeave = cur_depth < minDepthOfLeave ? cur_depth : minDepthOfLeave;

            if ( (!cur->left && !cur->right) ||
                    cur->left == pre_pop || cur->right == pre_pop ) {
                stk.pop();
                depth.pop();
                pre_pop = cur;
            } else {
                if (cur->right) {
                    stk.push(cur->right); depth.push(cur_depth + 1);
                }
                if (cur->left) {
                    stk.push(cur->left); depth.push(cur_depth + 1);
                }

            }

        }
        return minDepthOfLeave;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && ! root->right) return 1;
        int minD = INT_MAX;
        if (root->left!=NULL)
            minD = min(minDepth(root->left), minD);
        if (root->right!=NULL)
            minD = min(minDepth(root->right), minD);
        return 1+minD;
    }
};
