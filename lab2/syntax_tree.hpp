
#include <iostream>
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
		Syntax_Tree() {root = nullptr;};
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
				if(s[i] != '|' && s[i+1] != '|' && s[i] != '.' && s[i+1] != '.' && s[i] != '(' && s[i+1] != ')')
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
									//std::string b = s.substr(f);
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
							//std::cout << s.substr(f + 1, l-f-1) << "\n";
                                	Syntax_Node *p_node = nullptr;
                                	std::string buf = s.substr(f + 1, l-f-1);
									std::cout << buf << "\n";
                                	parse_string(buf, &p_node);
							//std::cout << p
                                			if ((*cur) == nullptr)
                                			{
                                        			*cur = p_node;
                                			}
                                			else
                                			{
                                                                (*cur)->right = p_node;
                                                                cur = &((*cur)->right);
                                			}
                                			//s = s.substr(l+1);
							i = l;
						}
						else if (s[i] == '|')
						{
							//std::cout << "SYMBOL: " << s[i] << "\n";
							Syntax_Node *a_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
							set_root(a_node, r);
							cur = &(*r);
						}
						else if (s[i] == '.')
						{
							//std::cout << "SYMBOL: " << s[i] << "\n";
							Syntax_Node *a_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
							if (s[i-1] == ')')
							{
									set_root(a_node, r);
									cur = &(*r);
							}
							else if((*cur)->data->value() != "|")
							{
								set_root(a_node, cur);
								//cur = &(*r);
							}
							else
							{
								(*cur)->right = a_node;
								cur = &((*cur)->right);
								//std::cout << "HERE:" << (*cur)->data->value() << "\n";
							}
						}
					    else if(s[i] != ')')
						{

                                                          	Syntax_Node *a_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
																			if (*cur == nullptr)
																			{
																				*cur = a_node;
																			}
																			else if((*cur)->data->value() == "." || (*cur)->data->value() == "|")
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
			parse_string(s, &root);
		}
				};
