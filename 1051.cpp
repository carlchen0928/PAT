#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

int m, n, k;
stack<int> s;

int main()
{
//	fstream cin("a.txt");
	cin>>m>>n>>k;
	for(int i = 0; i < k; i++)
	{
		int *seq = new int[n + 1];
		for(int j = 0; j < n; j++)
			cin>>seq[j + 1];
		int p = 1;
		int q = 1;
		s.push(p);
		bool flag = false;
		while (true)
		{
			if(s.size() > m || (q <= n && p > n))
			{
				flag = true;
				break;
			}
			if(q > n && p > n)
				break;

			if(s.empty() || s.top() != seq[q])
			{
				p++;
				s.push(p);
			}
			else
			{
				s.pop();
				q++;
			}
		}
		while (!s.empty())
			s.pop();
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}