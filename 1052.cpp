#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int maxAddr = 1000000;
struct node
{
	int addr;
	int key;
	int next;
};

bool cmp(const node &n1, const node &n2)
{
	return n1.key < n2.key;
}
vector<node> v;
vector<node> all(maxAddr);
int n, start;

int main()
{
	cin>>n>>start;
	int a, b, c;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b>>c;
		node n;
		n.addr = a;
		n.key = b;
		n.next = c;
		if(n.addr >= 0 && n.addr < maxAddr)
			all[n.addr] = n;
	}

	while (true)
	{
		if(n == 0)
		{
			cout<<"0 -1"<<endl;
			return 0;
		}
		if(start == -1) break;
		v.push_back(all[start]);
		start = all[start].next;
	}
	if(v.size() == 0)
	{
		cout<<"0 -1"<<endl;
		return 0;
	}
	sort(v.begin(), v.end(), cmp);
	cout<<v.size()<<" "<<setw(5)<<setfill('0')<<right<<v[0].addr<<endl;
	for(int i = 0; i < v.size(); i++)
	{
		if(i != v.size() - 1)
		{
			cout<<setw(5)<<setfill('0')<<right<<v[i].addr;
			cout<<" "<<v[i].key<<" ";
			cout<<setw(5)<<setfill('0')<<right<<v[i + 1].addr<<endl;
		}
		else
		{
			cout<<setw(5)<<setfill('0')<<right<<v[i].addr;
			cout<<" "<<v[i].key<<" -1"<<endl;
		}
	}
}