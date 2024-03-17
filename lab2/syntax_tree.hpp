#include <iostream>

class Syntax_Node
{
	public:
                char data;
                Syntax_Tree *left;
                Syntax_Tree *right;
		Syntax_Node(char c)
		{
			data = c;
		}
};

class Syntax_Tree
{
	private:
		Syntax_Node *root
	public:
		Syntax_Tree() = default;
		Syntax_Tree(char c)
		{
			data = c;
		}
		~Syntax_Tree() {m.clear();}
		void parse_string(const std::string &s, int first, int last, Syntax_Node *cur)
		{
                        for (int i = first; i < last; i++)
                        {
                                if (s[i] == '(')
                                {
                                        std::string s_2 = s.substr(i+1);
                                        int j = s_2.find_first_of(')');
                                }
                                if (s[i] != '#' && s[i] != '.' && s[i] != '^' && s[i] != '|' && s[i] != '+')
                                {
                                        Syntax_Node *a_node = new Syntax_Tree('.');
                                        a_node->left = new Syntax_Node(s[i]);
                                        if (cur == nullptr)
                                        {
                                                cur = a_node;
                                        }
                                        else
                                        {
                                                cur->right = a_ndoe;
                                                cur = cur->right;
                                        }
                                }
                        }
		}
		void create_ast(const std::string &s)
		{
			parse_string(s, 0, s.size()-1, root);
		}
};
