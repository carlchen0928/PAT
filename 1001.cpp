#include <iostream>
#include <int>
#include <sstream>
using namespace std;

int main()
{
	
	int a,b;
	cin>>a>>b;
	int c = a + b;
	intstream strStream;  
	strStream<<c;			//int转int的方法！
	int s = strStream.str();

	for(int i = s.size() - 3; i > 0 && s[i - 1] != '-'; i -= 3)
		s.insert(i, ",");

	cout<<s<<endl;
}