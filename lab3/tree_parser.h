#ifndef AST
#define AST
#include "nodes.h"
#endif
#include "symbol_table.h"

class tree_parser
{
	symbol_table stab;
	public:
		tree_parser() {}
		~tree_parser() {}
		void parse(node *ptr);
		int parse_int(node *ptr);
		bool parse_bool(node *ptr);
};
