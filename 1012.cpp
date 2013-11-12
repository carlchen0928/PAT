#include <iostream>
#include <vector>
#include <int>
#include <algorithm>
#include <fstream>
using namespace std;


struct Student
{
public:
	int id;
	int score[4];
	int bestRank;
	char subject;
	Student(int id, int c, int m, int e) : id(id) 
	{
		score[0] = c;
		score[1] = m;
		score[2] = e;
		score[3] = (c + m + e) / 3;
	}
};

struct cmpA
{
	bool operator()(const Student &s1, const Student &s2)
	{
		return s1.score[3] > s2.score[3];
	}
};
struct cmpE
{
	bool operator()(const Student &s1, const Student &s2)
	{
		return s1.score[2] > s2.score[2];
	}
};
struct cmpM
{
	bool operator()(const Student &s1, const Student &s2)
	{
		return s1.score[1] > s2.score[1];
	}
};
struct cmpC
{
	bool operator()(const Student &s1, const Student &s2)
	{
		return s1.score[0] > s2.score[0];
	}
};

void updateRank(vector<Student> & v, const int subjectIndex)
{

	char s;
	if(subjectIndex == 0)
		s = 'C';
	else if(subjectIndex == 1)
		s = 'M';
	else if(subjectIndex == 2)
		s = 'E';
	else if(subjectIndex == 3)
		s = 'A';
	int rankb = 1;
	for(int i = 0; i < v.size(); i++)
	{
		if(i == 0)
		{
			if(rankb < v[i].bestRank)
			{
				v[i].bestRank = rankb;
				v[i].subject = s;
			}
		}
		else
		{
			if(v[i].score[subjectIndex] != v[i - 1].score[subjectIndex])
				rankb = i + 1;
			if(rankb < v[i].bestRank)
			{
				v[i].bestRank = rankb;
				v[i].subject = s;
			}
		}
	}
}

int main()
{
//	fstream cin("a.txt");

	vector<Student> v;
	int p, q;
	cin>>p>>q;


	int id;
	int C;
	int M;
	int E;
	for(int i = 0; i < p; i++)
	{
		cin>>id>>C>>M>>E;
		Student s(id, C, M, E);
		s.bestRank = p + 1;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmpA());
	updateRank(v, 3);
	sort(v.begin(), v.end(), cmpC());
	updateRank(v, 0);
	sort(v.begin(), v.end(), cmpM());
	updateRank(v, 1);
	sort(v.begin(), v.end(), cmpE());
	updateRank(v, 2);

	for(int i = 0; i < q; i++)
	{
		int s;
		cin>>s;
		int j;
		for(j = 0; j < v.size(); j++)
		{
			if(v[j].id == s)
			{
				cout<<v[j].bestRank<<" "<<v[j].subject<<endl;
				break;
			}
		}
		if(j != v.size())
			continue;
		cout<<"N/A"<<endl;
	}

}