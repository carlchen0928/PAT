#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<vector<char *>> v;

int main()
{
	freopen("a.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	v = vector<vector<char *>>(n, vector<char *>());
	for(int i = 0; i < n; i++)
	{
		char name[4];
		int c;
		scanf("%s %d", &name, &c);
		int tmp;
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &tmp);
			v[tmp].push_back(name);
		}
	}

	for(int i = 0; i < v.size(); i++)
	{
		cout<<i + 1<<" "<<v[i].size()<<endl;
		for(int j = 0; j < v[i].size(); j++)
			cout<<v[i][j]<<endl;
	}
}