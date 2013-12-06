#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
std::vector<set<int> > v;
std::vector<int> dis;

int main()
{
	cin>>n;
	int tmp;
	int num;
	dis = std::vector<int>(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin>>tmp;
		set<int> s;
		for(int j = 0; j < tmp; j++)
		{
			cin>>num;
			set<int>::iterator it = s.find(num);
			if(it != s.end())
			{
				s.erase(it);
				dis[i]--;
			}
			else
			{
				s.insert(num);
				dis[i]++;
			}
		}
	}
}