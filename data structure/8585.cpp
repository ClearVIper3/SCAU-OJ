#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;
	while(n != 0)
	{
		s.push(n % 8);
		n /= 8;
	}

	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}
