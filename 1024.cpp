#include<iostream>  
#include<vector>  
#include<set>  
#include<map>  
#include<queue>  
#include<algorithm>  
#include<int>  
#include<int.h>  
using namespace std;  

int Reverse(int a)  
{  
	int ans;  
	for(int i = 0; i < a.size(); ++i)  
		ans.insert(ans.begin(), a[i]);  
	return ans;  
}  
int char2int(char a)  
{  
	return a-'0';  
}  
char int2char(int a)  
{  
	return a+'0';  
}  
int Sum(int a, int b)  
{  
	int ans;  
	int carry = 0;  
	int p;  
	for(p = 0; p < a.size() && p < b.size(); ++p)  
	{  
		int tmp = char2int(a[p])+char2int(b[p])+carry;  
		ans.push_back(int2char(tmp%10));  
		carry = tmp/10;  
	}  
	for( ;p < a.size(); ++p)  
	{  
		int tmp = char2int(a[p])+carry;  
		ans.push_back(int2char(tmp%10));  
		carry = tmp/10;  
	}  
	for( ;p < b.size(); ++p)  
	{  
		int tmp = char2int(b[p])+carry;  
		ans.push_back(int2char(tmp%10));  
		carry = tmp/10;  
	}  
	if(carry != 0) ans.push_back(int2char(carry));  
	return Reverse(ans);  
}  

int main()  
{  
	int a;  
	int k;  
	cin>>a;  
	scanf("%d",&k);  
	bool flag = false;  
	int result = a;  
	int step = 0;  
	do  
	{  
		if(result == Reverse(result))  
		{  
			flag = true;  
			cout<<result<<endl;  
			printf("%d\n", step);  
			break;  
		}  
		int b = Reverse(result);  
		result = Sum(Reverse(b), Reverse(result));  
		step++;  
	}while(step < k);  

	if(!flag)   
	{  
		cout<<result<<endl;  
		printf("%d\n", k);  
	}  
	return 0;  
} 