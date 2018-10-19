#include <iostream>
#include <vector>
#include <TreeTools.h>
using namespace std;

class Solution {
public:
    static struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

int main()
{
    vector<int> ary1{1, 3, 2, 5};
    vector<int> ary2{2, 1, 3, -1, 4, -1, 7};
    struct TreeNode *t1, *t2, *t3;
    t1 = intAryToTree(ary1, ary1.size(), t1, 0);
    t2 = intAryToTree(ary2, ary2.size(), t2, 0);
    t3 = Solution::mergeTrees(t1, t2);

    printTreePreorder(t3);
    cout << endl;
    printTreeLevelorder(t3);
    cout << endl;
    return 0;
}
