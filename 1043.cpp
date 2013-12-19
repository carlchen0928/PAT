#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int *arr;
int size;
vector<int> v;

struct node
{
	node *left;
	node *right;
	int data;
	node()
	{
		left = right = NULL;
	}
};

int find_index(int low, int high, bool mirror)
{
	int i;
	if(mirror)
	{
		for(i = low + 1; i <= high; i++)
			if(arr[low] > arr[i])
				return i;
	}
	else
	{
		for(i = low + 1; i <= high; i++)
			if(arr[low] <= arr[i])
				return i;
	}
	return i;
}

bool checkBST(int low, int high, int index, bool mirror)
{
	int rootValue = arr[low];
	if(mirror)
	{
		for(int i = low + 1; i <= index - 1; i++)
			if(arr[i] < rootValue) return false;
		for(int i = index; i <= high; i++)
			if(arr[i] >= rootValue) return false;
	}
	else
	{
		for(int i = low + 1; i <= index - 1; i++)
			if(arr[i] >= rootValue) return false;
		for(int i = index; i <= high; i++)
			if(arr[i] < rootValue) return false;
	}
	return true;
}

bool isBST(int low, int high)
{
	if(low > high)
		return true;
	int rootValue = arr[low];
	int i;
	for(i = low + 1; i <= high; i++)
		if(arr[i] >= rootValue)
			break;
	for(int j = i; j <= high; j++)
		if(arr[j] < rootValue)
			return false;
	return isBST(low + 1, i - 1) && isBST(i, high);
}

bool rebuild_tree(node * &root, int low, int high, bool mirror)
{
	if(low > high)
		return true;
	node *n = new node;
	n->data = arr[low];
	root = n;
	int index = find_index(low, high, mirror);
	if(!checkBST(low, high, index, mirror))
		return false;
	return rebuild_tree(root->left, low + 1, index - 1, mirror) && rebuild_tree(root->right, index, high, mirror);
}

void post_travel(node *root)
{
	if(root == NULL)
		return;
	post_travel(root->left);
	post_travel(root->right);
	v.push_back(root->data);
}

int main()
{
//	fstream cin("a.txt");
	cin>>size;
	arr = new int[size];
	for(int i = 0; i < size; i++)
		cin>>arr[i];

	bool flag;
	bool bst = isBST(0, size - 1);
	node *root = new node;
	if(bst)
	{
		flag = rebuild_tree(root, 0, size - 1, false);
		post_travel(root);
	}
	else
	{
		flag = rebuild_tree(root, 0, size - 1, true);
		post_travel(root);
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		for (int i = 0; i < v.size(); i++)
		{
			if(i == 0) cout<<v[i];
			else cout<<" "<<v[i];
		}
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;
}