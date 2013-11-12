#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n1, n2;
	n2 = (s.size() % 2 == 1)?3 : 4;
	while (n2 <= s.size())
	{
		n1 = (s.size() - n2)/2 + 1;
		if(n1 <= n2) break;
		n2 += 2;
	}
	int i = 0;
	for(; i < n1 - 1; i++)
	{
		cout<<s[i];
		for(int j = 0; j < n2 - 2; j++)
			cout<<" ";
		cout<<s[s.size() - i - 1]<<endl;
	}
	for(int j = i; j < s.size() - i; j++)
		cout<<s[j];
	cout<<endl;
}