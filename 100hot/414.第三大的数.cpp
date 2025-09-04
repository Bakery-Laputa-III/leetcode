/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode.cn/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (41.09%)
 * Likes:    494
 * Dislikes: 0
 * Total Accepted:    189K
 * Total Submissions: 459.8K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 *
 * 示例 2：
 *
 *
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -2^31
 *
 *
 *
 *
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 *
 */
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=
class Solution {
  public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> maxHeap(set.begin(), set.end());
        make_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        if (maxHeap.size() <= 2) return maxHeap[0];
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
        return maxHeap.front();
    }
};
// @lc code=end
