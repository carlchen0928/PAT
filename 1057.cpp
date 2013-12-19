#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int total = 100001;
vector<int> tree(total, 0);
vector<int> f(total, 0);
int n;
stack<int> s;

int lowBit(int idx)
{
	return idx & (idx ^ (idx - 1));
}

int read(int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= lowBit(idx);
	}
	return sum;
}

void update(int idx, int val)
{
	f[idx] += val;
	while (idx < total)
	{
		tree[idx] += val;
		idx += lowBit(idx);
	}
}

int find_mid(int cumfre)
{
	int low = 0, high = total, mid;
	while (low < high - 1)
	{
		mid = (low + high)/2;
		int sum = read(mid);
		if(sum < cumfre)
			low = mid;
		else
			high = mid;
	}
	return high;
}

int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	char cmd[11];
	int num;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", &cmd);
		if(cmd[1] == 'u')
		{
			int tmp;
			scanf("%d", &tmp);
			update(tmp, 1);
			s.push(tmp);
		}
		else if(cmd[1] == 'o')
		{
			if(!s.empty())
			{
				int tmp = s.top();
				s.pop();
				update(tmp, -1);
				printf("%d\n", tmp);
			}
			else
				printf("Invalid\n");
		}
		else if(cmd[1] == 'e')
		{
			if(!s.empty())
			{
				int size = s.size();
				if(size & 1 == 1) //ÆæÊý
					printf("%d\n", find_mid((size + 1)/2));
				else 
					printf("%d\n", find_mid(size/2));
			}
			else
				printf("Invalid\n");
		}
	}
	return 0;
}