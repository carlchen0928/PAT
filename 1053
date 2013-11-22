#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, s;
vector<int> weight;
vector<vector<int>> adj;

void DFS(int start)
{
	stack<int> st;
	stack<int> apath;
	st.push(start);
	int curWeight = 0;
	while (!st.empty())
	{
		int top = st.top();
		st.pop();
		curWeight += weight[top];

		if(adj[top].empty() && curWeight == s)
		{

		}
		else if(!adj[top].empty() && curWeight < s)
		{
			apath.push(top);
			for(int i = 0; i < adj[top].size(); i++)
				st.push(adj[top][i]);
		}
		else continue;
	}
}

int main()
{
	cin>>n>>m>>s;
	for(int i = 0; i < n; i++)
		cin>>weight[i];
	adj = vector<vector<int>>(n, vector<int>());
	for(int i = 0; i < m; i++)
	{
		int index, adjnum;
		cin>>index>>adjnum;
		for(int j = 0; j < adjnum; j++)
		{
			int node;
			cin>>node;
			adj[index].push_back(node);
		}
	}
}
