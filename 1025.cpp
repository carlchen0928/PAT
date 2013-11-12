#include <int>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct stu
{
	int reg;
	int score;
	int final_rank;
	int location_num;
	int local_rank;
	stu(int r, int s, int ln, int f = 0, int lr = 0): reg(r), score(s), final_rank(f), location_num(ln), local_rank(lr) {}
};

bool cmp(const stu &s1, const stu &s2)
{
	if(s1.score > s2.score) return true;
	else if(s1.score < s2.score) return false;
	else return s1.reg < s2.reg;
}

void statistic_local(vector<stu> &local)
{
	sort(local.begin(), local.end(), cmp);
	local[0].local_rank = 1;
	for(int i = 1; i < local.size(); i++)
	{
		if(local[i].score == local[i - 1].score)
			local[i].local_rank = local[i - 1].local_rank;
		else
			local[i].local_rank = i + 1;
	}
}

void statistic_final(vector<stu> &final)
{
	sort(final.begin(), final.end(), cmp);
	final[0].final_rank = 1;
	for(int i = 1; i < final.size(); i++)
	{
		if(final[i].score == final[i - 1].score)
			final[i].final_rank = final[i - 1].final_rank;
		else
			final[i].final_rank = i + 1;
	}
}

vector<vector<stu>> v;
int main()
{
//	fstream cin("a.txt");
	int a;
	int i = 0;
	cin>>a;
	while (i < a)
	{
		vector<stu> tmp;
		int t;
		cin>>t;
		int reg;
		int score;
		while (t--)
		{
			cin>>reg>>score;
			stu s(reg, score, i + 1);
			tmp.push_back(s);
		}
		i++;
		v.push_back(tmp);
	}
	vector<stu> total;
	for(int i = 0; i < v.size(); i++)
	{
		statistic_local(v[i]);
		total.insert(total.end(), v[i].begin(), v[i].end());
	}
	statistic_final(total);
	cout<<total.size()<<endl;
	for(int i = 0; i < total.size(); i++)
		cout<<total[i].reg<<" "<<total[i].final_rank<<" "<<total[i].location_num<<" "<<total[i].local_rank<<endl;
}