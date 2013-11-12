#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

vector<vector<int>> tree;
vector<int> ans;

void BFS(int s)
{
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	int cur_step = 0;
	int cnt = 0;

	while (!q.empty())
	{
		int id = q.front().first;
		int step = q.front().second;
		q.pop();
		if(step > cur_step)
		{
			cur_step = step;
			ans.push_back(cnt);
			cnt = 0;
		}
		if(tree[id].size() == 0) cnt++;
		for(int i = 0; i < tree[id].size(); i++)
			q.push(make_pair(tree[id][i], step + 1));
	}
	ans.push_back(cnt);
	return;
}

int main()
{
	//fstream cin("a.txt");

	int N, M;
	cin>>N>>M;
	tree.resize(N + 1);
	for(int i = 0; i < M; i++)
	{
		int id, num;
		cin>>id>>num;
		while (num--)
		{
			int tmp;
			cin>>tmp;
			tree[id].push_back(tmp);
		}
	}
	BFS(1);
	for(int i = 0; i < ans.size(); i++)
	{
		if(i == 0)
			cout<<ans[i];
		else
			cout<<" "<<ans[i];
	}
	cout<<endl;
}