#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int opened = 8 * 60 * 60;
const int closed = 17 * 60 * 60;

struct customer
{
	int hour;
	int minute;
	int second;
	int time;
	int total;
	customer(int h, int m, int s, int t) : hour(h), minute(m), second(s), time(t) { total = hour * 60 * 60 + minute * 60 + second; }
};

bool cmp(const customer &c1, const customer &c2)
{
	return c1.total < c2.total;
}

vector<customer> v;

int main()
{
	//freopen("a.txt", "r", stdin);

	int n, k;
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++)
	{
		int a, b, c, d;
		scanf("%d:%d:%d%d", &a, &b, &c, &d);
		customer cus(a, b, c, d);
		v.push_back(cus);
	}
	sort(v.begin(), v.end(), cmp);

	vector<int> endtime(k, opened);
	int waitingTime = 0;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i].total > closed) continue;
		int minIndex = 0;
		for(int j = 0; j < k; j++)
			if(endtime[j] < endtime[minIndex])
				minIndex = j;
		if(v[i].total > endtime[minIndex])
			endtime[minIndex] = v[i].total + v[i].time * 60;
		else
		{
			waitingTime += (endtime[minIndex] - v[i].total);
			endtime[minIndex] += v[i].time * 60;
		}
		count++;
	}
	if(count)
		printf("%.1lf\n", waitingTime/count/60.0);
	else 
		printf("0.0\n");
}