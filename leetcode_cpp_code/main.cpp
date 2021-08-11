#include <vector>
#include <iostream>
#include <map>
#include <systemtopologyapi.h>
using namespace std;

class Solution
{
public:
   void rotate(vector<int> &nums, int k)
   {
      int length = nums.size();
      vector<int> m_vec(length);
      for (size_t i = 0; i < length; i++)
      {
         //{0,1,2,3,4,5} size = 6, k = 1:0->1,5->0,newIndex = (index + k) % size - 1
         // 1,0,2,3,4
         m_vec[(k + i) % length] = nums[i];
      }
      nums = m_vec;
   };
   vector<int> twoSum(vector<int> &nums, int target)
   {
      map<int, int> m;
      for (size_t i = 0; i < nums.size(); i++)
      {
         auto t = m.find(target - nums[i]);
         if (t == m.end())
         {
            m[nums[i]] = i;
         }
         else
         {
            return {m[target - nums[i]], i};
         }
      }
      return {0, 0};
   };
   void moveZeroes(vector<int> &nums)
   {
      // 这种写法处理不了【0，0，1】
      // int length = nums.size();
      // int p_zero = length - 1;
      // int i = 0;
      // while (i < length && p_zero >= i)
      // {
      //    if (nums[i] == 0)
      //    {
      //       // 找到最后一个0的位置
      //       while (nums[p_zero] == 0 && p_zero >= i)
      //       {
      //          p_zero--;
      //       }
      //       // 移动
      //       if (p_zero > i)
      //       {
      //          for (int j = i; j < p_zero; j++)
      //          {
      //             nums[j] = nums[j + 1];
      //          }
      //          nums[p_zero] = 0;
      //       }
      //    }
      //    i++;
      // }
      /*滑动窗口，保证窗口内一定是符合条件的：所有的0都在最右边*/
      int length = nums.size();
      int left = 0, right = 0;
      while (right < length)
      {
         if (nums[right])
         {
            // 右边不为0 与左边调换
            swap(nums[right], nums[left++]);
         }
         right++;
      }
   }
};

int main()
{
   Solution s = Solution();
   vector<int> v = {0, 0, 1};
   s.moveZeroes(v);
   s.rotate(v, 1);
   vector<int> t = s.twoSum(v, 3);
   std::cout << t[0] << t[1] << endl;
   system("pause");
   return 0;
}