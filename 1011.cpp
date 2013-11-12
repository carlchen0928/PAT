#include <iostream>
#include <int>
#include <stdio.h>
#include <iomanip>
using namespace std;
#define  N 3
int main()
{
	char res[3]={'W','T','L'};
	char max_res[N];
	int i,j;
	float tmp,sum=1,odd;
	for(i=0;i<N;i++){
		tmp=0;
		for(j=0;j<3;j++){
			cin>>odd;
			if(odd>tmp){
				tmp=odd;
				max_res[i]=res[j];
			}
		}
		sum*=tmp;
	}
	sum=(sum*0.65-1)*2;
	for(i=0;i<N;i++)
		cout<<max_res[i]<<" ";
	cout<<fixed<<setprecision(2)<<sum<<endl;
	//printf("%.2f",sum+0.005);
	return 0;
}