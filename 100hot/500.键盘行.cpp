/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode.cn/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (74.16%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    85.9K
 * Total Submissions: 115.8K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 请注意，字符串 不区分大小写，相同字母的大小写形式都被视为在同一行。
 * 
 * 美式键盘 中：
 * 
 * 
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 * 
 * 输出：["Alaska","Dad"]
 * 
 * 解释：
 * 
 * 由于不区分大小写，"a" 和 "A" 都在美式键盘的第二行。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["omk"]
 * 
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["adsdf","sfd"]
 * 
 * 输出：["adsdf","sfd"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] 由英文字母（小写和大写字母）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        for (auto word : words) {
            bool r1 = true, r2 = true, r3 = true;
            for (auto c : word) {
                char x = tolower(c);
                if (r1 && row1.find(x) == row1.end()) { r1 = false; }
                if (r2 && row2.find(x) == row2.end()) { r2 = false; }
                if (r3 && row3.find(x) == row3.end()) { r3 = false; }
            }
            if (r1 || r2 || r3) ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end

