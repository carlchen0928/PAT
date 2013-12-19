#include <iostream>
#include <vector>
using namespace std;

int n, m;
int *chain;
vector<pair<int, int>> v;
int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	chain = new int[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &chain[i]);
	
	int curSum = 0;
	int nSum = 0;
	//for(int i = 0; i < n; i++)
	//{
	//	int nSum = 0;
	//	for(int j = i; j < n; j++)
	//	{
	//		nSum += chain[j];
	//		if(nSum >= m)
	//		{
	//			if(nSum - m < abs(curSum - m))
	//			{
	//				v.clear();
	//				v.push_back(make_pair(i, j));
	//				curSum = nSum;
	//			}
	//			else if(nSum - m == abs(curSum - m))
	//			{
	//				v.push_back(make_pair(i, j));
	//			}
	//			break;
	//		}
	//	}
	//}

	int i = 0, j = 0;
	while (i < n && j < n)
	{
		nSum += chain[j];
		if(nSum < m)
		{
			j++;
			continue;
		}
		if(nSum >= m)
		{
			if(nSum - m < abs(curSum - m))
			{
				v.clear();
				v.push_back(make_pair(i, j));
				curSum = nSum;
			}
			else if(nSum - m == abs(curSum - m))
				v.push_back(make_pair(i, j));
			nSum -= chain[i];
			nSum -= chain[j];
			i++;
			continue;
		}
	}
	for(int i = 0; i < v.size(); i++)
		printf("%d-%d\n", v[i].first + 1, v[i].second + 1);
}