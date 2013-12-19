#include<iostream>  
#include<string>  
#include<functional>  
#include<algorithm>  
#include<vector>  
#include<cstdio>  
using namespace std;  

typedef struct people  
{  
	string Name;  
	int Age;  
	int Net_Worth;  
	bool operator > (const people & p)const 
	{  
		if(Net_Worth != p.Net_Worth)  
		{  
			return Net_Worth > p.Net_Worth;  
		}  
		else  
		{  
			if(Age != p.Age) return Age < p.Age;  
			else 
				return Name < p.Name;  
		}  
	}  
}people;  



int main()  
{  
	int N; //the total number of people  
	int K; //the number of queries    
	int M;//the maximum number of outputs  
	int Amin,Amax;  
	int i,j,t1,t2,num;  
	cin>>N>>K;  

	vector<people> v(N);  
	for(i=0; i<N; i++)  
	{  
		cin>>v[i].Name;  
		scanf("%d%d",&v[i].Age,&v[i].Net_Worth);  
	}  

	sort(v.begin(),v.end(),greater<people>());  
	int filter[100000];  
	int filter_num = 0;  
	int age_count[201] = {0}; //记录某个年龄出现的次数  
	for(i=0; i<v.size(); i++)  
	{  
		if(++age_count[ v[i].Age ] < 101)  
			filter[ filter_num++ ] = i;  
	}  

	for(i=1; i<=K; i++)  
	{  
		scanf("%d%d%d",&M,&Amin,&Amax);  
		bool first = true;  
		cout<<"Case #"<<i<<":"<<endl;  
		int age;  
		num = 0;  
		for(j=0; j<filter_num && num<M; j++)  
		{  
			age = v[ filter[j] ].Age;  
			if(age >= Amin && age <= Amax)  
			{  
				num++;  
				//用cout输出会有两组数据超时  
				//cout<<v[ filter[j] ].Name<<" "<<v[ filter[j] ].Age<<" "<<v[ filter[j] ].Net_Worth<<endl;  
				cout<<v[ filter[j] ].Name<<" ";  
				printf("%d %d\n",v[filter[j]].Age,v[filter[j]].Net_Worth);  
			}  
		}  
		if(num == 0)  
			cout<<"None"<<endl;   
	}  
	return 0;  
}  