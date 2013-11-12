#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int city, pathNum, start, dis;
int *teams;
int path[501][501] = {0};
bool isVisited[501] = {false};

int mini = 999999999;
int current = 0;
int miniNum = 0;
int currentTeam = 0;
int totalTeam = 0;
vector<int> v;

void DFS(int begin);

int main()
{
	//fstream cin("a.txt");

	cin>>city>>pathNum>>start>>dis;
	teams = new int[city];
	for(int i = 0; i < city; i++)
		cin>>teams[i];
	for(int i = 0; i < pathNum; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		path[a][b] = c;
		path[b][a] = c;
	}
	v.push_back(start);
	isVisited[start] = true;
	DFS(start);
	isVisited[start] = false;
	v.pop_back();

	cout<<miniNum<<" "<<totalTeam<<endl;

}

void DFS(int begin)
{
	if(begin == dis)
	{
		for(int i = 0; i < v.size() - 1; i++)
		{
			current += path[v[i]][v[i + 1]];
			currentTeam += teams[v[i]];
		}
		currentTeam += teams[v[v.size() - 1]];

		if(current < mini)
		{
			mini = current;
			totalTeam = currentTeam;
			miniNum = 1;
		}
		else if(current == mini)
		{
			miniNum++;
			totalTeam >currentTeam ? totalTeam = totalTeam : totalTeam = currentTeam;
		}
		currentTeam = current = 0;
	}
	else
	{
		for(int i = 0; i < 501; i++)
		{
			if(!isVisited[i] && path[begin][i] != 0)
			{
				isVisited[i] = true;
				v.push_back(i);
				DFS(i);
				v.pop_back();
				isVisited[i] = false;
			}
		}
	}
}