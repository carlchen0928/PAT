#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;


int n, k;
const int big = 26 * 26 * 26 *10;
vector<int> v[big];
int main()
{
	//freopen("a.txt", "r", stdin);
	//fstream cin("a.txt");
	scanf("%d%d", &n, &k);
	int a, b;
	while(k--)
	{
		scanf("%d%d", &a, &b);
		for (int i = 0; i < b; ++i)
		{
			char *tmp = new char[5];
			scanf("%s", tmp);
			int hashIndex = (tmp[0] - 'A') * 26 * 26 * 10 + (tmp[1] - 'A') * 26 * 10 + (tmp[2] - 'A') * 10 + (tmp[3] - '0');
			v[hashIndex].push_back(a);
		}
	}
	std::vector<char *> query;

	for (int i = 0; i < n; ++i)
	{
		char *tmp = new char[5];
		scanf("%s", tmp);
		query.push_back(tmp);
	}
	for (int i = 0; i < query.size(); ++i)
	{
		char *tmp = query[i];
		int hashIndex = (tmp[0] - 'A') * 26 * 26 * 10 + (tmp[1] - 'A') * 26 * 10 + (tmp[2] - 'A') * 10 + (tmp[3] - '0');
		printf("%s", query[i]);
		if(v[hashIndex].size() == 0)
			printf(" 0");
		else
			printf(" %d", v[hashIndex].size());
		sort(v[hashIndex].begin(), v[hashIndex].end());
		for (int j = 0; j < v[hashIndex].size(); ++j)
			printf(" %d", v[hashIndex][j]);
		printf("\n");
	}
}