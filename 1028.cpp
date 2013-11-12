#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct record
{
	std::vector<int> v;
	record(std::vector<int> vp):v(vp) {}
};

struct cmp
{
	int t;
	cmp(int tp):t(tp) {}
	bool operator()(const record &r1, const record &r2)
	{
		if(r1.v[t - 1] < r2.v[t - 1]) return true;
		else if(r1.v[t - 1] > r2.v[t - 1]) return false;
		else return r1.v[0] < r2.v[0];
	}
};

void output(const record &r)
{
	std::cout<<r.v[0];
	for(int i = 1; i < r.v.size(); i++)
		std::cout<<" "<<r.v[i];
	std::cout<<std::endl;
}

std::vector<record> allRecord;
int main()
{
	//fstream cin("a.txt");
	int a, b;
	std::cin>>a>>b;
	while (a--)
	{
		int m, n, p;
		std::cin>>m>>n>>p;
		std::vector<int> vp;
		vp.push_back(m);
		vp.push_back(n);
		vp.push_back(p);
		record r(vp);
		allRecord.push_back(r);
	}
	sort(allRecord.begin(), allRecord.end(), cmp(b));
	for_each(allRecord.begin(), allRecord.end(), output);
}