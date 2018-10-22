#include <iostream>
#include <stack>
#include <vector>

#include <TreeTools.h>
using namespace std;

class Solution {
public:
    static bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
        if (!root1 && !root2) return true;
        if ((!root1 && root2) || (root1 && !root2)) return false;
        vector<int> res1 = preorder(root1);
        for (auto v1 : res1)
            cout << v1;
        cout << endl;

        vector<int> res2 = preorder(root2);
        for (auto v2 :res2)
            cout << v2;
        cout << endl;
        return res1 == res2;
    }

    static vector<int> preorder(struct TreeNode *root) {
        stack<struct TreeNode *> stk1;
        stk1.push(root);
        vector<int> res;
        while (!stk1.empty()) {
            struct TreeNode *temp1 = stk1.top();
            stk1.pop();

            if (temp1->right) {
                stk1.push(temp1->right);
            }
            if (temp1->left) {
                stk1.push(temp1->left);
            }
            if (!temp1->left  && !temp1->right) {
                res.push_back(temp1->val);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v1{3,5,1,6,2,9,8,-1,-1,7,4};
    vector<int> v2{3,5,1,10,2,9,8,6,-1,7,4};
    struct TreeNode *root1, *root2;
    root1 = intAryToTree(v1, v1.size(), root1, 0);
    root2 = intAryToTree(v2, v2.size(), root2, 0);
    bool res = Solution::leafSimilar(root1, root2);
    cout << "is" << res << endl;
    return 0;
}
