#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct node
{
	string a;
	string b;
	node(string a, string b):a(a), b(b) {}
};

vector<node> v;

int main()
{
//	fstream cin("a.txt");
	int N;
	cin>>N;
	string a, b;
	for(int i = 0; i < N; i++)
	{
		cin>>a>>b;
		bool flag = false;
		for(string::iterator it = b.begin(); it != b.end(); it++)
		{
			switch (*it)
			{
			case '1':
				*it = '@';
				flag = true;
				break;
			case '0':
				*it = '%';
				flag = true;
				break;
			case 'l':
				*it = 'L';
				flag = true;
				break;
			case 'O':
				*it = 'o';
				flag = true;
				break;
			default: break;
			}
		}
		if(flag)
			v.push_back(node(a, b));
	}
	if(v.empty())
	{
		if(N == 1)
			cout<<"There is 1 account and no account is modified"<<endl;
		else cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
	}
	else
	{
		cout<<v.size()<<endl;
		for(int i = 0; i < v.size(); i++)
			cout<<v[i].a<<" "<<v[i].b<<endl;
	}
}