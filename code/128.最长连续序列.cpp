/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (49.73%)
 * Likes:    2606
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,0,1,2]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        /*以set为基本操作对象(去重)*/
        unordered_set<int> u_set;
        for (const int& num : nums) {
            u_set.insert(num);
        }

        /*寻找最长streak*/
        int longest_streak = 0;
        for (const int& num : u_set) {
            if (u_set.count(num - 1) == 0) { // 唯有无前缀对象时放进入循环,
                                             // 由此接下来的寻找长串出了第一个的元素都没有进入循环,
                                             // 也就是u_set所有元素只遍历了一次  // 时间O(m*1)
                int currnet_num = num;
                int current_streak = 1;

                while (u_set.count(currnet_num + 1) != 0) { // 时间O(k*1)
                    currnet_num += 1;
                    current_streak += 1;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
// @lc code=end
