/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 *
 * https://leetcode.cn/problems/partition-array-into-three-parts-with-equal-sum/description/
 *
 * algorithms
 * Easy (38.48%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    68.6K
 * Total Submissions: 178.4K
 * Testcase Example:  '[0,2,1,-6,6,-7,9,1,2,0,1]'
 *
 * 给你一个整数数组 arr，只有可以将其划分为三个和相等的 非空 部分时才返回 true，否则返回 false。
 *
 * 形式上，如果可以找出索引 i + 1 < j 且满足 (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] +
 * arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length
 * - 1]) 就可以将数组三等分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [0,2,1,-6,6,-7,9,1,2,0,1]
 * 输出：true
 * 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [0,2,1,-6,6,7,9,-1,2,0,1]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = [3,3,6,5,-2,2,5,1,-9,4]
 * 输出：true
 * 解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3
 * -10^4
 *
 *
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        if (total % 3 != 0) return false;
        long long target = total / 3;
        int i = 0, j = arr.size() - 1;
        int l = 0, r = 0;
        do {
            l += arr[i++];
        } while (i < arr.size() && l != target);
        do {
            r += arr[j--];
        } while (j >= 0 && r != target);
        return i < j + 1; // i ,j会多走一步, 由此正确的位置应该为[0...i-1],[j+1...len-1],
                          // 所以i-1与j+1的距离大于1也就是i-1+1 < j+1
    }
};
// @lc code=end
int main() {
    Solution sole;
    vector<int> vct = {1, -1, 1, -1};
    sole.canThreePartsEqualSum(vct);
    return 0;
}
