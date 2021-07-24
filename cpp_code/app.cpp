#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <systemtopologyapi.h>
using namespace std;
#define MAX 9999
class MinStack
{
public:
    /** initialize your data structure here. */
    int array[MAX];
    int top_p = 0;
    int min_arr[MAX];
    int p_min = 0;
    MinStack()
    {
        array[0] = 9999999;
        min_arr[0] = 0;
    }

    void push(int val)
    {
        this->array[++this->top_p] = val;
        if (this->array[this->min_arr[this->p_min]] > val)
        {
            this->min_arr[++this->p_min] = this->top_p;
        }
    }

    void pop()
    {

        if (this->min_arr[this->p_min])
        {
            this->p_min--;
        }
        this->top_p--;
    }

    int top()
    {
        return this->array[this->top_p];
    }

    int getMin()
    {
        return this->array[this->min_arr[this->p_min]];
    }
};
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (73.00%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    113.4K
 * Total Submissions: 155.6K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */
#include <vector>
#include <bits/stdc++.h>
// @lc code=start
class Solution
{
public:
    // 2021/7/23 leetcode 科目一工作级别第三题
    int maxTouristLimit(vector<int> &nums, int cnt)
    {
        // nums[] 各单位报名参加参观的人数，cnt:总的参观名额  return 最大limit数量
        // test case
        // 1. [1,1],1  return 0
        // 2. [1,1,2,2,4],9 return 3

        // 如果总人数不超过cnt，return -1
        int sum = 0;
        int length = nums.size();
        for (auto i : nums)
        {
            sum += i;
        }
        if (sum <= cnt)
            return -1;
        // 总人数超过cnt
        // sort
        sort(nums.begin(), nums.end());
        // dp[i] : limit为nums[i]时候的总可去参观人数
        // dp[i] = dp[i - 1] + (nums[i] - nums[i - 1]) * (length - i)
        vector<int> dp(length);
        dp[0] = nums[0] * length;
        int limit_start, limit_end = 0;
        for (int i = 1; i < length; i++)
        {
            dp[i] = dp[i - 1] + (nums[i] - nums[i - 1]) * (length - i);
            // 当dp[i]超过了cnt时候，limit 一定小于 nums[i]
            if (dp[i] >= cnt)
            {
                limit_end = nums[i];
                limit_start = i >= 1 ? nums[i - 1] : nums[0]; //可能dp[1]就超过了cnt
                break;
            }
        }
        // limit的选值从nump[i - 1]到 nums[i]
        for (auto i = limit_end; i >= limit_start; i--)
        {
            if (sumWithLimit(nums, i) <= cnt)
            {
                return i;
            }
        }
        return cnt / length;
    }
    int sumWithLimit(vector<int> nums, int limit)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum += i <= limit ? i : limit;
        }
        return sum;
    }
    string reverseWords(string s)
    {
        int length = s.size();
        int start = 0, end = 0;
        while (end < length)
        {
            //找到起点
            while (s[start] == ' ' && start < length)
            {
                start++;
            }
            end = start;
            //找到起点终点
            while (s[end] != ' ' && end < length)
            {
                end++;
            }
            for (int i = start; i < (end - 1 + start) / 2; i++)
            {
                swap(s[i], s[end + start - i - 1]);
            }
            start = end;
        }
        return s;
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            //旋转一位
            int memory = nums[n - 1];
            for (int j = n - 1; j >= 1; j--)
            {
                nums[j] = nums[j - 1];
            }
            nums[0] = memory;
        }
    }
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);
        int p = n - 1;
        while (left <= right)
        {
            int l = nums[left] * nums[left], r = nums[right] * nums[right];
            if (l < r)
            {
                ans[p--] = r;
                right--;
            }
            else
            {
                ans[p--] = l;
                left++;
            }
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s)
    {
        int l = s.length();
        int left = 0, right = 0, ans = 0;
        unordered_set<char> my_set;
        //while中是滑动窗口的左边界
        while (left < l && right < l)
        {
            if (my_set.find(s[right]) == my_set.end())
            {
                my_set.insert(s[right++]);
                ans = max(ans, right - left);
            }
            else
            {
                my_set.erase(s[left++]);
            }
        }
        return ans;
    }
};

int main()
{
    // string a = "hello";
    // cout << a << endl;
    // for (size_t i = 0; i < a.size(); i++)
    // {
    //     char t = a[i];
    //     cout << t << endl;
    // }
    // MinStack min = MinStack();
    // min.push(-3);
    // min.push(-2);
    // min.getMin();
    // string s = "";
    // s.append(1, 'A'); // 后面插入1个A
    // cout << s << endl;
    // cout << min.getMin() << endl;
    // cout << "------------------" << endl;
    Solution sl = Solution();
    // sl.reverseWords("hello world");
    // sl.lengthOfLongestSubstring("abababc");

    vector<int> arr = {1, 1, 2, 4, 2};
    cout << sl.maxTouristLimit(arr, 9123) << endl;

    // // sl.rotate(arr, 1);
    // cout << "------------------" << endl;
    system("pause");
    return 0;
}