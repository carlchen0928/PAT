//Ò»´ÎDSF¼´¿É
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int num;
vector<vector<int>> adj;
vector<int> visited;
vector<int> deepest;
vector<int> distances;
int connected = 0;

void DSF_VISIT(int i)
{
	visited[i] = 1;
	for(int j = 0; j < adj[i].size(); j++)
	{
		if(!visited[adj[i][j]])
		{
			distances[adj[i][j]] = distances[i] + 1;
			DSF_VISIT(adj[i][j]);
		}
	}
	visited[i] = 2;
}

void DSF()
{
	for(int i = 1; i <= num; i++)
	{
		if(!visited[i])
		{
			DSF_VISIT(i);
			connected++;
		}
	}
}

int main()
{
	//fstream cin("a.txt");
	cin>>num;
	int tmp = num - 1;
	adj.assign(num + 1, vector<int>());
	visited.assign(num + 1, 0);
	deepest.assign(num + 1, 0);
	distances.assign(num + 1, 0);
	int a,b;
	while (tmp--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DSF();
	if(connected > 1)
		cout<<"Error: "<<connected<<" components"<<endl;
	else
	{
		for(int i = 1; i <= num; i++)
		{
			visited.assign(num + 1, 0);
			distances.assign(num + 1, 0);
			DSF_VISIT(i);
			vector<int>::iterator it = max_element(distances.begin(), distances.end());
			deepest[i] = *it;
		}
		vector<int>::iterator it = max_element(deepest.begin(), deepest.end());
		for(int i = 1; i < deepest.size(); i++)
		{
			if(deepest[i] == *it)
				cout<<i<<endl;
		}
	}
}