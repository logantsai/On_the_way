#include <iostream>
#include <vector>
#include <stack>

#include <TreeTools.h>
using namespace std;


class Solution {
public:
    vector<int> v;
#if 0
    void sumRootToLeaf_recu(TreeNode* root, int val) {
        if (!root->left && !root->right) {
            v.push_back(val*2 + root->val);
//            cout << val*2 + root->val  << endl;
        }
        if (root->left) sumRootToLeaf_recu(root->left, val*2 + root->val);
        if (root->right) sumRootToLeaf_recu(root->right, val*2 + root->val);
    }

    int sumRootToLeaf(TreeNode* root) {
        sumRootToLeaf_recu(root, 0);
        int sum = 0;
        for (auto a : v) {
//            cout << a << endl;
            sum+=a;
        }
        return sum;
    }
#else
    int sumRootToLeaf(TreeNode* root) {
        stack<struct TreeNode*> inds_stk;
        stack<int> val_stk;
        inds_stk.push(root);
        val_stk.push(root->val);

        vector<int> result;
        while (!inds_stk.empty()) {
            struct TreeNode* tmp = inds_stk.top();
            int tmpVal = val_stk.top();
            inds_stk.pop();
            val_stk.pop();

            if (!tmp->left && !tmp->right) {
                result.push_back(tmpVal);
            } else {    // 若有子
                if (tmp->left) {
                    val_stk.push(tmpVal << 1 | tmp->left->val);
                    inds_stk.push(tmp->left);
                }
                if (tmp->right) {
                    val_stk.push(tmpVal << 1 | tmp->right->val);
                    inds_stk.push(tmp->right);
                }
            }
        }
        int sum = 0;
        for (auto a : result) {
            cout << a << " ";
            sum+=a;
        }
        cout << endl;
        return sum;
    }
#endif
};


int main()
{
    vector<int> v{1,0,1,0,1,0};
    struct TreeNode* t;
    t = intAryToTree(v, v.size(), t, 0);
    Solution s;
    cout << "Sum of root to leaf:"<< s.sumRootToLeaf(t) << endl;
    return 0;
}
