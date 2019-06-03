#include <iostream>


#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> tree_stk;
        stack<vector<int>> path_stk;
        vector<int> treepath{root->val};
        vector<vector<int>> res;
        vector<string> ret;
        tree_stk.push(root);
        path_stk.push(treepath);
        while (!tree_stk.empty()) {
            TreeNode *cur = tree_stk.top(); tree_stk.pop();
            vector<int> cur_path = path_stk.top(); path_stk.pop();
            if (!cur->left && !cur->right) {
                res.push_back(cur_path);
            }

            if (cur->left) {
                cur_path.push_back(cur->left->val);

                tree_stk.push(cur->left);
                path_stk.push(cur_path);

                cur_path.pop_back();
            }

            if (cur->right) {
                cur_path.push_back(cur->right->val);

                tree_stk.push(cur->right);
                path_stk.push(cur_path);

                cur_path.pop_back();
            }
        }

        for (auto each_path : res) {
            for (auto element : each_path) {
                cout << element << " ";
            }
            cout << endl;
        }
        return ret;
    }
};
