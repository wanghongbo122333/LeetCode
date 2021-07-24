/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (45.47%)
 * Likes:    1003
 * Dislikes: 0
 * Total Accepted:    281.1K
 * Total Submissions: 618.3K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 0 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    //每次旋转一位 循环k次 时间复杂度O（n2）空间O(1)
    // void rotate(vector<int> &nums, int k)
    // {
    //     int n = nums.size();
    //     for (int i = 0; i < k; i++)
    //     {
    //         //旋转一位
    //         int memory = nums[n - 1];
    //         for (int j = n - 1; j >= 1; j--)
    //         {
    //             nums[j] = nums[j - 1];
    //         }
    //         nums[0] = memory;
    //     }
    // }
    //额外数组 空间O(n) 时间复杂度O(n)
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            //直接归位
            //新位置new = (i+k)%n
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};
// @lc code=end
