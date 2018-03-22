#include <stdio.h>
#include <stdlib.h>

#include "rb_tree.h"

void insertKeyIntoRBTree(RBTreeNode **root, int key)
{
	RBTreeNode *newNode = malloc(sizeof(RBTreeNode));
	if(newNode == NULL)
	{
		printf("Memory allocation error, could not insert key: %d", key);
		return;
	}
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->color = RED;
	newNode->key = key;

	if(*root == NULL)
	{
		newNode->color = BLACK;
		*root = newNode;
		return;
	}
	else
	{
		RBTreeNode *current = *root;

		while(current != NULL)
		{
			if(key < current->key)
			{
				if(current->left == NULL)
				{
					newNode->parent = current;
					current->left = newNode;
					RBFixup(root, newNode);
					return;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if(current->right == NULL)
				{
					newNode->parent = current;
					current->right = newNode;
					RBFixup(root, newNode);
					return;
				}
				else
				{
					current = current->right;
				}
			}
		}
	}
}

void rightRotate(RBTreeNode **root,RBTreeNode *x)
{
	if(x->left == NULL)
	{
		return;
	}

	RBTreeNode *y = x->left;
	x->left = y->right;

	if(y->right != NULL)
	{
		y->right->parent = x;
	}

	y->parent = x->parent;

	if(x->parent == NULL)
	{
		*root = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->right = x;
	x->parent = y;

	return;
}

void leftRotate(RBTreeNode **root, RBTreeNode *x)
{
	if(x->right == NULL)
	{
		return;
	}

	RBTreeNode *y = x->right;
	x->right = y->left;

	if(y->left != NULL)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;

	if(x->parent == NULL)
	{
		*root = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;

	return;
}

void RBFixup(RBTreeNode **root, RBTreeNode *node)
{
	while(node->parent != NULL && node->parent->color == RED)
	{
		if(node->parent == node->parent->parent->left)
		{
			RBTreeNode *uncle = node->parent->parent->right;

			if(uncle != NULL && uncle->color == RED)
			{
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
	
			else
			{
				if(node == node->parent->right)
				{
					node = node->parent;
					leftRotate(root, node);
				}

				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rightRotate(root, node->parent->parent);
			}
		}
		else if(node->parent == node->parent->parent->right)
		{
			RBTreeNode *uncle = node->parent->parent->left;
			if(uncle != NULL && uncle->color == RED)
			{
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
			{
				if(node == node->parent->left)
				{
					node = node->parent;
					rightRotate(root, node);
				}

				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				leftRotate(root, node->parent->parent);
			}
		}
	}
	if(node->parent == NULL)
	{
		node->color = BLACK;
		*root = node;
	}

	return;
}

void freeTree(RBTreeNode *root)
{
	if(root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}