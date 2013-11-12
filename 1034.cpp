#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int num = 2002;
int n, thres;
int s[num][num];
map<string, int> m;
map<int, string> name;
bool visited[num];
int gangSize = 0;
int totalWeight = 0;
int id = 0;
int head;

struct node
{
	int headIndex;
	int gangNum;
	node(int h, int g):headIndex(h), gangNum(g) {}
};
typedef struct
{
	string name;
	int wgt;
}member;
member mem[num];
vector<node> result;

void DFS_VISIT(int i)
{
	if(mem[i].wgt > mem[head].wgt)
		head = i;
	gangSize++;
	visited[i] = true;
	for(int j = 1; j <= id; j++)
		if(s[i][j] != 0)
			totalWeight += s[i][j];
	for(int j = 1; j <= id; j++)
	{
		if(s[i][j] != 0 && !visited[j])
		{
			DFS_VISIT(j);
		}
	}
}

void DFS()
{
	for(int i = 1; i <= id; i++)
	{
		if(!visited[i])
		{
			head = i;
			gangSize = 0;
			totalWeight = 0;
			DFS_VISIT(i);
			if(totalWeight/2 > thres && gangSize > 2)
			{
				int biggest = 1;
				node n(head, gangSize);
				result.push_back(n);
			}
		}
	}
}

bool comp(const node &n1, const node &n2)
{
	return name[n1.headIndex].compare(name[n2.headIndex]) < 0;
}

int main()
{
//	fstream cin("a.txt");
	memset(visited, 0, sizeof(visited)/sizeof(bool));
	cin>>n>>thres;
	string a, b;
	int c;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b>>c;
		if(!m[a]) {m[a] = ++id; name[id] = a;}
		if(!m[b]) {m[b] = ++id; name[id] = b;}
		s[m[a]][m[b]] = s[m[b]][m[a]] = s[m[a]][m[b]] + c;
		mem[m[a]].name = a;
		mem[m[a]].wgt += c;
		mem[m[b]].name = b;
		mem[m[b]].wgt += c;
	}
	DFS();
	if(result.size() == 0)
		cout<<0<<endl;
	else
	{
		sort(result.begin(), result.end(), comp);
		cout<<result.size()<<endl;
		for(int i = 0; i < result.size(); i++)
			cout<<name[result[i].headIndex]<<" "<<result[i].gangNum<<endl;
	}
}

