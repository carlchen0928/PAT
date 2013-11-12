//#include <iostream>
//#include <int>
//#include <cstdlib>
//using namespace std;
//
//int getNum(char a)
//{
//	return ((a - '0') >= 0 && (a - '0') <=9) ? (a - '0') : (a - 'a' + 10);
//}
//
//long long toDecimal(int Sour, long long N)
//{
//	long long Decimal = 0;
//	for(int::iterator it = Sour.begin(); it != Sour.end(); it++)
//		Decimal = Decimal * N + getNum(*it);
//	if(Decimal < 0)
//		return -1;
//	else
//		return Decimal;
//}
//
//int findRadix(int a, int b, long long N)
//{
//	long long num = toDecimal(a, N);
//	for(int i = 2; i < 35; i++)
//	{
//		long long tmp = toDecimal(b, i);
//		if(tmp == -1)
//			continue;
//		if(num == tmp)
//			return i;
//	}
//	return 0;
//}
//
//int main()
//{
//	int a,b;
//	long long c,d;
//	cin>>a>>b>>c>>d;
//	int result = -1;
//	if(c == 1)
//		result = findRadix(a, b, d);
//	else
//		result = findRadix(b, a, d);
//	if(result == 0)
//		cout<<"Impossible"<<endl;
//	else
//		cout<<result<<endl;
//}

#include <stdio.h>
#include <int.h>

long num2Dec(char *,int);//转换成10进制数据
long findLowRadix(char *);//寻找最低进制数
long binarysearch(char *,long ,long, long);
int main()
{
	char N1[11],N2[11];
	int tag,radix;
	long target = 0L,result=0L;
	long least;//进制最小
	long most;//进制最大
	scanf("%s%s",N1,N2);
	scanf("%d%d",&tag,&radix);

	if(1 == tag)
	{
		target = num2Dec(N1,radix);
		least=findLowRadix(N2);
		most = (target + 1 > least + 1) ? target +1 :least +1; 
		result = binarysearch(N2,least,most,target);
		if(result == -1)
			printf("Impossible");
		else
			printf("%d\n",result);
	}else if(2 == tag)
	{
		target = num2Dec(N2,radix);
		least=findLowRadix(N1);
		most = (target + 1 > least + 1) ? target +1 :least +1; 
		result = binarysearch(N1,least,most,target);
		if(result == -1)
			printf("Impossible");
		else
			printf("%d\n",result);
	}

	return 0;
}
long num2Dec(char *p,int radix)
{
	int len = strlen(p);
	int m=1,num=1,sum=0;
	int i=0;
	for(i=len-1;i>=0;i--)
	{
		if(p[i]>='a' && p[i]<='z')
			num = p[i]-'a' + 10;
		else if(p[i] >= '0' && p[i] <= '9')
			num = p[i]-'0';
		sum += num*m;
		m*=radix;
	}
	return sum;
}

//ab:最小就是12进制  69：最小就是10进制
long findLowRadix(char *p)
{
	long len=strlen(p),low=0,num=0,i=0;  

	for(i=len-1;i>=0;i--)  
	{  
		if(p[i]>='a'&&p[i]<='z')  
			num= p[i] - 'a' + 10;  
		else if(p[i]>='0'&& p[i]<='9')  
			num=p[i] - '0';  
		if(num+1>low)  
			low=num+1;  
	}  

	return low;  
}
long binarysearch(char *p,long low,long high,long target)
{
	long mid=low,tmp=0;
	while(low<=high)
	{
		tmp = num2Dec(p,mid);
		if(tmp > target)
			high=mid-1;
		else if(tmp < target)
			low = mid+1;
		else 
			return low;
		mid = (low+high)/2;
	}
	return -1;
}