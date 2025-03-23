#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int num(string s);
int cmax(int a,int b);

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        int result = 0;
        cin >> n;
        vector<int> nums(n);

        for(int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            if(num(s) != 111)
            {
                nums.push_back(num(s));
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                result = max(result,cmax(nums[i],nums[j]));
            }
        }
        cout << result << endl;
    }
    return 0;
}

int num(string s)
{
    if (s.empty() || s.size() > 4) return 111;

    if (s[0] == '-') // 处理负数
    {
        if (s.size() == 1 || s[1] == '0') return 111; // "-0" 或 "-" 不合法
        for (int i = 1; i < s.size(); i++)
        {
            if (!isdigit(s[i])) return 111;
        }
    }
    else // 处理自然数
    {
        if (s[0] == '0' && s.size() > 1) return 111; // "012" 或 "000" 不合法
        for (char c : s)
        {
            if (!isdigit(c)) return 111;
        }
    }
    return stoi(s); // 转换为数字
}

int cmax(int a,int b)
{
    int res = 0;
    res = max(a + b,max(a - b,a * b));
    return res;
}
