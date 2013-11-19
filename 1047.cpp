#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct stu
{
	char name[5];
};

int n, k;
vector<vector<int> > v;
vector<stu > names;

bool cmp(int a1, int a2)
{
	return strcmp(names[a1].name, names[a2].name) < 0;
}

int main()
{
	freopen("a.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	v = vector<vector<int> >(k, vector<int>());
	names = vector<stu>(n, stu());
	for(int i = 0; i < n; i++)
	{
		int c;
		scanf("%s %d", &names[i].name, &c);
		for(int j = 0; j < c; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			v[tmp - 1].push_back(i);
		}
	}

	for(int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n", i + 1, v[i].size());
		sort(v[i].begin(), v[i].end(), cmp);
		for(int j = 0; j < v[i].size(); j++)
			printf("%s\n", names[v[i][j]].name);
	}
}
