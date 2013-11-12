#include <iostream>
#include <vector>
#include <string>

typedef struct Student
{
	char name[20];
	char gender;
	char id[20];
	int g;
}Student;

bool ValidGrade (int g)
{  
	if(g >= 0 && g <= 100)  
		return true;  
	else return false;  
} 

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Student female,male;
		female.g=-1;
		male.g=101;
		Student tmp;

		while (n--)
		{

			scanf("%s %c %s %d",&tmp.name,&tmp.gender,&tmp.id,&tmp.g);
			if(tmp.gender=='F'&&tmp.g>female.g)
				female=tmp;
			else if(tmp.gender=='M'&&tmp.g <male.g)
				male=tmp;
		}
		if(ValidGrade(female.g))
			printf("%s %s\n",female.name,female.id);
		else printf("Absent\n");
		if(ValidGrade(male.g))
			printf("%s %s\n",male.name,male.id);
		else printf("Absent\n");
		if(ValidGrade(female.g)&&ValidGrade(male.g))
			printf("%d\n",female.g-male.g);
		else printf("NA\n");
	}
	return 0;
}
