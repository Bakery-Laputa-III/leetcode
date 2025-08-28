/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 *
 * https://leetcode.cn/problems/ugly-number/description/
 *
 * algorithms
 * Easy (50.29%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    223.1K
 * Total Submissions: 443.6K
 * Testcase Example:  '6'
 *
 * 丑数 就是只包含质因数 2、3 和 5 的 正 整数。
 *
 * 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 6
 * 输出：true
 * 解释：6 = 2 × 3
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：true
 * 解释：1 没有质因数。
 *
 * 示例 3：
 *
 *
 * 输入：n = 14
 * 输出：false
 * 解释：14 不是丑数，因为它包含了另外一个质因数 7 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
  public:
    bool isUgly(int n) {
        if (n == 0) return false;
        bool flag = true;
        while (n != 1 && flag == true) {
            flag = false;
            if (n % 2 == 0) {
                n /= 2;
                flag = true;
            }
            if (n % 3 == 0) {
                n /= 3;
                flag = true;
            }
            if (n % 5 == 0) {
                n /= 5;
                flag = true;
            }
        }
        if (n == 1)
            return true;
        else
            return false;
    }
};
// @lc code=end
