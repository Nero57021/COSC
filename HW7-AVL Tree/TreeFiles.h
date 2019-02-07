#define TreeFiles
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#pragma once
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

}*root;
class avlTree
{
public:
	int height(Node *);
	int diff(Node *);
	Node *rr_rotation(Node *);
	Node *ll_rotation(Node *);
	Node *lr_rotation(Node *);
	Node *rl_rotation(Node *);
	Node* balance(Node *);
	Node* insert(Node *, int);
	void display(Node *, int);
	void inorder(Node *);
	void preorder(Node *);
	void postorder(Node *);
	avlTree()
	{
		root = nullptr;
	}
};

int avlTree::height(Node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*
* Height Difference
*/
int avlTree::diff(Node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
Node *avlTree::rr_rotation(Node *parent)
{
	Node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
Node *avlTree::ll_rotation(Node *parent)
{
	Node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
* Left - Right Rotation
*/
Node *avlTree::lr_rotation(Node *parent)
{
	Node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
Node *avlTree::rl_rotation(Node *parent)
{
	Node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
Node *avlTree::balance(Node *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
* Insert Element into the tree
*/
Node *avlTree::insert(Node *root, int value)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

/*
* Display AVL Tree
*/
void avlTree::display(Node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

/*
* Inorder Traversal of AVL Tree
*/
void avlTree::inorder(Node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}
/*
* Preorder Traversal of AVL Tree
*/
void avlTree::preorder(Node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	preorder(tree->left);
	preorder(tree->right);

}

/*
* Postorder Traversal of AVL Tree
*/
void avlTree::postorder(Node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << "  ";
}