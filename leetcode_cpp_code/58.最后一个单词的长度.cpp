/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (34.62%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    196.6K
 * Total Submissions: 566.4K
 * Testcase Example:  '"Hello World"'
 *
 * 给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
 * 
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Hello World"
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " "
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅有英文字母和空格 ' ' 组成
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isLetter(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    int lengthOfLastWord(string s)
    {
        int length = 0;
        bool start = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (start)
            { //如果单词开始了寻找空格
                if (c == ' ')
                {
                    return length;
                }
                else
                {
                    length++;
                }
            }
            else
            { //未开始单词，寻找字母
                if (c != ' ')
                {
                    length++;
                    start = true;
                }
            }
        }
        if (!start)
        {
            //没找到单词
            return 0;
        }
        return length;
    }
};
// @lc code=end
