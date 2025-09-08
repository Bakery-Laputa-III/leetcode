/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (70.46%)
 * Likes:    396
 * Dislikes: 0
 * Total Accepted:    106.1K
 * Total Submissions: 150.6K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序
 * 返回答案。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 * 
 * 
 */
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<char> minFrq(26, CHAR_MAX);
        for (const auto& word : words) {
            vector<char> frq(26, 0);
            for (auto c : word) frq[c - 'a']++;
            for (int i = 0; i< 26; i++) minFrq[i] = min(minFrq[i], frq[i]);
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minFrq[i]; j++) ans.push_back(string(1, i + 'a'));
        }
        return ans;
    } 
};
// @lc code=end

