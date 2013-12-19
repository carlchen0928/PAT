#include <iostream>
using namespace std;

int Max(int a, int b)
{
	return a > b ? a : b;
}

struct node
{
	int data;
	node *left;
	node *right;
	int height;
	node(int data, int height)
	{
		this->data = data;
		this->height = height;
		this->left = NULL;
		this->right = NULL;
	}
};
node *root = NULL;
int n;
int Height(node *t)
{
	if(t == NULL) return 0;
	return t->height;
}

node* leftRotate(node *t)
{
	node *tmp = t->right;
	t->right = t->right->left;
	tmp->left = t;
	t->height = Max(Height(t->left), Height(t->right)) + 1;
	tmp->height = Max(Height(tmp->left), Height(tmp->right)) + 1;
	if(t == root) root = tmp;
	return tmp;
}

node* rightRotate(node *t)
{
	node *tmp = t->left;
	t->left = t->left->right;
	tmp->right = t;
	t->height = Max(Height(t->left), Height(t->right)) + 1;
	tmp->height = Max(Height(tmp->left), Height(tmp->right)) + 1;
	if(t == root) root = tmp;
	return tmp;
}

node* leftRightRotate(node *t)
{
	node *tmp = leftRotate(t->left);
	t->left = tmp;
	return rightRotate(t);
}

node* rightLeftRotate(node *t)
{
	node *tmp = rightRotate(t->right);
	t->right = tmp;
	return leftRotate(t);
}

node *insert(node *cur, int data)
{
	if(!cur)
	{
		cur = new node(data, 1);
		return cur;
	}
	else if(data < cur->data)
	{
		cur->left = insert(cur->left, data);
		if(Height(cur->left) - Height(cur->right) == 2)
		{
			if(data < cur->left->data)
				cur = rightRotate(cur);
			else
				cur = leftRightRotate(cur);
		}
	}
	else
	{
		cur->right = insert(cur->right, data);
		if(Height(cur->right) - Height(cur->left) == 2)
		{
			if(data > cur->right->data)
				cur = leftRotate(cur);
			else
				cur = rightLeftRotate(cur);
		}
	}
	cur->height = Max(Height(cur->left), Height(cur->right)) + 1;
	return cur;
}

int main()
{
	//	freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	node *first;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(i == 0)
		{
			root = new node(tmp, 1);
		}
		else
			insert(root, tmp);
	}
	printf("%d\n", root->data);
	return 0;
}
