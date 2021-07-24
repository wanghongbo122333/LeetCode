/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.64%)
 * Likes:    1912
 * Dislikes: 0
 * Total Accepted:    431.3K
 * Total Submissions: 602.1K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> my_vec;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(my_vec.find(nums[i] == my_vec.end()){
                my_vec[nums[i]] = 1;
            }else my_vec[nums[i]]++;
        }
        auto iter = my_vec::iterator();

    }
};
// @lc code=end

