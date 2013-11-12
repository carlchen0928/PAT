#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

struct node
{
	char s;
	int next;
	bool flag;
	node(char s, int n, bool f) : s(s), next(n), flag(f) {}
	node() {}
};

map<int, node> m;
int a, b, c;
int d, e;
char cc; 

int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d%d%d", &a, &b, &c);
	for(int i = 0; i < c; i++)
	{
		scanf("%d%s%d", &d, &cc, &e);
		node n(cc, e, false);
		m[d] = n;
	}
	int tmp = b;
	while (tmp != -1)
	{
		m[tmp].flag = true;
		tmp = m[tmp].next;
	}
	tmp = a;
	while (tmp != -1)
	{
		if(m[tmp].flag == true)
			break;
		tmp = m[tmp].next;
	}
	if(tmp != -1)
	{
		cout.fill('0');
		cout<<setw(5)<<std::right<<tmp<<endl;
	}
	else cout<<tmp<<endl;
}