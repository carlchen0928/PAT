#include <iostream>
#include <queue>
using namespace std;

#define CUSTOMER_MAX 1000+1
#define INF 0x6fffffff  

#ifndef LOCAL
//	#define LOCAL
#endif LOCAL

int n; // number of windows <=20
int m ;// queue capacity  <=10
int k; // customers  <=1000
int q; // query times <=1000

int  ProcessTime[CUSTOMER_MAX]; // 
queue<int> que[20];
queue<int >Wait[20];
int currTime = 0;
int LeaveTime[CUSTOMER_MAX];
int Timebase[20] = {0};

int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin>>n>>m>>k>>q;
	for(int i=0;i<k;i++)
	{
		cin>>ProcessTime[i];
	}
	int index;
	int top = 0;
	for(int i = 0;i<2*k;i++) 
	{
		int min_len  = m;
		if(top !=k) // if there are any customer not in line
		{
			for(int j=0;j<n;j++) 
			{
				if(min_len > que[j].size() )
				{
					min_len = que[j].size();
					index = j;
				}
			}
		}
		if(min_len != m) // find minimum queue 
		{
			que[index].push(top);
			Wait[index].push(ProcessTime[top]);
			top++;
		}else  // no queue available or no customer not in line, then customer pop 
		{
			long min_wait = INF;
			bool empty = true;
			for(int j=0;j<n;j++)
			{
				if(Wait[j].empty()) continue;
				if(min_wait > Timebase[j]+Wait[j].front())  // find current minimum wait time
				{
					min_wait = Timebase[j]+Wait[j].front();
					index = j;
					empty = false;
				}
			}
			if(empty) break;
			Timebase[index] += Wait[index].front();
			LeaveTime[que[index].front()] = Timebase[index];
			que[index].pop();
			Wait[index].pop();
		}
	}

	//60*9	
	int qq;
	for(int i=0;i<q;i++)
	{
		cin>>qq;
		qq--;
		if(LeaveTime[qq]-ProcessTime[qq]<60*9)
		{			
			int hour = LeaveTime[qq]/60;
			int second = LeaveTime[qq]%60;
			printf("%02d:%02d\n",8+hour,second);  
		}
		else
			printf("Sorry\n");
	}

#ifdef  LOCAL
	system("PASUE");
#endif LOCAL

	return 0;
}
