/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode.cn/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.41%)
 * Likes:    635
 * Dislikes: 0
 * Total Accepted:    228.8K
 * Total Submissions: 412.9K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的 回文串 的长度。
 *
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 *
 * 示例 2:
 *
 *
 * 输入:s = "a"
 * 输出:1
 * 解释：可以构造的最长回文串是"a"，它的长度是 1。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length <= 2000
 * s 只由小写 和/或 大写英文字母组成
 *
 *
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
  public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (auto c : s) {
            map[c]++;
        }
        int ans = 0;
        bool flag = false; // 存在奇times则可加入中间
        for (auto [_, frq] : map) {
            if (frq % 2 == 0) {
                ans += frq;
            } else {
                ans += frq - 1;
                flag = true;
            }
        }
        if (flag) ans += 1;
        return ans;
    }
};
// @lc code=end
