#include <iostream>
#include <vector>
#include <unordered_map>
#include <TreeTools.h>

/* key : 使用 map 容器結構來表示 tree 結構
 * Input : [113, 215, 221]
 * 百位表示第幾層，十位表示第幾位置
 */
class Solution {
public:

    void helper(int num, unordered_map<int, int>& m, int cur_sum, int& res) {
        if (!m.count(num)) return;

        int left_child = (num/10+1)*10 + (num%10*2-1);
        int right_child = (num/10+1)*10 + (num%10*2);

        cur_sum += m[num];
        if (!m.count(left_child) && !m.count(right_child)) {
            res += cur_sum;
            return;
        }

        helper(left_child, m, res);
        helper(right_childe, m, res);

    }
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> map_tree;
        for (auto n : nums) {
            map_tree[n/10] = n % 10;
        }
        int res = 0;
        helper(11, map_tree, 0, res);
    }
}
