#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string a;
map<string, int> mp;

bool isAlf(int index)
{
	if(a[index] >= 'a' && a[index] <= 'z')
		return true;
	if(a[index] >= 'A' && a[index] <= 'Z')
	{
		a[index] = 'a' + (a[index] - 'A');
		return true;
	}
	if(a[index] >= '0' && a[index] <= '9')
		return true;
	return false;
}

int main()
{
//	fstream cin("a.txt");
	getline(cin, a);
//	cout<<a<<endl;
	string tmp = "";
	for(int i = 0; i < a.length(); i++)
	{
		if(isAlf(i))
			tmp += a[i];
		else if(tmp != "")
		{
			if(mp.find(tmp) == mp.end())
				mp.insert(pair<string, int>(tmp, 1));
			else
				mp[tmp]++;
			tmp = "";
		}
	}
	if(tmp != "")
	{
		if(mp.find(tmp) == mp.end())
			mp.insert(pair<string, int>(tmp, 1));
		else
			mp[tmp]++;
	}
	map<string, int>::iterator max = mp.begin();
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
//		cout<<it->first<<endl;
		if(it->second > max->second)
			max = it;
		else if(it->second == max->second)
		{
			if(it->first < max->first)
				max = it;
		}
	}
	cout<<max->first<<" "<<max->second<<endl;
	return 0;
}