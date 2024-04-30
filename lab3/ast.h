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

class node
{
	public:
		int operation;
		node *left, *right;
		node(int operation)
		{
			this->operation = operation;
			left = nullptr;
			right = nullptr;
		}
		virtual void print_val() = 0;
		int gettype();
		~node();
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
