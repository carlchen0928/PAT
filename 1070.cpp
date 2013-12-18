#include <iostream>
#include <stdlib.h>
using namespace std;

int n, d;
struct Cake
{
	double amount;
	double price;
	double perPrice;
	/* data */
};
Cake moon[1001];
int comp(const void *a, const void *b)
{
	double tmp = ((Cake *)b)->perPrice - ((Cake *)a)->perPrice;
	if(tmp > 0) return 1;
	else if(tmp < 0) return -1;
	else return 0;
	//printf("aaa\n");
}
int main()
{
//	freopen("a.txt", "r", stdin);
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%lf", &moon[i].amount);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &moon[i].price);
		moon[i].perPrice = moon[i].price / moon[i].amount;
	}
	qsort(moon, n, sizeof(moon[0]), comp);
//	for(int i = 0; i < n; i++)
//		printf("%lf %lf %lf\n", moon[i].amount, moon[i].price, moon[i].perPrice);

	double result = 0.0;
	for(int i = 0; i < n; i++)
	{
		if(d > moon[i].amount)
		{
			result += moon[i].price;
			d -= moon[i].amount;
		}
		else
		{
			result += moon[i].perPrice * d;
			break;
		}
	}
	printf("%.2lf\n", result);
}