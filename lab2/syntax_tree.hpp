#include <iostream>
#include <stack>
#include "ast.hpp"

class Syntax_Node
{
	public:
               	Expression *data;
                Syntax_Node *left;
                Syntax_Node *right;
		Syntax_Node(Expression *_data)
		{
			data = _data;
			left = nullptr;
			right = nullptr;
		}
};

class Syntax_Tree
{
	public:
		Syntax_Node *root;
		std::vector <Syntax_Node*> nodes;
		Syntax_Tree() {root = nullptr;};
		~Syntax_Tree() {}
		void set_root(Syntax_Node *node)
		{
			Syntax_Node *buf = root;
			root = node;
			root->left = buf;
		}
		void parse_string(std::string &s, int first, int last, Syntax_Node **cur)
		{
			int f,l;
			f = s.find_first_of('(');
			if (f == std::string::npos)
			{
				//std::cout << "MARKER\n";
                        	for (int i = first; i < last; i++)
                        	{
						Syntax_Node *a_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
						nodes.push_nack(a_node);
                        	}
				for (int i = 0; i < nodes.size(); i++)
				{
						if (i > 0 && i < nodes.size() -1 && nodes[i]->data->value() == "|")
						{
							nodes[i]->data = new Disjunction(nodes[i-1]->data, nodes[i+1]->data);
							nodes.erase(i+1);
							nodes.erase(i-1);
							
						}
				}
			}
			//return cur;
		}

	void putTree(Syntax_Node *ptr, int level)
	{
		int i = level;
		if (ptr)
		{
			putTree(ptr->right, level + 1);
			while (i-- > 0)
				std::cout << "  ";
			std::cout << ptr->data->value() << "\n";
			putTree(ptr->left, level + 1);
		}
	}


		void create_ast(std::string &s)
		{
			parse_string(s, 0, s.size(), &root);
		}
};
