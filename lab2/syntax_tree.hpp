
#include <iostream>
#include <vector>
#include "ast.hpp"

class Syntax_Node
{
	public:
        Expression *data;
        Syntax_Node *left;
        Syntax_Node *right;
		bool is_nullable;
		std::vector<int> f;
		std::vector<int> l;
		Syntax_Node(Expression *_data)
		{
			is_nullable = false;
			data = _data;
			left = nullptr;
			right = nullptr;
		}
};

class Syntax_Tree
{
	public:
		Syntax_Node *root;
		std::vector<std::vector<int>> follow_pos;
		Syntax_Tree() {root = nullptr;}
		~Syntax_Tree() {}

		void set_root(Syntax_Node *node, Syntax_Node **r)
		{
			Syntax_Node *buf = (*r);
			(*r) = node;
			(*r)->left = buf;
		}

		void concat_str(std::string &s)
		{
			for (int i = 0; i < s.size() - 1; i++)
			{
				if(s[i] != '|' && s[i+1] != '|'  && s[i+1] != '+'  && s[i] != '.' && s[i+1] != '.' && s[i] != '(' && s[i+1] != ')')
				{
					s.insert(i+1, ".");
				}
			}
		}

		void parse_string(std::string &s, Syntax_Node **cur)
		{
			int f,l;
			Syntax_Node **r = cur;
			concat_str(s);
			std::cout << s << "\n";
                        	for (int i = 0; i < s.size(); i++)
                        	{
								if (s[i] == '(')
								{
									f = i;
                               		int j = i+1;
									int q_1 = 1, q_2 = 0;
									while (q_1 != q_2)
									{
										if (s[j] == '(')
										{
											q_1++;
										}
										else if (s[j] == ')')
										{
											q_2++;
										}
										j++;
									}
									l = j - 1;
                                	Syntax_Node *p_node = nullptr;
                                	std::string buf = s.substr(f + 1, l-f-1);
									std::cout << buf << "\n";
                                	parse_string(buf, &p_node);
                                			if ((*cur) == nullptr)
                                			{
                                        			*cur = p_node;
                                			}
                                			else
                                			{
                                                                (*cur)->right = p_node;
                                                                cur = &((*cur)->right);
                                			}
							i = l;
						}
						else if (s[i] == '|')
						{
							//std::cout << "SYMBOL: " << s[i] << "\n";
							Syntax_Node *or_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
							set_root(or_node, r);
							cur = &(*r);
						}
						else if (s[i] == '.')
						{
							//std::cout << "SYMBOL: " << s[i] << "\n";
							Syntax_Node *c_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
							if (s[i-1] == ')')
							{
									if ((*cur)->data->value() == ".")
									{
										set_root(c_node, cur);
										//cur = &(*r);
									}
									else
									{
										set_root(c_node, r);
										cur = &(*r);
									}
							}
							else if((*cur)->data->value() != "|")
							{
								set_root(c_node, cur);
								//cur = &(*r);
							}
							else
							{
								(*cur)->right = c_node;
								cur = &((*cur)->right);
								//std::cout << "HERE:" << (*cur)->data->value() << "\n";
							}
						}
						else if (s[i] == '+')
						{
							Syntax_Node *p_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
							set_root(p_node, cur);
						}
					    else if(s[i] != ')')
						{

                                                          	Syntax_Node *a_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
																			if (*cur == nullptr)
																			{
																				*cur = a_node;
																			}
																			else if((*cur)->data->value() == "." || (*cur)->data->value() == "|" || (*cur)->data->value() == "+")
																			{
																				std::cout << "SYMBOL: " << s[i] << "\n";
																				(*cur)->right = a_node;
																				cur = &((*cur)->right);
																			}
																			else
																			{
																				(*r)->right = a_node;
																				cur = &(*r);
																				//r = &((*r)->right);
																			}
							}
							std::cout << i+1 << " ITERATION:\n";
							putTree(*r, 0);
						}

    }

    void copy_f_vectors(Syntax_Node **ptr, Syntax_Node **left, Syntax_Node **right)
    {
    	for (int i = 0; i < (*left)->f.size(); i++)
    	{
    		(*ptr)->f.push_back((*left)->f[i]);
    	}
    	for (int i = 0; i < (*right)->f.size(); i++)
    	{
    		(*ptr)->f.push_back((*right)->f[i]);
    	}
    }

