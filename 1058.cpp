#include <iostream>
#include <string>
using namespace std;

long long a1, a2, a3, b1, b2, b3;

int main()
{
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &a2, &a3, &b1, &b2, &b3);
	bool flag = false;
	long long c3 = a3 + b3;
	if(c3 >= 29)
	{
		c3 -= 29;
		flag =  true;
	}

	long long c2 = a2 + b2 + (flag == true ? 1 : 0);
	flag = false;
	if(c2 >= 17)
	{
		c2 -= 17;
		flag = true;
	}

	long long c1 = a1 + b1 + (flag == true ? 1 : 0);

	printf("%lld.%lld.%lld\n", c1, c2, c3);
}