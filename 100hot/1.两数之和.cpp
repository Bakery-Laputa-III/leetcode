/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*建立{num:index}map*/
        unordered_map<int, int> u_map;
        for (int i = 0; i < nums.size(); i++) {
            u_map[nums[i]] = i;
        }

        /*从头遍历可能成为ans的pair*/
        for (int i = 0; i < nums.size() - 1;
             i++) { //用[0, nums.size()-1)=[0,size()-2]的原因就是最后一个元素的配对必然要到前面找,
                    //所以如果最后一个元素被选择, 那么必然已经被前面元素所配对,
                    //由此没有必要再循环到最后一个.
            auto it = u_map.find(target - nums[i]);
            if (it != u_map.end() && it->second != i) {
                return {i, it->second};
            }
        }

        return {}; // ciallo~(测试修改)
    }
};
// @lc code=end
