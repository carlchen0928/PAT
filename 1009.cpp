#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

double *A[2];
map<int, double> result;

int main()
{
	//fstream cin("a.txt");

	int i = 0;
	int N[2];
	while (i < 2)
	{
		cin>>N[i];
		A[i] = new double[2 * N[i]];
		int tmp = 0;;
		while (tmp < 2 * N[i])
		{
			cin>>A[i][tmp];
			tmp++;
		}
		i++;
	}
	

	for(int i = 0; i < 2 * N[0]; i += 2)
	{
		for(int j = 0; j < 2 * N[1]; j += 2)
		{
			double coefficient = A[0][i + 1] * A[1][j + 1];
			int exponent = A[0][i] + A[1][j];
			if(result[exponent] != 0)
				result[exponent] += coefficient;
			else
				result[exponent] = coefficient;
		}
	}

	for(map<int, double>::iterator it = result.begin(); it != result.end(); it++)
	{
		if((*it).second == 0)
			result.erase(it);
	}

	cout<<result.size();
	for(map<int, double>::reverse_iterator rit = result.rbegin(); rit != result.rend(); rit++)
	{
		cout<<" "<<(*rit).first<<" "<<fixed<<setprecision(1)<<(*rit).second;
	}

	return 0;
}