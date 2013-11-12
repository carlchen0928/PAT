#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


struct item
{
	item(){}
	item(int e, double c)
	{
		this->exp = e;
		this->coef = c;
	}
	int exp;
	double coef;
};
void merge(item *items1, item *items2, int a, int b);
int main()
{
	//fstream cin("a.txt");

	int a,b;
	cin>>a;
	int tmp = a;
	item *items1 = new item[a];
	while (tmp--)
	{
		int exp;
		double coef;
		cin>>exp>>coef;
		item it(exp, coef);
		items1[a - tmp - 1] = it;
	}
	cin>>b;
	tmp = b;
	item *items2 = new item[b];
	while (tmp--)
	{
		int exp;
		double coef;
		cin>>exp>>coef;
		item it(exp, coef);
		items2[b - tmp - 1] = it;
	}

	merge(items1, items2, a, b);
	return 0;
}

void merge(item *items1, item *items2, int a, int b)
{
	vector<item> v;
	int i = 0,j = 0;
	for(;i < a && j < b;)
	{
		if(items1[i].exp > items2[j].exp)
		{
			if(items1[i].coef != 0)
				v.push_back(items1[i]);
			i++;
		}
		else if(items1[i].exp < items2[j].exp)
		{
			if(items2[j].coef != 0)
				v.push_back(items2[j]);
			j++;
		}
		else
		{
			item it(items1[i].exp, items1[i].coef + items2[j].coef);
			if (it.coef != 0)
				v.push_back(it);
			i++;
			j++;
		}
	}

	if(i == a)
	{
		while (j < b)
		{
			if(items2[j].coef != 0)
				v.push_back(items2[j]);
			j++;
		}
	}
	else
	{
		while (i < a)
		{
			if(items1[i].coef != 0)
				v.push_back(items1[i]);
			i++;
		}
	}

	cout<<v.size();
	for (int i = 0; i < v.size(); i++)
	{
		cout<<" "<<v[i].exp<<" "<<fixed<<setprecision(1)<<v[i].coef;
	}
	cout<<endl;
}