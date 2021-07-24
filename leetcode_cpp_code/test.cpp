#include <string>
using namespace std;
class Solution
{
public:
    bool isLetter(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    int lengthOfLastWord(string s)
    {
        int l = 0;
        bool start = false;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (start)
            { //如果单词开始了寻找空格
                if (c == ' ')
                {
                    return l;
                }
                else
                {
                    l++;
                }
            }
            else
            { //未开始单词，寻找字母
                if (c != ' ')
                {
                    l++;
                    start = true;
                }
            }
        }
        if (!start)
        {
            //没找到单词
            return 0;
        }
        return l;
    }
};
int main()
{
    string s = "sd  ";
    Solution so = Solution();
    so.lengthOfLastWord(s);
}