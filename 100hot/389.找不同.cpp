/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode.cn/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (63.58%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    250.4K
 * Total Submissions: 394K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 *
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 *
 * 请找出在 t 中被添加的字母。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "", t = "y"
 * 输出："y"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (auto c : s) {
            ans ^= c;
        }
        for (auto c : t) {
            ans ^= c;
        }
        return ans;
    }
};
// @lc code=end
