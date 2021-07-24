#include <vector>
#include <iostream>
#include <map>
#include <systemtopologyapi.h>
using namespace std;

class Solution
{
public:
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
};

int main()
{
   Solution s = Solution();
   vector<int> v = {1, 2, 3, 4, 5};
   vector<int> t = s.twoSum(v, 3);
   std::cout << t[0] << t[1] << endl;
   system("pause");
   return 0;
}