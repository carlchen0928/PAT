//1027 20:40
#include<iostream>
#include<vector>
using namespace std;
char ra[15]="0123456789ABC";
vector<int> a[3];
void tenToNum(int order,int x)
{
	int i=0,j;
	if(x==0)
		a[order].push_back(0);
	else {
		while(x){
			a[order].push_back(x%13);
			x=x/13;		
		}
	}


}

void print(int order)
{
	int i;
	for(i=a[order].size()-1;i>=0;i--){
		cout<<ra[a[order][i]];
	}
}

int main()
{
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	tenToNum(0,r);
	tenToNum(1,g);
	tenToNum(2,b);

	cout<<"#";

	if(a[0].size()==1)
		cout<<"0";
	print(0);
	if(a[1].size()==1)
		cout<<"0";
	print(1);
	if(a[2].size()==1)
		cout<<"0";
	print(2);



	return 0;

}