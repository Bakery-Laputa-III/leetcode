/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode.cn/problems/happy-number/description/
 *
 * algorithms
 * Easy (65.97%)
 * Likes:    1739
 * Dislikes: 0
 * Total Accepted:    678.4K
 * Total Submissions: 1M
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 *
 *
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */
#include <iostream>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        do {
            if (nums.count(n) == 0) {
                nums.insert(n);
            } else {
                return false;
            }
            n = next(n);
        } while (n != 1);
        return true;
    }

    // 111 -> 3
    // 321 -> 14
    // 0 -> 0
    // 1 -> 1
    int next(int n) {
        int ans = 0;
        while (n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution me;
    std::cout << "Test of Next" << std::endl;
    std::cout << "111->" << me.next(111) << std::endl;
    std::cout << "321->" << me.next(321) << std::endl;
    std::cout << "0->" << me.next(0) << std::endl;
    std::cout << "1->" << me.next(1) << std::endl;
    return 0;
}
