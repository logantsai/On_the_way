#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#include <TreeTools.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }

    int maxDepth_iterative(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode* root> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res++;
            for (int i = 0, n = q.size(); i < n; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        res++;
    }
};
