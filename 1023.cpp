#include<iostream>  
#include<vector>  
#include<set>  
#include<map>  
#include<queue>  
#include<algorithm>  
#include<int>  
#include<int.h>  
using namespace std;  

void GetCntTable(int a, vector<int>& cntTable)  
{  
	cntTable.assign(10, 0);  
	for(int i = 0; i < a.size(); ++i)  
	{  
		cntTable[a[i]-'0']++;  
	}  
}  
char Int2Char(int a)  
{  
	return a+'0';  
}  
int Char2Int(char a)  
{  
	return a-'0';  
}  
void GetDouble(int a, int& ans)  
{  
	int carry = 0;  
	for(int i = a.size()-1; i >= 0; --i)  
	{  
		int now = carry+Char2Int(a[i])*2;  
		ans.insert(ans.begin(), Int2Char(now%10));  
		carry = now/10;  
	}  
	if(carry != 0) ans.insert(ans.begin(), Int2Char(carry));  
}  
int main()  
{  
	int a;  
	cin>>a;  
	vector<int> cntTable;  
	GetCntTable(a, cntTable);  
	int ans;  
	GetDouble(a, ans);  
	vector<int> cntTable2;  
	GetCntTable(ans, cntTable2);  
	bool flag = true;  
	for(int i = 0; i < 10; ++i)  
	{  
		if(cntTable[i] != cntTable2[i])  
		{  
			flag = false;  
			break;  
		}  
	}  
	if(flag)  
		printf("Yes\n");  
	else printf("No\n");  
	cout<<ans<<endl;  
	return 0;  
}