/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (42.46%)
 * Likes:    374
 * Dislikes: 0
 * Total Accepted:    91.8K
 * Total Submissions: 215.7K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 > l2) return false;
        //记录两个数组
        vector<int> cnt1(26), cnt2(26);
        //统计前l1长度的字符
        for(int i = 0; i < l1; i++){
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if(cnt1 == cnt2) return true;
        //窗口大小固定为s1长度
        for(int i = l1; i < l2; i++){
            //每次向后移动一个，cnt2去掉s2[i - l1]
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - l1] - 'a']--;
            if(cnt1 ==cnt2) return true;
        }
        return false;

    }
};
// @lc code=end

