//最长回文子串
//http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html
//想法一：暴力，从头到尾以每个点为中点，向两边扫描。
//想法二：利用LCS（Longgest common substring）问题来解，将字符串逆序，然后求两个串的LCS，之后再比较求得的公共子串原来是否在同一位置，如果在，则此串就是LPS
//想法三：DP
//		Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.
//		P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )
//		P[ i, i ] ← true
//		P[ i, i+1 ] ← ( Si = Si+1 )
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string source;
int l[1001][1001];
//char source[1001];

int main()
{
	
	fstream cin("a.txt");
	getline(cin, source);
	cout<<source<<endl;
	for(int i = 1; i <= source.length() - 1; i++)
	{
		if(source[i - 1] == source[i])
			l[i - 1][i] = 2;
		l[i][i] = 1;
	}

	for(int i  = 1; i <= source.length(); i++)
	{
		for(int j = 1; j <= source.length(); j++)
			cout<<l[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl;
	for(int len = 2; len <= source.length() - 1; len++)
	{
		for(int i = 1; i <= source.length() - len; i++)
		{
			int j = i + len;
			if(source[i - 1] == source[j - 1] && l[i + 1][j - 1] != 0)
				l[i][j] = l[i + 1][j - 1] + 2;
		}
	}

	for(int i  = 1; i <= source.length(); i++)
	{
		for(int j = 1; j <= source.length(); j++)
			cout<<l[i][j]<<" ";
		cout<<endl;
	}
}
