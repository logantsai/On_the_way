#include <iostream>

#include <vector>

#include <TreeTools.h>

using namespace std;


class Solution {
public:

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left <= right) {
            int mid = (left + right) / 2;
/*
int mid=left+(right-left+1)/2;
int mid=(right+left)/2 + ((right-left)& 0x1 == 1 ? 1 : 0);
//奇數時，取最中間的值；偶數時，取偏後的那個中間值
*/
            TreeNode *cur = new TreeNode(nums[mid]);
            cur->left = helper(nums, left, mid - 1);
            cur->right = helper(nums, mid+1, right);
            return cur;
        }
        return NULL;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};



