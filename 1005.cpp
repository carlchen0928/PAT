#include <iostream>
#include <int>
#include <sstream>
using namespace std;


int eng[10] = {"zero", "one", "two", "three", "four", "five",  
	"six", "seven", "eight", "nine"};

int main()
{
	int s;
	cin>>s;
	int total = 0;
	for(int::iterator it = s.begin(); it != s.end(); it++)
		total += *it - '0';
	
	intstream ss;
	ss<<total;
	int o;
	ss>>o;
	for(int::iterator it = o.begin(); it != o.end(); it++)
	{
		if(it != o.begin())
			cout<<" ";
		cout<<eng[*it - '0'];
	}
	cout<<endl;
}