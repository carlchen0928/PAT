//类似于01背包的DP
//降序排列是关键！！！

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int N, M;
vector<int> v;
vector<vector<int>> l;

void dp()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(v[i] > j)
				l[i][j] = l[i - 1][j];
			else 
				l[i][j] = l[i - 1][j - v[i]] + v[i] > l[i - 1][j] ? l[i - 1][j - v[i]] + v[i] : l[i - 1][j];
		}
	}

	if(l[N][M] != M)
	{
		cout<<"No Solution"<<endl;
		return;
	}

	//回溯输出选取的序列
	int j = M;
	int i = N;
	//cout<<" ";
	while (j > 0)
	{
		if(l[i][j] == l[i - 1][j - v[i]] + v[i])
		{
			cout<<v[i];
			j -= v[i];
			i -= 1;
			if(j != 0) cout<<" ";
		}
		else
		{
			i -= 1;
		}
	}
	cout<<endl;
}

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	//fstream cin("a.txt");

	cin>>N>>M;
	v.push_back(0);
	for(int i = 0; i < N; i++)
	{
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin() + 1, v.end(), cmp);
	for(int i = 0; i <= N; i++)
	{
		vector<int> tmp;
		for(int j = 0; j <= M; j++)
			tmp.push_back(0);
		l.push_back(tmp);
	}
	dp();
}