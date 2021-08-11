#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            // 找到起点
            if (s[i] != ' ')
            {
                int start = i, end = start;
                while (s[end] != ' ' && end < length)
                {
                    end++;
                }
                reversWord(s, start, end - 1);
                i = end - 1;
            }
        }
        return s;
    }
    void reversWord(string &s, int start, int end)
    {
        for (int i = start; i < (end + start) / 2; i++)
        {
            swap(s[i], s[end + start - i]);
        }
    }
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
    int guess(int max)
    {
        cout << "guess a number between 1 and " << max << endl;
        cout << "if the number is less than what i guess ,intput 1;if it is bigger than what i guess, input 2,if bingo! input 3" << endl;
        int l = 1, r = max;
        int count = 0;
        // for (int i = 0; i < 7; i++)
        while (1)
        {
            int mid = (l + r) / 2;
            count++;
            cout << "the number is " << mid << endl;
            int tmp;
            cout << "please input:" << endl;
            cin >> tmp;
            if (tmp == 3)
            {
                cout << " Yes ! total guess: " << count << endl;
                return mid;
            }

            else if (tmp == 2)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
};
int main()
{
    Solution s;
    int res = s.guess(1024);
    cout << res << endl;
    system("pause");
    return 0;
}