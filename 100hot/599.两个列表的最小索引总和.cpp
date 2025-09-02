/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 *
 * https://leetcode.cn/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (58.11%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    103.4K
 * Total Submissions: 178K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * 给定两个字符串数组 list1 和 list2，找到 索引和最小的公共字符串。
 * 
 * 公共字符串 是同时出现在 list1 和 list2 中的字符串。
 * 
 * 具有 最小索引和的公共字符串 是指，如果它在 list1[i] 和 list2[j] 中出现，那么 i + j 应该是所有其他 公共字符串
 * 中的最小值。
 * 
 * 返回所有 具有最小索引和的公共字符串。以 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 =
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
 * "Shogun"]
 * 输出: ["Shogun"]
 * 解释: 唯一的公共字符串是 “Shogun”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 =
 * ["KFC", "Shogun", "Burger King"]
 * 输出: ["Shogun"]
 * 解释: 具有最小索引和的公共字符串是 “Shogun”，它有最小的索引和 = (0 + 1) = 1。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
 * 输出：["sad","happy"]
 * 解释：有三个公共字符串：
 * "happy" 索引和 = (0 + 1) = 1.
 * "sad" 索引和 = (1 + 0) = 1.
 * "good" 索引和 = (2 + 2) = 4.
 * 最小索引和的字符串是 "sad" 和 "happy"。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= list1.length, list2.length <= 1000
 * 1 <= list1[i].length, list2[i].length <= 30 
 * list1[i] 和 list2[i] 由空格 ' ' 和英文字母组成。
 * list1 的所有字符串都是 唯一 的。
 * list2 中的所有字符串都是 唯一 的。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
         unordered_map<string, int> map;
         for (int i = 0; i < list2.size(); i++) {
            map[list2[i]] = i;
         }
         vector<string> min_x;
         int min_v = 2000;
         for (int i = 0; i < list1.size(); i++) {
            if (map.count(list1[i])) {
                if (i + map[list1[i]] == min_v) {
                    min_x.push_back(list1[i]);
                } else if (i + map[list1[i]] < min_v) {
                    min_x.clear();
                    min_x.push_back(list1[i]);
                    min_v = i + map[list1[i]];
                }
            }
         }
         return min_x;
    }
};
// @lc code=end

