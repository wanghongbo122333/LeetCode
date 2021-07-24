/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (63.30%)
 * Likes:    1390
 * Dislikes: 0
 * Total Accepted:    408.4K
 * Total Submissions: 645.2K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
 * 题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
 * 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
 * IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
 * 关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> my;
        my.insert(make_pair("IX", 9));   //9
        my.insert(make_pair("IV", 4));   //3
        my.insert(make_pair("XL", 40));  //40
        my.insert(make_pair("XC", 90));  //90
        my.insert(make_pair("CM", 900)); //900
        my.insert(make_pair("CD", 400)); //400
        my.insert(make_pair("X", 10));
        my.insert(make_pair("I", 1));
        my.insert(make_pair("L", 50));
        my.insert(make_pair("C", 100));
        my.insert(make_pair("M", 1000));
        my.insert(make_pair("V", 5));
        my.insert(make_pair("D", 500));
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && my.find(s.substr(i, 2)) != my.end())
            {
                res += my[s.substr(i, 2)];
                i++;
            }
            else
            {
                res += my[s.substr(i, 1)];
            }
        }
        return res;
    }
    //  int result = 0;
    //     unordered_map<string, int> store = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
    //     int sSize = int(s.size());
    //     for (int i = 0; i < sSize; i++)
    //     {
    //         if (i + 1 < sSize && store.find(s.substr(i, 2)) != store.end())
    //         {
    //             result += store[s.substr(i, 2)];
    //             //注意这里用到了大小为2的字符串
    //             i++;
    //         }
    //         else
    //         {
    //             result += store[s.substr(i, 1)];
    //         }
    //     }
    //     return result;
};
// @lc code=end
