#include <iostream>
#include <vector>
#include "ast.hpp"

struct Vertex
{
	int n;
	std::string s;
	Vertex (int _n, std::string _s)
	{
		n = _n;
		s = _s;
	}
};

class Syntax_Node
{
	public:
        Expression *data;
        Syntax_Node *left;
        Syntax_Node *right;
		bool is_nullable;
		std::vector<Vertex> f;
		std::vector<Vertex> l;
		Syntax_Node(Expression *_data)
		{
			is_nullable = false;
			data = _data;
			left = nullptr;
			right = nullptr;
		}
		~Syntax_Node()
		{
			delete data;
			left = nullptr;
			right = nullptr;
		}
};

class Syntax_Tree
{
	public:
		Syntax_Node *root;
		std::vector<std::vector<Vertex>> follow_pos;
		Syntax_Tree() {root = nullptr;}

		void del_tree(Syntax_Node *root)
		{
		 	if (root)
		 	{
		 		if (root->left) del_tree(root->left);
		 		if (root->right) del_tree(root->right);
		 		delete root;
		 	}
		}

		~Syntax_Tree()
		 {
		 	del_tree(root);
		 }

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
				if (s[i] == '{' && s[i+4] == '}')
				{
						i +=4;
				}
				else if((s[i] != '|' || (s[i-1] == '#' && s[i] == '|')) && s[i+1] != '{' &&  s[i] != '#' && s[i+1] != '|'  && s[i+1] != '+'  && (s[i] != '.' || (s[i-1] == '#' && s[i] == '.')) && s[i+1] != '.' &&
				 (s[i] != '(' || (s[i-1] == '#' && s[i] == '(')) && (s[i+1] != ')'))
				{
					s.insert(i+1, ".");
				}
			}
		}

		bool parse_string(std::string &s, Syntax_Node **cur)
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
										if (s[j] == '(' && s[j-1] != '#')
										{
											q_1++;
										}
										else if (s[j] == ')' && s[j-1] != '#')
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
                                	//std::cout << l +1 << "\n";
                                	if ((*cur) == nullptr)
                                	{
                                        	*cur = p_node;
                                	}
                                	/*else if (l + 1 < s.size() && s[l + 1] == '*')
                                	{
                                		(*r)->right = p_node;
                                        cur = &((*r)->right);
                                	}*/
                                	else
                                	{
                                            (*cur)->right = p_node;
                                            cur = &((*cur)->right);
                                	}
									i = l;
								}
								else if (s[i] == '|')
								{
									Syntax_Node *or_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
									or_node->data->is_metasymbol = true;
									set_root(or_node, r);
									cur = &(*r);
								}
								else if (s[i] == '.')
								{
									Syntax_Node *c_node = new Syntax_Node(new Symbol(std::string(1, s[i])));
									c_node->data->is_metasymbol = true;
									if (s[i-1] == ')' && s[i-2] != '#')
									{
										if ((*cur)->data->value() == "." && (*cur)->data->is_metasymbol)
										{
											set_root(c_node, cur);
										}
										else
										{
											set_root(c_node, r);
											cur = &(*r);
										}
									}
									else if((*cur)->data->value() != "|" || !(*cur)->data->is_metasymbol)
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
									p_node->data->is_metasymbol = true;
									set_root(p_node, cur);
								}
								else if (s[i] == '{')
								{
									std::string token;	
									//std::cout << s[i+1] << "\n";													
									if ((s[i+1] >= 48 && s[i+1] <= 57) && s[i+2] == ',' && (s[i+1] >= 48 && s[i+1] <= 57) && s[i+3] > s[i+1] && s[i+4] == '}')
									{
										token += s.substr(i, 5);
										//std::cout << token << "\n";
									}
									else
									{
										throw std::runtime_error("wrong regex");
									}
									Syntax_Node *r_node = new Syntax_Node(new Symbol(token));
									r_node->data->is_metasymbol = true;
									set_root(r_node, cur);
									i += 5;
								}
					    	else if(s[i] != ')')
							{
								std::string token;
								if (s[i] == '#')
								{
									if (i < s.size() - 1)
										i++;
									else
										throw std::runtime_error("wrong regex");
								}
								token.push_back(s[i]);
                              	Syntax_Node *a_node = new Syntax_Node(new Symbol(token));
								if (*cur == nullptr)
								{
									*cur = a_node;
								}
								else if(((*cur)->data->value() == "." || (*cur)->data->value() == "|" || (*cur)->data->value() == "+") && (*cur)->data->is_metasymbol)
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
					return true;
    }

    //NEED TO FIX
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

    //NEED TO FIX
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

    //NEED TO USE UNOREDERED_SET
    void set_node(Syntax_Node **ptr, int ind)
    {
    	std::string s = (*ptr)->data->value();
    	if (s == "|" && (*ptr)->data->is_metasymbol)
    	{
    		//N - set
    		if ((*ptr)->left->is_nullable || (*ptr)->right->is_nullable)
    		{
    			(*ptr)->is_nullable = true;
    		}
    		//F - set
    		copy_f_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		//L - set
    		copy_l_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    	}
    	else if (s == "." && (*ptr)->data->is_metasymbol)
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
    						follow_pos[(*ptr)->left->l[i].n - 1].push_back((*ptr)->right->f[j]);
    				}
    		}
       	}
    	else if (s == "+" && (*ptr)->data->is_metasymbol)
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
    						follow_pos[(*ptr)->left->l[i].n - 1].push_back((*ptr)->left->f[j]);
    				}
    		}    		
    	}
    	else if (s == "^")
    	{
    		(*ptr)->is_nullable = true;
    	}
    	else if (s[0] == '{' && s[s.size() - 1] == '}')
    	{
    		//N - set
    		if ((*ptr)->left->is_nullable == true)
    		{
    			(*ptr)->is_nullable = true;
    		}
    		//F - set
    		if (s[i+1] > 0)
    		{
    			for (int i = 0; i < (*ptr)->left->f.size(); i++)
    			{
    						(*ptr)->f.push_back((*ptr)->left->f[i]);
    			}
    		}
    		else if (s[i+1] == 0)
    		{
    			copy_f_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		}
    		//L - set
    		if (s[i+1] > 0)
    		{
    			for (int i = 0; i < (*ptr)->left->l.size(); i++)
    			{
    				(*ptr)->l.push_back((*ptr)->left->l[i]);
    			}
    		}
    		else if (s[i+1] == 0)
    		{
    			copy_l_vectors(ptr, &((*ptr)->left), &((*ptr)->right));
    		}
    		//FP - set
    		for (int i = 0; i < (*ptr)->left->l.size(); i++)
    		{
    				for (int j = 0; j < (*ptr)->left->f.size(); j++)
    				{
    						follow_pos[(*ptr)->left->l[i].n - 1].push_back((*ptr)->left->f[j]);
    				}
    		}    		
    	}
    	else
    	{
    		(*ptr)->f.push_back(Vertex(ind, (*ptr)->data->value()));
    		(*ptr)->l.push_back(Vertex(ind, (*ptr)->data->value()));
    	}
    }

    void create_sets(Syntax_Node **ptr, int *ind, std::vector<Vertex>& states)
    {
    	if (*ptr)
    	{
    		create_sets(&((*ptr)->left), ind, states);
    		create_sets(&((*ptr)->right), ind, states);
    		if (((*ptr)->data->value() != "|" && (*ptr)->data->value() != "+" && (*ptr)->data->value() != ".") ||
    		 (*ptr)->data->is_metasymbol == false)
    		{
    			(*ind)++;
    			follow_pos.emplace_back();
    			states.push_back(Vertex(*ind, (*ptr)->data->value()));
    		}
    		set_node(ptr, *ind);
    		std::cout << (*ptr)->data->value() << " " << "N set: " << (*ptr)->is_nullable << " " <<
    		"F set: ";
    		for (auto &c : (*ptr)->f)
    			std::cout << c.n << " " << c.s << " ";
    		std::cout << "L set: ";
    		for (auto &c : (*ptr)->l)
    			std::cout << c.n << " " << c.s << " ";
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


	std::vector<Vertex> create_ast(std::string &s)
	{
			s.push_back('$');
			int ind = 0; //index of each a_node in ast
			parse_string(s, &root);
			std::vector<Vertex> states;
			create_sets(&root, &ind, states);
			std::cout << "FP-set:\n";
			for (int i = 0; i < follow_pos.size(); i++)
			{
				std::cout << i + 1 << " NODE: ";
				for (int j = 0; j < follow_pos[i].size(); j++)
				{
					std::cout << follow_pos[i][j].n << " " << follow_pos[i][j].s << " ";
				}
				std::cout << "\n";
			}
			std::cout << "STATES:\n";
			for (int i =0; i < states.size(); i++)
			{
				std::cout << states[i].n << " " << states[i].s << "\n";
			}
			return states;
	}
};
