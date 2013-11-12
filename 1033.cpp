#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

double a, b, c, d;
struct node
{
	double price;
	double dist;
	node(double p, double d): price(p), dist(d) {}
};
vector<node> v;
bool finished = false;
double cost = 0;

bool cmp(const node &n1, const node &n2)
{
	return n1.dist < n2.dist;
}

double fillOrNot(int index, double left)
{
	double fastest = v[index].dist + c * a;
	if(index + 1 < d && (v[index + 1].dist - v[index].dist) > c * a)
	{
		cost += v[index].price * (a - left);
		return fastest;
	}
	else if(index + 1 == d && (b - v[index].dist) > c * a)
	{
		cost += v[index].price * (a - left);
		return fastest;
	}
	/*if(fastest >= b)
	{
		cost += ((b - v[index].dist)/c - left) * v[index].price;
		finished = true;
		return 0.0;
	}*/
	int smallest = index + 1;
	for(int i = index + 1; i < d && v[i].dist < fastest; i++)
		if(v[index].price > v[i].price)
		{
			cost += ((v[i].dist - v[index].dist)/c - left)*v[index].price;
			return fillOrNot(i, 0);
		}
		else if(v[smallest].price > v[i].price)
			smallest = i;
	//如果没有比当前便宜的
	if(fastest >= b)
	{//如果当前可以到终点，直接到
		cost += ((b - v[index].dist)/c - left) * v[index].price;
		finished = true;
		return 0.0;
	}
	else
	{
		cost += (a - left) * v[index].price;
		return fillOrNot(smallest, a - (v[smallest].dist - v[index].dist)/c);
	}
}

int main()
{
//	fstream cin("a.txt");
	cin>>a>>b>>c>>d;
	double tmp1;
	double tmp2;
	for(int i = 0; i < d; i++)
	{
		cin>>tmp1>>tmp2;
		node n(tmp1, tmp2);
		v.push_back(n);
	}
	sort(v.begin(), v.end(), cmp);
	double fastest = fillOrNot(0, 0.0);
	if(v[0].dist != 0)
	{
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	if(finished)
		cout<<fixed<<setprecision(2)<<cost<<endl;
	else
		cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<fastest<<endl;
}