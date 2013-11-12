#include <iostream>
#include <fstream>
using namespace std;

bool isAllNeg(int a[], int n)   
{   
	int i = 0;   
	for(i=0; i<n; i++)   
		if(a[i] >= 0)   
			return false;   
	return true;   
}  

int main()
{
	//fstream cin("a.txt");

	int num;
	cin>>num;
	int *A = new int[num];
	int i = 0;
	while (i < num) 
	{
		cin>>A[i];
		i++;
	}

	int Max, Cur;
	Max = Cur = 0;
	int start, end, curStart;
	start = end = curStart = A[0];
	for(int i = 0; i < num; i++)
	{
		Cur += A[i];
		if(Cur < 0)
		{
			Cur = 0;
			(i + 1) < num ? curStart = A[i + 1]:curStart = curStart;
		}
		if(Max < Cur)
		{
			Max = Cur;
			end = A[i];
			start = curStart;
		}
	}
	
	if(isAllNeg(A, num))
		cout<<0<<" "<<A[0]<<" "<<A[num - 1];
	else if(Max == 0)
		cout<<0<<" "<<0<<" "<<0;
	else
		cout<<Max<<" "<<start<<" "<<end<<endl;
}
