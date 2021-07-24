/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1);
            row.push_back(1);
            for (int j = 1; j < i + 1; j++)
            {
                //
            }
            res.push_back(row);
        }
    }
};
// @lc code=end
