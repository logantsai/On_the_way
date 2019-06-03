#include <iostream>
#include <stack>
#include <vector>

#include <TreeTools.h>
using namespace std;


class Solution {
public:
#if 1
    int sum = 0;
    int convertBST_helper(TreeNode* node, int val) {
        if (node) {
        int sum, sum2;
            sum = convertBST_helper(node->right, val);
            if (sum > node->val) {
                node->val += sum;
                sum = node->val;
            } else sum = sum > node->val ? sum : node->val;

            sum2 = convertBST_helper(node->left, sum);

            return sum2;
        }
        return val;
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        convertBST_helper(root, 0);
        return root;
    }
#else
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;

        TreeNode* cur = root;
        int sum = 0;
        while (cur != NULL || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->right;
            } else {
                TreeNode* cur2 = stk.top(); stk.pop();
                sum += cur2->val;
                cur2->val = sum;
                cur = cur2->left;
            }
        }
        return root;
    }
#endif
};

int main()
{
    struct TreeNode *t1;
    vector<int> v1{5,2,13,1};
    t1 = intAryToTree(v1, v1.size(), t1, 0);
    printTreeLevelorder(t1); cout << endl;
    Solution s;
    struct TreeNode *t2 = s.convertBST(t1);
    printTreeLevelorder(t2);
    return 0;
}
