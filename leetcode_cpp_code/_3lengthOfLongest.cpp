/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.30%)
 * Likes:    5616
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         // 哈希集合，记录每个字符是否出现过
//         unordered_set<char> occ;
//         int n = s.size();
//         // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
//         int rk = -1, ans = 0;
//         // 枚举左指针的位置，初始值隐性地表示为 -1
//         for (int i = 0; i < n; ++i) {
//             if (i != 0) {
//                 // 左指针向右移动一格，移除一个字符
//                 occ.erase(s[i - 1]);
//             }
//             while (rk + 1 < n && !occ.count(s[rk + 1])) {
//                 // 不断地移动右指针
//                 occ.insert(s[rk + 1]);
//                 ++rk;
//             }
//             // 第 i 到 rk 个字符是一个极长的无重复字符子串
//             ans = max(ans, rk - i + 1);
//         }
//         return ans;
//     }
// };
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = s.size();
        int left = 0, right = 0;
        int ans = 0;
        unordered_set<char> my_set;
        //while中是滑动窗口的左边界
        while (right < l && left < l)
        {
            if (my_set.find(s[right]) == my_set.end())
            {
                my_set.insert(s[right++]);
                ans = max(ans, right - left);
            }
            else
            { //abcb
                my_set.erase(s[left++]);
            }
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution s = Solution();
    s.lengthOfLongestSubstring("abcbefgbc");
    return 0;
}