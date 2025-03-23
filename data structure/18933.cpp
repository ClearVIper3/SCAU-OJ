#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	char s[205];
	stack<int> used;
	stack<char> stk;
	while(scanf("%s",s) != EOF)
	{
		int i;
		for(i = 0; s[i] != '\0'; i++)
		{
			if(s[i] == '(')
			{
				stk.push(s[i]);
				used.push(i);
			}
			else if(s[i] == ')')
			{
				if(!stk.empty() && stk.top() == '(')
				{
					stk.pop();
					used.pop();
				}
				else
				{
					stk.push(s[i]);
					used.push(i);
				}
			}
		}
		
		vector<char> res(i + 1,' ');
		res[i] = '\0';
		while(!used.empty())
		{
			int a = used.top();
			char c = stk.top();
			used.pop();
			stk.pop();
			if(c == '(') res[a] = '$';
			else res[a] = '?';
		}
		
		puts(s);
		cout << &res[0] << endl;
	}
	return 0;
}
