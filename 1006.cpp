#include <stdio.h>
#include <int.h>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	

	int num;
	while (scanf("%d", &num) != EOF)
	{
		
		char earlest[20];
		char lastest[20];
		char thisone[20];
		int h1, h2, m1, m2, s1, s2;
		scanf("%s%d%*c%d%*c%d %d%*c%d%*c%d", &thisone, &h1, &m1, &s1, &h2, &m2, &s2);
		int ear = 3600 * h1 + 60 * m1 + s1;
		int lat = 3600 * h2 + 60 * m2 + s2;
		memcpy(earlest, thisone, sizeof(thisone)/sizeof(char));
		memcpy(lastest, thisone, sizeof(thisone)/sizeof(char));
		num--;
		while (num--)
		{
			memset(thisone, 0, sizeof(thisone)/sizeof(char));
			scanf("%s%d%*c%d%*c%d %d%*c%d%*c%d", &thisone, &h1, &m1, &s1, &h2, &m2, &s2);
			int tmp1 = 3600 * h1 + 60 * m1 + s1;
			int tmp2 = 3600 * h2 + 60 * m2 + s2;
			if(ear > tmp1) 
			{
				//earlest[0] = '\0';
				memset(earlest, 0, sizeof(earlest)/sizeof(char));
				memcpy(earlest, thisone, sizeof(thisone)/sizeof(char));
				ear = tmp1;
			}
			if(lat < tmp2)
			{
				//lastest[0] = '\0';	//清空字符数组，也可以用下面一种方法，更为保险
				memset(lastest, 0, sizeof(lastest)/sizeof(char));
				memcpy(lastest, thisone, sizeof(thisone)/sizeof(char));
				lat = tmp2;
			}
		}

		printf("%s %s\n", earlest, lastest);
	}
}


