#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100005
struct node
{
	char id[10];
	int v,t,c;
}s[N];
int cmp(const void *a,const void *b)
{
	struct node *x=(struct node *)a;
	struct node *y=(struct node *)b;
	if(x->c!=y->c)return x->c-y->c;
	if(y->v+y->t!=(x->v+x->t))return y->v+y->t-(x->v+x->t);
	if(y->v!=x->v)return y->v-x->v;
	return strcmp(x->id,y->id);
}
int main()
{
	int n,i,l,h;
	while(scanf("%d%d%d",&n,&l,&h)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",s[i].id,&s[i].v,&s[i].t);
			if(s[i].v>=h&&s[i].t>=h)s[i].c=1;
			else
				if(s[i].v>=h&&s[i].t>=l&&s[i].t<h)s[i].c=2;
				else
					if(s[i].v>=l&&s[i].v<h&&s[i].t>=l&&s[i].t<h&&s[i].v>=s[i].t)s[i].c=3;
					else
						if(s[i].v>=l&&s[i].t>=l)s[i].c=4;
						else
							s[i].c=0;
		}
		qsort(s,n,sizeof(struct node),cmp);
		for(i=0;i<n;i++)
			if(s[i].c!=0)break;
		printf("%d\n",n-i);
		for(;i<n;i++)
			printf("%s %d %d\n",s[i].id,s[i].v,s[i].t);

	}
}