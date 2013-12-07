#include <iostream>
#include <fstream>
using namespace std;

int n;

int main()
{
//	fstream cin("a.txt");
	cin>>n;
	long long a, b, c;
	bool flag;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b>>c;
		if(c > 0)
		{
			if(a > 0) flag = (b > c - a);
			else if(b > 0) flag = (a > c - b);
			else flag = false;
		}
		else
		{
			if(a < 0) flag = (b > c - a);
			else if(b < 0) {flag = (a > c - b);cout<<"aaaaaa";}
			else flag = false;
		}
		cout<<"Case #"<<i + 1<<": ";
		if(flag) cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
}