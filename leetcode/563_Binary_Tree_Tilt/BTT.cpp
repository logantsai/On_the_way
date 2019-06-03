#include <iostream>

#include <vector>

#include <TreeTools.h>
using namespace std;

class Solution {
public:
    int tilt_bt = 0;
    int helper(TreeNode* node) {
        if (!node) return 0;
        int l_sum, r_sum;
        l_sum = helper(node->left);
        r_sum = helper(node->right);
        int sum = l_sum + r_sum + node->val;
        int tilt_this = (l_sum - r_sum) > 0 ? (l_sum - r_sum) : -1*(l_sum - r_sum);
        tilt_bt += tilt_this;
        return sum;
    }
    int findTilt(TreeNode* root) {
        helper(root);
        return tilt_bt;
    }
};


int main()
{
    vector<int> v{1,2,3};
    TreeNode* t1;
    t1 = intAryToTree(v, v.size(), t1, 0);
    Solution s;
    int a = s.findTilt(t1);
    cout << "tilt of BT: " << a << endl;

    return 0;
}
