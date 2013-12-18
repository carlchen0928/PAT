#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
//	node *parent;
	int height;
	/* data */
};

node* leftRotate(node *t)
{
	node *tmp = t->right;
	t->right = t->right->left;
	tmp->left = t;
	t->height = Max(t->left->height, t->right->height);
	tmp->height = Max(tmp->left->height, tmp->right->height);
	return tmp;
}