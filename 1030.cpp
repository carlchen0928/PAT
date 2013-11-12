#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct node
{
	int index;
	int curDist;
	vector<node> preCity;
	node(int c, int d) : index(c), curDist(d) {}
};

const int MAXINT = 0x7fffffff;
int n, m, s, d;
vector<vector<int>> dist;
vector<vector<int>> cost;
vector<node> v;
vector<node> q;
vector<int> result;
int totalCost = MAXINT;

bool cmp(const node &n1, const node &n2)
{
	return n1.curDist > n2.curDist;
}
bool cmp1(const node &n1, const node &n2)
{
	return n1.index < n2.index;
}

void Dijkstra()
{
	for(int i = 0; i < n; i++)
		v.push_back(node(i, MAXINT));
	v[s].curDist = 0;
	while (!v.empty())
	{
		make_heap(v.begin(), v.end(), cmp);
		pop_heap(v.begin(), v.end(), cmp);
		node n = v.back();
		v.pop_back();
		for(int i = 0; i < v.size(); i++)
		{
			if(dist[n.index][v[i].index] != -1)
			{
				int now = dist[n.index][v[i].index] + n.curDist;
				if(now < v[i].curDist)
				{
					v[i].curDist = now;
					v[i].preCity.clear();
					v[i].preCity.push_back(n);
				}
				else if(now == v[i].curDist)
					v[i].preCity.push_back(n);
			}
		}
		q.push_back(n);
	}
}

void getPath(int index, int curCost, vector<int> &seq)
{
	if(q[index].index == s)
	{
		if(curCost < totalCost)
		{
			totalCost = curCost;
			result = seq;
		}
	}
	else
	{
		for(int i = 0; i < q[index].preCity.size(); i++)
		{
			seq.push_back(q[index].preCity[i].index);
			curCost += cost[index][q[index].preCity[i].index];
			getPath(q[index].preCity[i].index, curCost, seq);
			curCost -= cost[index][q[index].preCity[i].index];
			seq.pop_back();
		}
	}
}

int main()
{
//	fstream cin("a.txt");
	cin>>n>>m>>s>>d;
	int i = 0;
	dist = vector<vector<int>>(n, vector<int>(n, -1));
	cost = vector<vector<int>>(n, vector<int>(n, -1));
	int t1, t2, t3, t4;
	while (i < m)
	{
		cin>>t1>>t2>>t3>>t4;
		dist[t1][t2] = dist[t2][t1] = t3;
		cost[t1][t2] = cost[t2][t1] = t4;
		i++;
	}
	Dijkstra();
	sort(q.begin(), q.end(), cmp1);
	vector<int> tmp;
	getPath(d, 0, tmp);
	for(vector<int>::reverse_iterator rit = result.rbegin(); rit != result.rend(); rit++)
		cout<<*rit<<" ";
	cout<<d<<" "<<q[d].curDist<<" "<<totalCost<<endl;
}