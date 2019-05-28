#include <iostream>
#include <vector>
#include <queue>

#include <TreeTools.h>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;

        root->left = root->right;
        root->right = tmp;
        return root;
    }


    TreeNode* invertTree_iterative(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            struct TreeNode* t = q.front();
            q.pop();
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);

            struct TreeNode* t2 = t->left;
            t->left = t->right;
            t->right = t2;
        }

        return root;
    }
};


int main()
{

    struct TreeNode *t1;
    vector<int> v1{1, 2, 3, 4, 5, 6, 7};
    t1 = intAryToTree(v1, v1.size(), t1, 0);

    printTreeLevelorder(t1);
    cout << endl;

    Solution s;
    s.invertTree_iterative(t1);
    printTreeLevelorder(t1);
    return 0;
}
