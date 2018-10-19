#include <iostream>
#include <vector>
#include <TreeTools.h>

using namespace std;

// binary search tree (BST)
// the tree must be BST
class Solution {
public:
    static struct TreeNode* searchBST(struct TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val < val) {
            return searchBST(root->right, val);
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return root;
        }
    }
};

int main()
{
    vector<int> v{4, 2, 7, 1, 3};
    struct TreeNode *root;
    root = intAryToTree(v, v.size(), root, 0);
    root = Solution::searchBST(root, 2);
    printTreeLevelorder(root);
    cout << endl;
    return 0;
}
