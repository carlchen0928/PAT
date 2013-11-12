#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<long> v1;
vector<long> v2;
int main()
{
	int a, b;
	long tmp;

	scanf("%d", &a);
	int i = 0;
	while (i < a)
	{
		scanf("%ld", &tmp);
		v1.push_back(tmp);
		i++;
	}
	scanf("%d", &b);
	i = 0;
	while (i < b)
	{
		scanf("%ld", &tmp);
		v2.push_back(tmp);
		i++;
	}
	vector<long> v3(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	i = 0;
	int j = 0, t = 0;
	while(i < a && j < b)
	{
		if(v1[i] < v2[j])
		{
			v3[t] = v1[i];
			t++;
			i++;
		}
		else
		{
			v3[t] = v2[j];
			t++;
			j++;
		}
	}
	if(i < a)
		for(; i < a; i++, t++)
			v3[t] = v1[i];
	if(j < b)
		for(; j < b; j++, t++)
			v3[t] = v2[j];

	cout<<v3[(a + b - 1)/2]<<endl;
}