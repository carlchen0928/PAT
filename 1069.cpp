#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int n;
set<int> s;
vector<int> getNumbers(int tmp)
{
	vector<int> res(2);
	vector<int> v(4);
	v[0] = tmp % 10;
	v[1] = (tmp/10) % 10;
	v[2] = (tmp/100) % 10;
	v[3] = (tmp/1000) % 10;
	sort(v.begin(), v.end(), less<int>());
	res[1] = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
	sort(v.begin(), v.end(), greater<int>());
	res[0] = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
	return res;
}

int main()
{
	cin>>n;
	while (true)
	{
		vector<int> res = getNumbers(n);
		int tmp = res[0] - res[1];
		if(s.find(tmp) != s.end())
			break;
		cout<<right<<setw(4)<<setfill('0')<<res[0]<<" - ";
		cout<<right<<setw(4)<<setfill('0')<<res[1]<<" = ";
		cout<<right<<setw(4)<<setfill('0')<<tmp<<endl;
		if(tmp == 0)
			break;
		s.insert(tmp);
		n = tmp;
	}
}