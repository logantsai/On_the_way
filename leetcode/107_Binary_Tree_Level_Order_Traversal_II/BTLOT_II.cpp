#include <iostream>
#include <vector>
#include <queue>

/* for reverse */
#include <algorithm>
#include <TreeTools.h>
using namespace std;




class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);

        vector<int> level;
        vector<vector<int>> res;
        if (!root) return res;
        while (!que.empty()) {
            TreeNode *cur = que.front(); que.pop();
            if (cur) {
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                level.push_back(cur->val);
            } else {
                if (!que.empty()) que.push(NULL);
                res.push_back(level);
                level.clear();
            }
        }

        reverse(res.begin(), res.end());
        return res;

    }
};


