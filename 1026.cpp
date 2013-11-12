#include <stdio.h>
#include <stdlib.h>
#include <int.h>
#include <malloc.h>

#define N 10000
#define K 100

typedef struct
{
	char arrtime[9];
	int playingtime;
	char is_vip;
}player; //size of player: 9+4+1=14B

typedef struct
{
	char opentime[9];  //�Ӵ˿̿���������ӵĿ���ʱ��
	int usedtimes;
	char is_vip;
}table;

player players[N+1];
table tables[K+1];
int table_num, vip_table_num;

int waiting_minutes(char arrtime[], char sertime[])
{
	int i, minutes = 0;
	minutes += (sertime[3] - arrtime[3]) * 10 + (sertime[4] - arrtime[4]);
	minutes += ((sertime[0] - arrtime[0]) * 10 + (sertime[1] - arrtime[1])) * 60;
	i = (sertime[6] - arrtime[6]) * 10 + sertime[7] - arrtime[7]; 
	if(i >= 30)
		minutes++;
	else if(i < -30)
		minutes--;
	return minutes;
}

char *add(char time_str[], int minutes)
{
	int h, m;
	m = ((time_str[0] - '0') * 10 + time_str[1] - '0') * 60 \
		+ (time_str[3] - '0') * 10 + time_str[4] - '0';
	m += minutes;
	h = m / 60;
	m = m % 60;
	time_str[0] = h / 10 + '0';
	time_str[1] = h % 10 + '0';
	time_str[3] = m / 10 + '0';
	time_str[4] = m % 10 + '0';
	return time_str;
}

int calc_sec(char time_str[])  // ��һ��ʱ���ַ���ת�����루��00:00:00��ʼ��ʱ��
{
	int s;
	s = (time_str[6] - '0') * 10 + time_str[7] - '0';
	s += (time_str[3] - '0') * 600 + (time_str[4] - '0') * 60;
	s += (time_str[0] - '0') * 36000 + (time_str[1] - '0') * 3600;
	return s;
}

int is_early_than(char time1[], char time2[])
{
	int s1, s2;
	s1 = calc_sec(time1);
	s2 = calc_sec(time2);
	if(s1 <= s2)  // ��������
		return 1;
	else
		return 0;
}

int is_closed(char time_str[])
{
	int last = 21 * 3600, s;
	s = calc_sec(time_str);
	if(s < last)
		return 0;
	else
		return 1;
}


int get_a_table(table tables[], int table_num, char time_now[])
{
	int i;
	for(i = 1; i <= table_num; i++)
		if(is_early_than(tables[i].opentime, time_now))
			return i;
	return 0;
}

int get_earliest_table(table tables[], int table_num)
{
	int i, num = 1;
	char earlistime[9] = "21:00:00";
	for(i = 1; i <= table_num; i++)
		if(!is_early_than(earlistime, tables[i].opentime))
		{
			strcpy(earlistime, tables[i].opentime);
			num = i;
		}
		return num;
}

int get_a_vip_table(table tables[], int table_num, char time_now[])
{
	int i;
	for(i = 1; i <= table_num; i++)
		if(is_early_than(tables[i].opentime, time_now) && tables[i].is_vip == 'Y')
			return i;
	return 0;
}


// �ӵ�ǰ�±�cur_index��ʼ����players[]���������ң�����ʱ��time_before֮ǰ���ܲ����ҵ�һ��vip player
// �ҵ��˾ͷ���1���������vip player����cur_index�ϣ�������Ųһλ�����򷵻�0
int get_a_vip_player(player players[], int pairs, int cur_index, char time_before[])
{
	int found = 0, i, j;
	player p;
	for(i = cur_index + 1; i <= pairs; i++)
	{
		if(!is_early_than(players[i].arrtime, time_before))
			break;
		if(players[i].is_vip == 'Y')
		{
			found = 1;
			p = players[i];
			for(j = i; j > cur_index; j--)
				players[j] = players[j - 1];
			players[cur_index] = p;
			break;
		}
	}
	return found;
}

