#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long factor = 1;
	long long count = 0;
	while (n / factor != 0)
	{
		long long low = n % factor;
		long long cur = (n / factor) % 10;
		long long high = n / (factor * 10);
		switch (cur)
		{
		case 0:
			count += high * factor;
			break;
		case 1:
			count += high * factor + low + 1;
			break;
		default:
			count += (high + 1) * factor;
			break;
		}
		factor *= 10;
	}
	cout<<count<<endl;
}