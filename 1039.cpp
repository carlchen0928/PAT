#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int n, k;
map<char *, vector<int> > m;
int main()
{
	fstream cin("1.txt");
	cin>>n>>k;
	int a, b;
	while(k--)
	{
		cin>>a>>b;
		char tmp[5];
		for (int i = 0; i < b; ++i)
		{
			scanf("%s", tmp);
			m[tmp].push_back(a);
		}
	}
	std::vector<char *> query;
	for (int i = 0; i < n; ++i)
	{
		char tmp[5];
		scanf("%s", tmp);
		query.push_back(tmp);
	}
	for (int i = 0; i < query.size(); ++i)
	{
		cout<<query[i];
		if(m[query[i]].size() == 0)
			cout<<" 0";
		else
			cout<<" "<<m[query[i]].size();
		sort(m[query[i]].begin(), m[query[i]].end());
		for (int j = 0; j < m[query[i]].size(); ++j)
		{
			cout<<" "<<m[query[i]][j];
		}
		cout<<endl;
	}
}

