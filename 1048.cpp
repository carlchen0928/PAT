#include <iostream>
using namespace std;

const int maxFace = 1000;
int faceV[maxFace + 1];
int n, m;
int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(tmp < m) faceV[tmp]++;
	}
	int pos = 0;
	bool flag = false;
	for(pos = 1; pos < m; pos++)
	{
		if(faceV[pos] == 0 || faceV[m - pos] == 0)
			continue;
		else if(pos == m - pos && faceV[pos] == 1)
			continue;
		else
		{
			flag = true;
			break;
		}
	}
	if(flag)
		printf("%d %d\n", pos, m - pos);
	else
		printf("No Solution\n");
}