#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <queue>
using namespace std;

int n;
vector<int> v;
vector<int> result;

struct node
{
	node *left;
	node *right;
	int data;
	node() {left = NULL; right = NULL;}
};
queue<node *> q;
void partition(node *curroot, int begin, int end, bool flag)
{
	if(begin == end)
	{
		node *tmp = new node;
		tmp->data = v[begin];
		if(flag) curroot->left = tmp;
		else curroot->right = tmp;
		return;
	}
	else if(begin > end) return;
	int nodesNum = end - begin;
	int cof = 1;
	while (true)
	{
		int total = 2 * (pow(2, cof) - 1);
		if(nodesNum <= total)
		{
			int half = total - pow(2, cof - 1);
			if(nodesNum > half)
			{
				node *tmp = new node;
				int leftnum = pow(2, cof) - 1;
				tmp->data = v[begin + leftnum];
				if(flag) curroot->left = tmp;
				else curroot->right = tmp;
				partition(tmp, begin, begin + leftnum - 1, true);
				partition(tmp, begin + leftnum + 1, end, false);
				return;
			}
			else
			{
				node *tmp = new node;
				int rightnum = pow(2, cof - 1) - 1;
				tmp->data = v[end - rightnum];
				if(flag) curroot->left = tmp;
				else curroot->right = tmp;
				partition(tmp, begin, end - rightnum - 1, true);
				partition(tmp, end - rightnum + 1, end, false);
				return;
			}
		}
		else cof++;
	}
}

void level_order_travel(node *root)
{
	node *tmp = root;
	q.push(tmp);
	while (!q.empty())
	{
		node *k = q.front();
		q.pop();
		result.push_back(k->data);
		if(k->left != NULL) q.push(k->left);
		if(k->right != NULL) q.push(k->right);
	}
}

int main()
{
//	fstream cin("a.txt");
	cin>>n;
	v = vector<int>(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	node *root = new node;
	partition(root, 0, v.size() - 1, true);
	level_order_travel(root->left);
	for(int i = 0; i < result.size(); i++)
	{
		if(i == 0) cout<<result[i];
		else cout<<" "<<result[i];
	}
	cout<<endl;
	return 0;
}