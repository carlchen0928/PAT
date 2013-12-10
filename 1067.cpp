#include <iostream>
using namespace std;

int n;
int *arr;
int *whereis;

void printArr()
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	scanf("%d", &n);
	arr = new int[n];
	whereis = new int[n];
	int first0 = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		whereis[arr[i]] = i;
		if(arr[i] == 0) first0 = i;
	}
	int count = 0;
	int zeroPosition = first0;
	while(true)
	{
		if(zeroPosition != 0)
		{
			int p = whereis[zeroPosition];
			arr[p] = 0;
			arr[zeroPosition] = zeroPosition;
			whereis[zeroPosition] = zeroPosition;
			whereis[0] = p;
			zeroPosition = p;
			count++;
//			printArr();
		}
		else
		{
			int i;
			for(i = 0; i < n; i++)
			{
				if(arr[i] != i)
				{
					int tmp = arr[i];
					whereis[arr[i]] = 0;
					whereis[0] = i;
					arr[i] = 0;
					arr[0] = tmp;
					zeroPosition = i;
					count++;
//					printArr();
					break;
				}
			}
			if(i == n) break;
		}
	}
	printf("%d\n", count);
}