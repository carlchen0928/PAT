//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//using namespace std;
//
//int n;
//
//int sig(vector<char> &v, string s)
//{
//	int p;
//	int k = -1;
//	bool first = true;
//	for(int i = 0; i < s.size(); i++)
//	{
//		if(s[i] != '0' && s[i] != '.' && first)
//		{
//			p = i;
//			first = false;
//		}
//		if(s[i] == '.')
//			k = i;
//	}
//	if(k == -1) k = s.size();
//	for(int j = p; j < s.size() && j < n; j++)
//	{
//		if(s[j] != '.')
//			v.push_back(s[j]);
//	}
//	if(k - p < 0) return k - p + 1;
//	else return k - p;
//}
//
//bool equalv(vector<char> &v1, vector<char> &v2)
//{
//	if(v1.size() != v2.size()) return false;
//	for(int i = 0; i < v1.size(); i++)
//		if(v1[i] != v2[i])
//			return false;
//	return true;
//}
//
//void printv(vector<char> &v, int cof)
//{
//	cout<<" 0.";
//	for(int i = 0; i < v.size(); i++)
//		cout<<v[i];
//	if(v.size() < n)
//		for(int j = 0; j < v.size() - n; j++)
//			cout<<'0';
//	cout<<"*10^"<<cof;
//}
//
//int main()
//{
////	freopen("a.txt", "r", stdin);
//	string s1, s2;
//	cin>>n;
//	cin>>s1>>s2;
//	vector<char> v1, v2;
//
//	int cof1 = sig(v1, s1);
//	int cof2 = sig(v2, s2);
//	bool flag = true;
//	if(cof1 != cof2 || !equalv(v1, v2))
//	{
//		cout<<"NO";
//		flag = false;
//	}
//	else cout<<"YES";
//	printv(v1, cof1);
//	if(!flag) printv(v2, cof2);
//	cout<<endl;
//	return 0;
//}

/*
test 6 
3 0.00 00.00
test 3
3 0.1 0.001
0.001=0.1*10^-2
pay 
前导0
不同格式的0
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char a[105],b[105];
struct num
{
	char s[105];
	int k;
}x,y;
struct num getn(char a[],int n)
{
	int na=strlen(a),i,j=na,k=na,t,flag=0;
	struct num x;
	memset(x.s,'0',n*sizeof(char));
	x.s[n]='\0';
	for(i=0;i<na;i++)
	{
		if(a[i]>'0'&&a[i]<='9'&&!flag)
		{
			j=i;
			flag=1;
		}
		if(a[i]=='.')k=i;
	}
	//	printf("%d %d\n",j,k);
	if(j==na)
	{
		x.k=0;
	}
	else
	{
		t=0;
		for(i=j;i<na&&t<n;i++)
			if(i!=k)x.s[t++]=a[i];
		if(k>j)x.k=k-j;
		else
			x.k=k-j+1;
	}
	//printf("%s %d\n",x.s,x.k);
	return x;

}
void deal(char a[],char b[],int n)
{
	x=getn(a,n);
	y=getn(b,n);
	if(!strcmp(x.s,y.s)&&x.k==y.k)printf("YES 0.%s*10^%d\n",x.s,x.k);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",x.s,x.k,y.s,y.k);
}
int main()
{

	int na,nb,i,n,t,flag;
	while(scanf("%d%s%s",&n,a,b)!=EOF)
	{
		deal(a,b,n);
	}
	return 0;
}
