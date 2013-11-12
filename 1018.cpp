#include <iostream>
#include <memory.h>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxInt = 0x7fffffff;
const int maxStation = 501;
int road[501][501];
int bikeCount[501];
bool visited[501];
int capacity, stationNum, proStation, roadsNum;



struct node
{
	int index;
	int minDistance;
	vector<int> preNode;
	node(int i, int minDistance) : index(i), minDistance(minDistance) {}
};
vector<node> q;
vector<node> s;
int minBike = maxInt;
vector<int> result;

bool cmp(const node &n1, const node &n2)
{
	return n1.minDistance > n2.minDistance;
}
bool cmpbyIndex(const node &n1, const node &n2)
{
	return n1.index > n2.index;
}

void Dijkstra()
{
	s.push_back(node(0, 0));
	for(int i = 1; i <= stationNum; i++)
		s.push_back(node(i, maxInt));
	while (!s.empty())
	{
		make_heap(s.begin(), s.end(), cmp);
		pop_heap(s.begin(), s.end(), cmp);
		node tmp = s.back();
		s.pop_back();
		for(int i = 0; i < s.size(); i++)
		{
			if(road[tmp.index][s[i].index])
			{
				if(tmp.minDistance + road[tmp.index][s[i].index] < s[i].minDistance)
				{
					s[i].minDistance = tmp.minDistance + road[tmp.index][s[i].index];
					s[i].preNode.clear();
					s[i].preNode.push_back(tmp.index);
				}
				else if(tmp.minDistance + road[tmp.index][s[i].index] == s[i].minDistance)
					s[i].preNode.push_back(tmp.index);
			}
		}
		q.push_back(tmp);
	}
}



int getPath(int index, int cur, vector<int> path)
{
	const int need = bikeCount[proStation] - capacity/2;
	sort(s.begin(), s.end(), cmpbyIndex);
	if(index == 0)
	{
		if(abs(cur + need + 5) < abs(minBike + need + 5))
		{
			minBike = cur;
			result = path;
		}
		return 0;
	}
	for(int i = 0; i < q[index].preNode.size(); i++)
	{
		path.push_back(q[index].preNode[i]);
		getPath(q[index].preNode[i], bikeCount[q[index].preNode[i]] - capacity/2 + cur, path);
		path.pop_back();
	}
}

int main()
{
	fstream cin("a.txt");

	cin>>capacity>>stationNum>>proStation>>roadsNum;
	for(int i = 1; i <= stationNum; i++)
		cin>>bikeCount[i];
	for(int i = 0; i < roadsNum; i++)
	{
		int row, colunm, tmp;
		cin>>row>>colunm>>tmp;
		road[row][colunm] = road[colunm][row] = tmp;
	}
	memset(visited, 0, sizeof(visited)/sizeof(bool));



	Dijkstra();

	getPath(proStation, 0, vector<int>());
	//system("pause");
	int tmp = bikeCount[proStation] + minBike;
	if(tmp < 0)
		cout<<abs(tmp)<<" ";
	else cout<<0<<" ";
	
	reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout<<result[i]<<"->";
	}
	cout<<proStation<<" ";
	if(tmp > 0)
		cout<<tmp<<endl;
	else cout<<0<<endl;
}


