#include <iostream>
using namespace std;

char s1[10000];
int ascii[257];

int main()
{
//	freopen("a.txt", "r", stdin);
	char c;
	int i = 0;
	scanf("%c", &c);
	while(c != '\n')
	{
		s1[i] = c;
		i++;
		scanf("%c", &c);
	}
	while(scanf("%c", &c) != EOF)
	{
		ascii[c]++;
	}
	for(int i = 0; i < 10000; i++)
	{
		if(ascii[s1[i]] != 0)
			s1[i] = 0;
	}

	for(int i = 0; i < 10000; i++)
	{
		if(s1[i] != 0)
			printf("%c", s1[i]);
	}
	printf("\n");
}