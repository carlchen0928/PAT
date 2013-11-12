#include <iostream>
#include <fstream>
using namespace std;

int N, M, P;
int *a;
int *b;
int *L;

int *stp;
const int MINNUM = -999;

bool compare(int tmp1, int tmp2)
{
	if(stp[tmp2 - 1] == -1)
		return false;
	if(stp[tmp1 - 1] >= stp[tmp2 - 1])
		return true;
	else
		return false;
}
bool isExist(int tmp)
{
	if(stp[tmp - 1] != -1)
		return true;
	return false;
}

void LIS()
{
	for(int j = 0; j < P; j++)
	{
		int max = MINNUM;
		if(!isExist(b[j]))
			continue;
		for(int p = 0; p < j; p++)
		{
			if(compare(b[j], b[p]))
				max = max > L[p] ? max : L[p];
		}
		if(max == MINNUM)
			continue;
		else
			L[j] = max + 1;
	}
}


int main()
{
	//fstream cin("a.txt");
	cin>>N>>M;

	stp = new int[N];
	for(int i = 0; i < N; i++)
		stp[i] = -1;

	a = new int[M];
	int tmp = 0;
	while (tmp < M)
	{
		cin>>a[tmp];
		stp[a[tmp] - 1] = tmp;
		tmp++;
	}
	cin>>P;
	b = new int[P];
	tmp = 0;
	while (tmp < P)
	{
		cin>>b[tmp];
		tmp++;
	}
	L = new int[P];
	for(int i = 0; i < P; i++)
		if(isExist(b[i]))
			L[i] = 1;
		else
			L[i] = -1;

	LIS();
	int maxnum = -2;
	for(int i = 0; i < P; i++)
		if(L[i] > maxnum)
			maxnum = L[i];
	if(maxnum > 0)
		cout<<maxnum<<endl;
	else
		cout<<0<<endl;
	//system("Pause");
}