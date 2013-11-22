#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

int n, m, s;
vector<int> weight;
vector<int> parent;
vector<vector<int> > adj;
vector<vector<int> > result;

void putResult(int leaf)
{
	vector<int> tmp;
	int node = leaf;
	while(node != -1)
	{
		tmp.push_back(node);
		node = parent[node];
	}
	result.push_back(tmp);
}

void DFS(int start)
{
	stack<int> st;
	st.push(start);
	int curWeight = 0;
	while (!st.empty())
	{
		int top = st.top();
		st.pop();
		curWeight += weight[top];

		if(adj[top].empty() && curWeight == s)
		{
			putResult(top);
			curWeight -= weight[top];
			continue;
		}
		else if(!adj[top].empty() && curWeight < s)
		{
			for(int i = 0; i < adj[top].size(); i++)
				st.push(adj[top][i]);
		}
		else 
		{
			curWeight -= weight[top];
			continue;
		}
	}
}

int main()
{
	fstream cin("a.txt");
	cin>>n>>m>>s;
	for(int i = 0; i < n; i++)
		cin>>weight[i];
	adj = vector<vector<int> >(n, vector<int>());
	parent = vector<int>(n, -1);
	for(int i = 0; i < m; i++)
	{
		int index, adjnum;
		cin>>index>>adjnum;
		for(int j = 0; j < adjnum; j++)
		{
			int node;
			cin>>node;
			adj[index].push_back(node);
			parent[node] = index;
		}
	}
	DFS(0);
	for(int i = 0; i < result.size(); i++)
	{
		vector<int>::reverse_iterator rit;
		for(rit = result[i].rbegin(); rit != result[i].rend(); rit ++)
		{
			if(rit == result[i].rend() - 1)
				cout<<*rit<<endl;
			else cout<<*rit<<" ";
		}
	}
}
