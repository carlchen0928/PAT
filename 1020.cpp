#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

int k;
vector<int> post;
vector<int> in;
vector<int> reslut;

struct tree_node
{
	int data;
	tree_node *left;
	tree_node *right;
	tree_node() 
	{
		left = NULL;
		right = NULL;
	}
};
tree_node *root;
 tree_node *preOrder(vector<int>::iterator pBegin, vector<int>::iterator pEnd, vector<int>::iterator iBegin, vector<int>::iterator iEnd, tree_node *root)
{
	if(pBegin == pEnd || iBegin == iEnd)
		return NULL;
	int tmp = *(pEnd - 1);
	root = new tree_node;
	root->data = tmp;
	vector<int>::iterator index = find(iBegin, iEnd, tmp);
	root->left = preOrder(pBegin, pBegin + (index - iBegin), iBegin, index, root->left);
	root->right = preOrder(pBegin + (index - iBegin), pEnd - 1, index + 1, iEnd, root->right);
	return root;
}

 void BSF()
 {
	 queue<tree_node *> q;
	 q.push(root);
	 while (!q.empty())
	 {
		 tree_node *tmp = q.front();
		 q.pop();
		 reslut.push_back(tmp->data);
		 if(tmp->left != NULL) q.push(tmp->left);
		 if(tmp->right != NULL) q.push(tmp->right);
	 }
 }

int main()
{
	//fstream cin("a.txt");
	cin>>k;
	int tmp = k;
	post.push_back(0);
	in.push_back(0);
	while (tmp--)
	{
		int node;
		cin>>node;
		post.push_back(node);
	}
	tmp = k;
	while (tmp--)
	{
		int node;
		cin>>node;
		in.push_back(node);
	}
	root = preOrder(post.begin() + 1, post.end(), in.begin() + 1, in.end(), root);
	BSF();
	for(int i = 0; i < reslut.size(); i++)
	{
		if(i == 0)
			cout<<reslut[i];
		else
			cout<<" "<<reslut[i];
	}
	cout<<endl;
}