#include <iostream>
#include <memory.h>
using namespace std;

const int num = 100000;
int n, m;
int *dist;
int total = 0;

int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	dist = new int[n + 1];
	memset(dist, 0, (n + 1) * sizeof(int));
	int *adj;
	adj = new int[n + 1];
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &adj[i]);
		total += adj[i];
	}
	int nsum = 0;
	for(int i = 1; i < n; i++)
	{
		nsum += adj[i];
		dist[i + 1] = nsum;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int tmp;
		if(a > b) tmp = dist[a] - dist[b];
		else tmp = dist[b] - dist[a];
		printf("%d\n", ((tmp < total - tmp) ? tmp : (total - tmp)));
	}
}