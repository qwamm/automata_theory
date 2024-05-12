#include <iostream>
#include "nodes.h"

ast::ast()
{
	root = nullptr;
}

void ast::del_root()
{
	node *left = root->left, *old = root;
	root->left = nullptr;
	root = left;
}

void ast::add(node *new_node)
{
		if(root == nullptr)
		{
			root = new_node;
		}
		else if (new_node->left == nullptr)
		{
			node *new_root = new_node;
			node *old = root;
			root = new_root;
			root->left = old;
		}
		else
		{
			node *new_root = new_node;
			node *old = root;
			root = new_root;
			node *ptr = root;
			while (ptr->left)
			{
				ptr = ptr->left;
			}
			ptr->left = old;
		}
}

void ast::put_tree(node *ptr, int level)
{
	int i = level;
	if (ptr)
	{
		put_tree(ptr->right, level+1);
		while (i-- > 0)
			std::cout << " ";
		ptr->print_val();
		std::cout << "\n";
		put_tree(ptr->left, level+1);
	}
}
