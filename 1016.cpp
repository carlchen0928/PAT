#include <iostream>
#include <map>
#include <vector>
#include <int>
#include <algorithm>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int r = 24;

struct aCall
{
	int month;
	int day;
	int hour;
	int minute;
	int status;
	aCall(int mo, int d, int h, int m, int s) : month(mo), day(d), hour(h), minute(m), status(s) {}
};

int rate[r];
map<int, vector<aCall>> m;

bool cmp(const aCall &a1, const aCall &a2)
{
	if(a1.month < a2.month)	return true;
	else if(a1.month > a2.month) return false;
	else if(a1.day < a2.day) return true;
	else if(a1.day > a2.day) return false;
	else if(a1.hour < a2.hour) return true;
	else if(a1.hour > a2.hour) return false;
	else if(a1.minute < a2.minute) return true;
	else return false;
}

int compute_money(const char *name, aCall a1, aCall a2)
{
	aCall tmp = a1;
	int result = 0;
	int totalTime = 0;
	while (tmp.day < a2.day || tmp.hour < a2.hour || tmp.minute < a2.minute)
	{
		result += rate[tmp.hour];
		tmp.minute++;
		totalTime++;
		if(tmp.minute == 60)
		{
			tmp.minute = 0;
			tmp.hour++;
			if(tmp.hour == 24)
			{
				tmp.hour = 0;
				tmp.day++;
			}
		}
	}
	printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", a1.day, a1.hour, a1.minute, a2.day, a2.hour, a2.minute, totalTime, result/100.0);
	return result;
}

int main()
{
	//freopen("a.txt", "r", stdin);

	for(int i = 0; i < r; i++)
		scanf("%d", &rate[i]);
	
	int count;
	scanf("%d", &count);
	char name[30];
	char status[10];
	int month, day, hour, minute;
	for(int i = 0; i < count; i++)
	{
		scanf("%s", &name);
		scanf("%02d:%02d:%02d:%02d", &month, &day, &hour, &minute);
		scanf("%s", &status);
		aCall a(month, day, hour, minute, status);
		if(m.find(name) != m.end())
			m[name].push_back(a);
		else
		{
			vector<aCall> tmp;
			tmp.push_back(a);
			m.insert(make_pair(name, tmp));
		}
		memset(name, 0, sizeof(name)/sizeof(char));
		memset(status, 0, sizeof(status)/sizeof(char));
	}
	
	for(map<int, vector<aCall>>::iterator it = m.begin(); it != m.end(); it++)
	{
		sort(it->second.begin(), it->second.end(), cmp);
		vector<aCall> tmp = it->second;
		bool flag = true;
		int total = 0;
		for(vector<aCall>::iterator vit = tmp.begin(); vit != tmp.end() && (vit + 1) != tmp.end(); vit++)
		{
			if(vit->status != "on-line") continue;
			if((vit + 1)->status != "off-line") continue;
			if(flag) 
			{
				printf("%s %02d\n", it->first.c_str(), vit->month);
				flag = false;
			}
			total += compute_money(it->first.c_str(), *vit, *(vit + 1));
			vit++;
		}
		if(!flag)
			printf("Total amount: $%.2f\n", total/100.0);

	}

}

//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include<int.h>
//#include<vector>
//#include<map>
//using namespace std;
//const int HOURS=24;
//const int NAME=21;
//typedef struct Record{
//	char name[NAME];
//	int mou;
//	int dd;
//	int hh;
//	int mm;
//	char line[10];
//}Record;
//typedef struct Res{
//	float money;
//	int last_time;
//}Res;
//int compare_name(const void *a ,const void *b){
//	int tmp=strcmp(((Record*)a)->name,((Record *)b)->name);
//	if(tmp==0){
//		if(((Record*)a)->mou!=((Record *)b)->mou)
//			return ((Record*)a)->mou-((Record *)b)->mou;
//		if(((Record*)a)->dd!=((Record *)b)->dd)
//			return ((Record*)a)->dd-((Record *)b)->dd;
//		if(((Record*)a)->hh!=((Record *)b)->hh)
//			return ((Record*)a)->hh-((Record *)b)->hh;
//		if(((Record*)a)->mm!=((Record *)b)->mm)
//			return ((Record*)a)->mm-((Record *)b)->mm;
//	}
//	else
//		return tmp;
//}
//void compute_money(Record *r1,Record *r2,int *rate, Res *res){
//	Record r;
//	r.dd=r1->dd;
//	r.hh=r1->hh;
//	r.mm=r1->mm;
//	res->money=0;
//	res->last_time=0;
//	while(r.dd<r2->dd||r.hh<r2->hh||r.mm<r2->mm){
//		res->money+=rate[r.hh];
//		res->last_time++;
//		r.mm++;
//		if(r.mm>=60){
//			r.mm=0;
//			r.hh++;
//			if(r.hh>=24){
//				r.hh=0;
//				r.dd++;
//			}
//		}
//	}
//	res->money/=100;
//}
//int check_ok(Record *r,int index,int n){
//	char pname[NAME];
//	int i,flag=0,has=0;
//	strcpy(pname,r[index].name);
//	for(i=index;i<n;i++){
//		if(strcmp(r[i].name,pname)==0){
//			if(r[i].line[1]=='n'){
//				flag=1;
//			}
//			else if(r[i].line[1]=='f'&&1==flag){
//				flag=0;
//				has=1;
//			}
//		}
//		else
//			break;
//	}
//	return has;
//}
//int main()
//{
//	int rate[HOURS];
//	int i,n;
//	for(i=0;i<HOURS;i++)
//		scanf("%d",&rate[i]);
//	scanf("%d",&n);
//	Record *r=new Record [n];
//	for(i=0;i<n;i++){
//		scanf("%s",r[i].name);
//		scanf("%d:%d:%d:%d",&r[i].mou,&r[i].dd,&r[i].hh,&r[i].mm);
//		scanf("%s",r[i].line);
//	}
//	qsort(r,n,sizeof(Record),compare_name);
//	if(n>0){
//		i=0;
//		while(i<n){
//			int has=check_ok(r,i,n);
//			char pname[NAME];
//			if(1==has){
//				printf("%s %02d\n",r[i].name,r[i].mou);
//				strcpy(pname,r[i].name);
//				int flag=0;
//				float t_money=0;
//				Record rn;
//				while(strcmp(pname,r[i].name)==0){
//					if(r[i].line[1]=='n'){
//						rn.dd=r[i].dd;
//						rn.hh=r[i].hh;
//						rn.mm=r[i].mm;
//						flag=1;
//					}
//					else if(r[i].line[1]=='f'&&1==flag){
//						flag=0;
//						printf("%02d:%02d:%02d %02d:%02d:%02d",rn.dd,rn.hh,rn.mm,r[i].dd,r[i].hh,r[i].mm);
//						Res res;
//						compute_money(&rn,&r[i],rate,&res);
//						printf(" %d $%.2f\n",res.last_time,res.money);
//						t_money+=res.money;
//
//					}
//					i++;
//				}
//				printf("Total amount: $%.2f\n",t_money);
//			}
//			else
//				i++;
//		}
//	}
//	return 0;
//}