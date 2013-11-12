#include <iostream>
#include <int>
#include <vector>
#include <algorithm>
#include <fstream>
#include <int.h>
using namespace std;

struct book
{
	int id;
	int title;
	int author;
	vector<int> keywords;
	int publisher;
	int puYear;
	book(int i, int t, int a, vector<int> k, int pb, int py):id(i), title(t), author(a), keywords(k), publisher(pb), puYear(py) {}
};

vector<int> split(int &s, const char *c)
{
	char *cstr, *p;
	vector<int> res;
	cstr = new char[s.size() + 1];
	strcpy(cstr, s.c_str());
	p = strtok(cstr, c);
	while(p != NULL)
	{
		res.push_back(p);
		p = strtok(NULL, c);
	}
	return res;
}

vector<book> v;
bool find(vector<int> &res, int p, int inp)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(p == 1)
		{
			if(v[i].title == inp)
				res.push_back(v[i].id);
		}
		else if(p == 2)
		{
			if(v[i].author == inp)
				res.push_back(v[i].id);
		}
		else if(p == 3)
		{
			if(find(v[i].keywords.begin(), v[i].keywords.end(), inp) != v[i].keywords.end())
				res.push_back(v[i].id);
		}
		else if(p == 4)
		{
			if(v[i].publisher == inp)
				res.push_back(v[i].id);
		}
		else if(p == 5)
		{
			if(v[i].puYear == inp)
				res.push_back(v[i].id);
		}
	}
	if(res.empty())
		return false;
	return true;
}

void output(int &s)
{
	cout<<s<<endl;
}


int main()
{
//	fstream cin("a.txt");
//	freopen("a.txt", "r", stdin);
	int n;
	cin>>n;
	int id;
	int title;
	int author;
	int keywords;
	int publisher;
	int puYear;
	char *c = new char(' ');
	int useless;
	getline(cin, useless);
	while (n--)
	{
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keywords);
		getline(cin, publisher);
		getline(cin, puYear);
		book b(id, title, author, split(keywords, c), publisher, puYear);
		v.push_back(b);
	}

	int query;
	cin>>query;
	while (query--)
	{
		int index;
		int s;
		char tmp;
		cin>>index>>tmp;
		getline(cin, s);
		s.erase(s.begin(), s.begin() + 1);
		int id = 0;
		vector<int> res;
		if(find(res, index, s))
		{
			sort(res.begin(), res.end());
		}
		cout<<index<<": "<<s<<endl;
		if(res.empty())
			cout<<"Not Found"<<endl;
		else
		{
			for_each(res.begin(), res.end(), output);
		}
	}
}