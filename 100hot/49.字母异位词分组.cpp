/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*建立string : vector<string>表, 将异位词放置同一vector中*/
        unordered_map<string, vector<string>> map;
        for (const auto& str : strs) {
            string tmp = str;             // 空间O(n*k)
            sort(tmp.begin(), tmp.end()); // 时间O(n*klogk)
            map[tmp].push_back(str);      // 时间O(n*1)
        }

        /*将map.second全部移动到一个新的vector中*/
        vector<vector<string>> ans;
        for (auto& pair : map) {
            ans.push_back(std::move(pair.second)); // 移动语义避免拷贝
        }

        return ans;
    }
};
// @lc code=end
