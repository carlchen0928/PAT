#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
//	fstream cin("a.txt");
	int a, b;
	vector<long long> nc;
	vector<long long> np;
	cin>>a;
	long long tmp;
	for(int i = 0; i < a; i++)
	{
		cin>>tmp;
		nc.push_back(tmp);
	}
	cin>>b;
	for(int i = 0; i < b; i++)
	{
		cin>>tmp;
		np.push_back(tmp);
	}
	sort(nc.begin(), nc.end());
	sort(np.begin(), np.end());
	long long getback = 0;
	int i = 0, j = 0;
	while (i < nc.size() && j < np.size() && nc[i] < 0 && np[j] < 0)
	{
		getback += nc[i] * np[j];
		i++; j++;
	}
	i = nc.size() - 1;
	j = np.size() - 1;
	while (i >= 0 && j >= 0 && nc[i] > 0 && np[j] > 0)
	{
		getback += nc[i] * np[j];
		i--; j--;
	}
	cout<<getback<<endl;
}