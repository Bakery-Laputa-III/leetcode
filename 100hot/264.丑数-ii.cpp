/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode.cn/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (58.13%)
 * Likes:    1273
 * Dislikes: 0
 * Total Accepted:    206K
 * Total Submissions: 354.3K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 *
 * 丑数 就是质因子只包含 2、3 和 5 的正整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1690
 *
 *
 */
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<long> factors = {2, 3, 5};
        unordered_set<long> uglys;
        priority_queue<long, vector<long>, greater<long>> min_heap;

        uglys.insert(1);
        min_heap.push(1);

        long ugly = 0;
        for (int i = 0; i < n; i++) {
            long crt = min_heap.top();
            min_heap.pop();
            ugly = crt;
            for (const auto& factor : factors) {
                long next = crt * factor;
                if (uglys.count(next) == 0) {
                    uglys.insert(next);
                    min_heap.push(next);
                }
            }
        }

        return (int)ugly;
    }
};
// @lc code=end