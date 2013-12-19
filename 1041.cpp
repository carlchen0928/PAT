#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int v[100000];
int input[100000];
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v[tmp]++;
		input[i] = tmp;
	}
	bool flag = false;
	for(i = 0; i < n; i++)
	{
		if(v[input[i]] == 1)
		{
			flag = true;
			break;
		}
	}
	if(flag)
		cout<<input[i]<<endl;
	else
		cout<<"None"<<endl;
	return 0;
}