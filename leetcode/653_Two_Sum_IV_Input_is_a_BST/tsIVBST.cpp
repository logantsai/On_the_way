#include <iostream>
#include <unordered_map>

#include <TreeTools.h>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root->left && !root->right) return false;
        unordered_map<int, TreeNode*> m;
        stack<TreeNode*> stk;

        stk.push(root);

        while (!stk.empty()) {
            TreeNode *t = stk.top();
            stk.pop();

            m.insert({t->val ,t});
            if (t->left) stk.push(t->left);
            if (t->right) stk.push(t->right);
        }

        for (auto a : m) {
            cout << a.first << ":" << a.second << endl;
            if (k - a.first == a.first) continue;
            if (m.find(k - a.first) == m.end())
                continue;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> v{2,-1,3};
    struct TreeNode *t1;
    t1 = intAryToTree(v, v.size(), t1, 0);

    Solution s;
    cout << "target is: " << s.findTarget(t1, 6) << endl;

    return 0;
}



