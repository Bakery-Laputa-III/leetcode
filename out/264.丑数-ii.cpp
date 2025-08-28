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
using namespace std;

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

    int nthUglyNumber(int n) {  // 超时
        int i;
        for (i = 1; n > 0; i++) {
            if (isUgly(i)) {
                n--;
            }
        }
        return i - 1;
    }
};

// @lc code=end

