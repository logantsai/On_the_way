#include <iostream>
#include <TreeTools.h>

#include <utility>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y) return false;

        stack<pair<int, TreeNode*>> stk;
        stk.push(make_pair(0, root));

        vector<pair<int, TreeNode*>> res;

        while (!stk.empty()) {
            pair<int, TreeNode*> cur = stk.top();
            stk.pop();
            struct TreeNode* cur_node = cur.second;
            int cur_level = cur.first;

            if (cur_node->left) {
                if (cur_node->left->val == x || cur_node->left->val == y) {
                    cout << "left" << cur_node->left->val << endl;
                    res.push_back(make_pair(cur_level + 1, cur_node));
                }
                stk.push(make_pair(cur_level + 1, cur_node->left));
            }
            if (cur_node->right) {
                if (cur_node->right->val == x || cur_node->right->val == y) {
                    cout << "right" << cur_node->right->val << endl;
                    res.push_back(make_pair(cur_level + 1, cur_node));
                }
                stk.push(make_pair(cur_level + 1, cur_node->right));
            }
        }
        for (auto a : res) {
            cout << a.first << " " << a.second << endl;
        }
        if (res.size() != 2) return false;
        else {
            if (res[0].first == res[1].first &&
                res[0].second != res[1].second) return true;
            return false;
        }
    }
};

int main()
{
    struct TreeNode *t1;
    vector<int> v1{1, 2, 3, -1, 4};
    t1 = intAryToTree(v1, v1.size(), t1, 0);
    Solution s;
    int x, y;
    x = 2;
    y = 3;
    cout << x << "&" << y << " is cousins: " << endl <<s.isCousins(t1, x, y) << endl;
    return 0;
}
