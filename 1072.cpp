#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXINT = 0x7ffffff;
struct node
{
	int index;
	int distance;
	bool visited;
	node(int a, int b, bool v):index(a), distance(b), visited(v){}
};

int n, m, k, d;
double minDis, avgDis;
vector<vector<node>> dist;

bool comp(const node &n1, const node &n2)
{
	return n1.distance < n2.distance;
}

bool Dijkstra(int start)
{
	vector<node> current;
	vector<node> res;
	current.push_back(node(-1, -1, false));
	res.push_back(node(-1, -1, false));
	for(int i = 1; i < n + m + 1; i++)
		current.push_back(node(i, MAXINT, false));
	current[start].distance = 0;
	current[start].visited = true;
	res.push_back(current[start]);
	int tmp = start;
	while (true)
	{
		for(int i = 0; i < dist[tmp].size(); i++)
		{
			if(current[dist[tmp][i].index].distance > current[tmp].distance + dist[tmp][i].distance && !current[dist[tmp][i].index].visited)
				current[dist[tmp][i].index].distance = current[tmp].distance + dist[tmp][i].distance;
		}
		int minIndex = 0;
		int minValue = MAXINT;
		for(int i = 1; i < current.size(); i++)
			if(current[i].distance < minValue && !current[i].visited)
			{
				minIndex = i;
				minValue = current[i].distance;
			}
		current[minIndex].visited = true;
		res.push_back(current[minIndex]);
		tmp = minIndex;
		if(current[minIndex].distance > d && current[minIndex].index <= n)
			return false;
		if(res.size() == current.size())
			break;
	}
	double total = 0.0;
	minDis = (double)MAXINT;
	for(int i = 1; i < res.size(); i++)
	{
		if(res[i].index <= n)
		{
			total += res[i].distance;
			if(minDis > res[i].distance)
				minDis = (double)res[i].distance;
		}
	}
	avgDis = total/n;
	return true;
}

int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &k, &d);
	dist = vector<vector<node>>(n + m + 1, vector<node>());
	for(int i = 0; i < k; i++)
	{
		char tmp1[5];
		char tmp2[5];
		int dis;
		scanf("%s %s %d", &tmp1, &tmp2, &dis);
		int begin;
		int end;
		if(tmp1[0] != 'G') begin = atoi(tmp1);
		else
		{
			char gas[5];
			for(int j = 1; j < 5; j++)
				gas[j - 1] = tmp1[j];
			begin = atoi(gas) + n;
		}
		if(tmp2[0] != 'G') end = atoi(tmp2);
		else
		{
			char gas[5];
			for(int j = 1; j < 5; j++)
				gas[j - 1] = tmp2[j];
			end = atoi(gas) + n;
		}
		dist[begin].push_back(node(end, dis, false));
		dist[end].push_back(node(begin, dis, false));
	}
	int fin;
	double minAvg = (double)MAXINT;
	double minDisf = -1.0;
	for(int i = 1; i <= m; i++)
	{
		minDis = 0.0;
		avgDis = 0.0;
		bool flag = Dijkstra(n + i);
		if(flag)
		{
			if(minDisf < minDis)
			{
				fin = i;
				minAvg = avgDis;
				minDisf = minDis;
			}
			else if(minDisf == minDis)
			{
				if(minAvg > avgDis)
				{
					fin = i;
					minAvg = avgDis;
					minDisf = minDis;
				}
			}
		}
	}
	if(minDisf == -1.0)
		printf("No Solution\n");
	else
	{
		printf("G%d\n", fin);
		printf("%.1lf %.1lf\n", minDisf, minAvg);
	}
}