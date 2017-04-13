#pragma once
#include <iostream>
#include <cmath>

class Tree
{
public:
	Tree() 
	{
		_root = NULL;  
	};

	void Add(int value); 
	void Show(); 

private:
	class Node 
	{
	public:
		Node()
		{
			x = NULL;
			left = NULL;
			right = NULL;
		}
		int x; 
		Node *left, *right; 
	};
	Node *_root; 

	void print_tree(Node *p, int level); 
};

void Tree::Add(int value) 
{
	if (_root == NULL) 
	{
		Node *node = new Node;
		node->x = value;
		node->left = NULL;
		node->right = NULL;
		_root = node;
	}
	else 
	{
		Node *tmpNode = new Node;
		tmpNode->x = value; 
		Node *currentNode = _root; 

		bool fl = false; 
		while (!fl) 
		{
			if ((!currentNode->left) && (value <= currentNode->x)) 
			{
				currentNode->left = tmpNode; 
				fl = true; 
			}
			else if ((currentNode->left) && (value <= currentNode->x)) 
			{
				currentNode = currentNode->left; 
			}
			else if ((!currentNode->right) && (value > currentNode->x)) 
			{
				currentNode->right = tmpNode;
				fl = true;
			}
			else if ((currentNode->right) && (value > currentNode->x))
			{
				currentNode = currentNode->right;
			}
		}

	}
}

void Tree::Show() 
{
	print_tree(_root, 0); 
}

void Tree::print_tree(Node *p, int level) 
{
	if (p)
	{
		print_tree(p->right, level + 1);     
		for (int i = 0; i < level; i++)
		{
			printf("   ");
		}
		printf("%i\n", p->x);               
		print_tree(p->left, level + 1);    
	}
}