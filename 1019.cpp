#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b;
	cin>>a>>b;

	if(a == 0)
	{
		cout<<"Yes"<<endl<<0<<endl;
		return 0;
	}

	vector<long long> v;
	while (a != 0)
	{
		v.push_back(a % b);
		a /= b;
	}
	bool flag = true;
	int tmp = v.size()/2;
	while (tmp--)
	{
		if(v[tmp] != v[v.size() - tmp - 1])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		if(i == 0)
			cout<<v[i];
		else
			cout<<" "<<v[i];
	}
	cout<<endl;
}