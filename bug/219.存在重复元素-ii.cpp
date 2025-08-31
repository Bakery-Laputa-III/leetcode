/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode.cn/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (50.06%)
 * Likes:    815
 * Dislikes: 0
 * Total Accepted:    412.9K
 * Total Submissions: 824.4K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] ==
 * nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */
#define RUN 1
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int len = k + 1; // 滑动窗口长度
        for (int i = 0; i < nums.size(); i++) {
            if (set.size() == len) {
                set.erase(set.begin());
            }
            if (set.find(nums[i]) == set.end()) {
                set.insert(nums[i]);
            }
            else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
#if RUN
int main() {
    Solution sole;
    vector<int> nums = { 1, 2, 3, 1, 2, 3 };
    int k = 2;
    cout << "Test!" << endl;
    cout << sole.containsNearbyDuplicate(nums, k);
    return 0;
}
#endif
