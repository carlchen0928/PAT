#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> v;
bool flag = false;

bool cmp(const string &s1, const string &s2)
{
	string tmp1 = s1 + s2;
	string tmp2 = s2 + s1;
	return tmp1.compare(tmp2) < 0;
}

void printString(const string &s)
{
	int i = 0;
	if(!flag)
	{
		for(; i < s.size(); i++)
			if(s[i] != '0')
			{
				flag = true;
				break;
			}
		for(; i < s.size(); i++)
			cout<<s[i];
	}
	else
		cout<<s;
}

int main()
{
//	fstream cin("a.txt");
	int num;
	cin>>num;
	string tmp;
	for(int i = 0; i < num; i++)
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for_each(v.begin(), v.end(), printString);
	if(!flag) cout<<'0';
	cout<<endl;
}