int cmp(const void *a, const void *b)
{
	int i;
	player *c, *d;
	c = (player *)a;
	d = (player *)b;
	for(i = 0; i < 9; i++)
		if((c->arrtime)[i] != (d->arrtime)[i])
			return ((c->arrtime)[i]) - ((d->arrtime)[i]);
	return 0;
}


int main()
{
	int i, j, pairs, num, vip_num, playingtime, is_vip;
	char time_str[9];
	scanf("%d", &pairs);
	i = 1;
	while(i <= pairs)
	{
		scanf("%s%d%d", &time_str, &playingtime, &is_vip);
		if(playingtime > 120)
			playingtime = 120;
		if(is_vip)
		{
			strcpy(players[i].arrtime, time_str);
			players[i].playingtime = playingtime;
			players[i].is_vip = 'Y';
		}
		else
		{
			strcpy(players[i].arrtime, time_str);
			players[i].playingtime = playingtime;
			players[i].is_vip = 'N';
		}
		i++;
	}
	qsort(&(players[1]), pairs, sizeof(player), cmp);

	scanf("%d%d", &table_num, &vip_table_num);
	for(i = 1; i <= table_num; i++)
	{
		tables[i].usedtimes = 0;
		tables[i].is_vip = 'N';
		strcpy(tables[i].opentime, "08:00:00");
	}
	for(i = 1; i <= vip_table_num; i++)
	{
		scanf("%d", &j);
		tables[j].is_vip = 'Y';
	}

	//��ʼ����
	for(i = 1; i <= pairs; i++)
	{
		if(is_closed(players[i].arrtime))
			break;
		num = get_a_table(tables, table_num, players[i].arrtime);
		vip_num = get_a_vip_table(tables, table_num, players[i].arrtime);
		if(num > 0)  //��ʾ���п�����
		{
			if(players[i].is_vip == 'Y' && vip_num > 0) //�����vip player�����п�vip table
			{
				tables[vip_num].usedtimes++;
				strcpy(tables[vip_num].opentime, players[i].arrtime);
				add(tables[vip_num].opentime, players[i].playingtime);
				printf("%s %s %d\n", players[i].arrtime, players[i].arrtime, 0);
			}
			else
			{
				tables[num].usedtimes++;
				strcpy(tables[num].opentime, players[i].arrtime);
				add(tables[num].opentime, players[i].playingtime);
				printf("%s %s %d\n", players[i].arrtime, players[i].arrtime, 0);
			}
		}
		else if(num == 0)  //û�п����ˣ���ǰ����˱���Ҫ����
		{
			num = get_earliest_table(tables, table_num);
			if(is_closed(tables[num].opentime))
				break;
			if(tables[num].is_vip == 'N') // ��ǰ������vip��
			{
				tables[num].usedtimes++;
				printf("%s %s %d\n", players[i].arrtime, tables[num].opentime, \
					waiting_minutes(players[i].arrtime, tables[num].opentime));
				add(tables[num].opentime, players[i].playingtime);
			}
			else  // ��ǰ��������vip��
			{
				if(players[i].is_vip == 'Y')  // ��ǰplayer������vip player
				{
					tables[num].usedtimes++;
					printf("%s %s %d\n", players[i].arrtime, tables[num].opentime, \
						waiting_minutes(players[i].arrtime, tables[num].opentime));
					add(tables[num].opentime, players[i].playingtime);
				}
				else  // ��ǰplayer����vip player
				{
					get_a_vip_player(players, pairs, i, tables[num].opentime);
					tables[num].usedtimes++;
					printf("%s %s %d\n", players[i].arrtime, tables[num].opentime, \
						waiting_minutes(players[i].arrtime, tables[num].opentime));
					add(tables[num].opentime, players[i].playingtime);
				}
			}
		}
	}
	for(i = 1; i <= table_num; i++){
		printf("%d", tables[i].usedtimes);		
		if(i != table_num)
			printf(" ");
	}
	return 0;
}

