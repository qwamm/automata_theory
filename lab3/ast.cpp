#include <iostream>
#include "nodes.h"

ast::ast()
{
	root = nullptr;
}

void ast::add(node *new_node)
{
	/*if (root != nullptr && root->left == nullptr)
	{
		root->left = new_node;
	}
	else if (root != nullptr && root->right == nullptr)
	{
		root->right = new_node;
	}*/
	//else
	//{
		if(root == nullptr)
		{
			root = new_node;
		}
		else
		{
			//std::cout << "MARKER\n";
			node *new_root = new_node;
			node *old = root;
			root = new_root;
			root->left = old;
			//this->put_tree(old, 0);
		}
	//}
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