    void copy_l_vectors(Syntax_Node **ptr, Syntax_Node **left, Syntax_Node **right)
    {
    	for (int i = 0; i < (*left)->l.size(); i++)
    	{
    		(*ptr)->l.push_back((*left)->l[i]);
    	}
    	for (int i = 0; i < (*right)->l.size(); i++)
    	{
    		(*ptr)->l.push_back((*right)->l[i]);
    	}
    }

    void set_node(Syntax_Node **ptr, int ind)
    {
    	std::string s = (*ptr)->data->value();
    	if (s == "|")
    	{
    		if ((*ptr)->left->is_nullable || (*ptr)->right->is_nullable)
    		{
    			(*ptr)->is_nullable = true;
    		}
    		copy_f_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		copy_l_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    	}
    	else if (s == ".")
    	{
    		//N - set
    		if ((*ptr)->left->is_nullable && (*ptr)->right->is_nullable)
    		{
    			(*ptr)->is_nullable = true;
    		}
    		// F - set
    		if ((*ptr)->left->is_nullable)
    		{
    			copy_f_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		}
    		else
    		{
    			for (int i = 0; i < (*ptr)->left->f.size(); i++)
    			{
    				(*ptr)->f.push_back((*ptr)->left->f[i]);
    			}
    		}
    		//L - set
    		if ((*ptr)->right->is_nullable)
    		{
    			copy_l_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		}
    		else
    		{
    			for (int i = 0; i < (*ptr)->right->l.size(); i++)
    			{
    				(*ptr)->l.push_back((*ptr)->right->l[i]);
    			}
    		}
    		//FP - set
    		for (int i = 0; i < (*ptr)->left->l.size(); i++)
    		{
    				for (int j = 0; j < (*ptr)->right->f.size(); j++)
    				{
    						follow_pos[(*ptr)->left->l[i] - 1].push_back((*ptr)->right->f[j]);
    				}
    		}
       	}
    	else if (s == "+")
    	{
    		//N - set
    		if ((*ptr)->left->is_nullable)
    		{
    			(*ptr)->is_nullable = true;
    		}
    		//F - set
    		for (int i = 0; i < (*ptr)->left->f.size(); i++)
    		{
    				(*ptr)->f.push_back((*ptr)->left->f[i]);
    		}
    		//L - set
    		for (int i = 0; i < (*ptr)->left->l.size(); i++)
    		{
    				(*ptr)->l.push_back((*ptr)->left->l[i]);
    		}
    		//FP - set
    		for (int i = 0; i < (*ptr)->left->l.size(); i++)
    		{
    				for (int j = 0; j < (*ptr)->left->f.size(); j++)
    				{
    						follow_pos[(*ptr)->left->l[i] - 1].push_back((*ptr)->left->f[j]);
    				}
    		}    		
    	}
    	else if (s == "^")
    	{
    		(*ptr)->is_nullable = true;
    	}
    	else
    	{
    		(*ptr)->f.push_back(ind);
    		(*ptr)->l.push_back(ind);
    	}
    }

    void create_sets(Syntax_Node **ptr, int *ind)
    {
    	if (*ptr)
    	{
    		create_sets(&((*ptr)->left), ind);
    		create_sets(&((*ptr)->right), ind);
    		if ((*ptr)->data->value() != "|" && (*ptr)->data->value() != "+" && (*ptr)->data->value() != ".")
    		{
    			(*ind)++;
    			follow_pos.push_back(std::vector<int>());
    		}
    		set_node(ptr, *ind);
    		std::cout << (*ptr)->data->value() << " " << "N set: " << (*ptr)->is_nullable << " " <<
    		"F set: ";
    		for (auto &c : (*ptr)->f)
    			std::cout << c << " ";
    		std::cout << "L set: ";
    		for (auto &c : (*ptr)->l)
    			std::cout << c << " ";
    		std::cout << "\n";    		 
    	}
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
			s.push_back('$');
			int ind = 0; //index of each a_node in ast
			parse_string(s, &root);
			create_sets(&root, &ind);
			std::cout << "FP-set:\n";
			for (int i = 0; i < follow_pos.size(); i++)
			{
				std::cout << i + 1 << " NODE: ";
				for (int j = 0; j < follow_pos[i].size(); j++)
				{
					std::cout << follow_pos[i][j] << " ";
				}
				std::cout << "\n";
			}
	}
};
