#include<iostream>

void OutputWord(int a)
{
	int flag = a/13;
	if(0 == flag)
		printf("S");
	else if(1 == flag)
		printf("H");
	else if(2 == flag)
		printf("C");
	else if(3 == flag)
		printf("D");
	else if(4 == flag)
		printf("J");
	printf("%d", a%13+1);
}
#define NUM 54
int main()
{
	int n;
	int s[NUM];
	int a[NUM];
	while( scanf("%d", &n) != EOF )
	{
		for(int i = 0; i < NUM; ++i)
		{
			a[i] = i;
			scanf("%d", &s[i]);
		}
		//shuffling
		while(n--)
		{
			int a_back[NUM];
			for(int i = 0; i < NUM; ++i)
				a_back[i] = a[i];
			for(int i = 0; i < NUM; ++i)
				a[s[i]-1] = a_back[i]; 
		}
		//output
		for(int i = 0; i < NUM; ++i)
		{
			OutputWord(a[i]);
			//printf("%d", a[i]);
			if(i != NUM-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}