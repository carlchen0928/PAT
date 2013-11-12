#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	for(int i = 3; i < n; i += 2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int reverseRadix(int n, int d)
{
	vector<int> v;
	int reverse = n;
	while (reverse != 0)
	{
		int tmp = reverse % d;
		if(tmp != 0)
			v.push_back(tmp);
		for(int i = 0; i < v.size(); i++)
			v[i] *= d;
		reverse /= d;
	}
	int result = 0;
	for(int i = 0; i < v.size(); i++)
		result += v[i] / d;
	return result;
}

int main()
{
	int n, d;
	while (cin>>n)
	{
		if(n < 0)
			break;
		cin>>d;
		int r = reverseRadix(n, d);
		if(isPrime(r) && isPrime(n))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}