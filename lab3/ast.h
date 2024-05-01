#include <cstring>
#define STRN 1 //string token
#define INTN 2 //int token
#define BOOLN 3 //bool token
#define NEGN 4 // -
#define PLUSN 5 // +
#define MULN 6 // *
#define DIVN 7 // /
#define EQUN 8 // ?
#define NOTEQUN 9 // !
#define EXPN 10 // ^
#define LESSN 11 // <
#define GREATERN 12 // >
#define UMINN 13 // -
#define VARN 14 // variable token
#define UNDEFVARN 15 // undef var
#define ASSIGNN 16 //assign to variable
#define ARRASSIGNN 17 // assign to array element
#define BLOCKN 18 //BLOCK <group of sentences> UNBLOCK

class node
{
	public:
		int operation;
		node *left, *right;
                bool inside;
		node(int operation)
		{
			this->operation = operation;
			left = nullptr;
			right = nullptr;
                        inside = false;
		}
                void set_left (node *ptr)
                {
                        this->left = ptr;
                }
                char* copy_str(char *buf)
                {
                        char *new_str = new char[strlen(buf) + 1];
                        int i = 0;
                        for (i = 0; i < strlen(buf); i++)
                        {
                                new_str[i] = buf[i];
                        }
                        new_str[i] = '\0';
                        return new_str;
                }
		virtual void print_val() = 0;
		int gettype();
		~node() {}
};

class ast
{
        public:
                node *root;
                ast();
                ~ast() {}
                void put_tree(node *ptr, int level);
                void add(node *new_node);
};
