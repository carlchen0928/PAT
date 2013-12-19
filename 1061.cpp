#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string s1, s2, s3, s4;

void printWeek(char p)
{
	switch (p - 'A')
	{
	case 0:
		cout<<"MON ";
		break;
	case 1:
		cout<<"TUE ";
		break;
	case 2:
		cout<<"WED ";
		break;
	case 3:
		cout<<"THU ";
		break;
	case 4:
		cout<<"FRI ";
		break;
	case 5:
		cout<<"SAT ";
		break;
	case 6:
		cout<<"SUN ";
		break;
	default:
		break;
	}
}

int main()
{
	cin>>s1>>s2>>s3>>s4;
	int i = 0;
	for(; i < s1.size(); i++)
	{
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			printWeek(s1[i]);
			break;
		}
	}
	for(i++; i < s1.size(); i++)
	{
		if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')))
		{
			if(s1[i] >= '0' && s1[i] <= '9')
				cout<<right<<setw(2)<<setfill('0')<<s1[i];
			else
				cout<<right<<setw(2)<<setfill('0')<<s1[i] - 'A' + 10;
			cout<<':';
			break;
		}
	}
	for(int j = 0; j < s3.size(); j++)
	{
		if(s3[j] == s4[j] && ((s3[j] >= 'A' && s3[j] <= 'Z') || (s3[j] >= 'a' && s3[j] <= 'z')))
		{
			cout<<right<<setw(2)<<setfill('0')<<j<<endl;
			break;
		}
	}
}