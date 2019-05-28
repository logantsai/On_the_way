#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<double> result;
        vector<double> vec;
        if (!root) return result;

        double tmpValue = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur) {
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                vec.push_back(cur->val);
            } else {
                if (!q.empty()) q.push(NULL);
                double avg = accumulate(vec.begin() , vec.end() , 0.0) / vec.size();
                result.push_back(avg);
                vec.clear();
            }
        }
        return result;
    }
};


int main()
{

    vector<double> v;
    TreeNode* n_1 = new TreeNode(1);
    TreeNode* n_2 = new TreeNode(2);
    TreeNode* n_3 = new TreeNode(3);
    TreeNode* n_4 = new TreeNode(4);
    TreeNode* n_5 = new TreeNode(5);
    TreeNode* n_6 = new TreeNode(6);

    n_1->left = n_2;
    n_1->right = n_3;
    n_2->left = n_4;
    n_2->right = n_5;
    n_3->right = n_6;


    Solution s;
    v = s.averageOfLevels(n_1);

    for (double a : v) {
        cout << a << endl;
    }

    return 0;
}
