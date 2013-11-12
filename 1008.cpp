#include <iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;
	int cost = 0;
	int curFloor = 0;
	while (num--)
	{
		int floor;
		cin>>floor;
		int tmp = floor - curFloor;
		cost += tmp > 0 ? 6 * tmp : -4 * tmp;
		cost += 5;
		curFloor = floor;
	}

	cout<<cost<<endl;
}