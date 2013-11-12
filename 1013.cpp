#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

const int maxNum = 1001;

bool visited[maxNum];
int edge[maxNum][maxNum];
int N, M, K;

void DFS(int begin)
{
	for(int i = 1; i <= N; i++)
	{
		if(edge[begin][i] && !visited[i])
		{
			visited[i] = true;
			DFS(i);
		}
	}
}

int main()
{
	//fstream cin("a.txt");

	cin>>N>>M>>K;
	for(int i = 1; i <= M; i++)
	{
		int tmp1, tmp2;
		cin>>tmp1>>tmp2;
		edge[tmp1][tmp2] = edge[tmp2][tmp1] = 1;
	}
	memset(visited, 0, maxNum);

	int result = 0;
	for(int i = 0; i < K; i++)
	{
		int k;
		cin>>k;
		visited[k] = true;
		for(int j = 1; j <= N; j++)
		{
			if(!visited[j])
			{
				DFS(j);
				result++;
			}
		}
		cout<<result - 1<<endl;
		memset(visited, 0, maxNum);
		result = 0;
	}
}