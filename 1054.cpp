#include <iostream>
#include <fstream>
using namespace std;

int m, n;
int times = 1;
int curNum = -1;
int main()
{
//	fstream cin("a.txt");
	cin>>m>>n;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if(i == 0 && j == 0)
				curNum = tmp;
			if(times == 0)
			{
				curNum = tmp;
				times++;
			}
			else if(curNum != tmp)
				times--;
			else
				times++;
		}
	}
	cout<<curNum<<endl;
}