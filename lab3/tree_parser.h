#ifndef AST
#define AST
#include "nodes.h"
#include "robot.h"
#endif
#include "symbol_table.h"

class tree_parser
{
	public:
		symbol_table global;
		symbol_table functions;
		tree_parser() {}
		~tree_parser() {}
		void parse(node *ptr, symbol_table& stab, robot &r);
		int parse_int(node *ptr, symbol_table& stab);
		int parse_bool(node *ptr, symbol_table& stab);
		void check_height(node *func_params, node *call_params);
		void assign_params (node *func_params, node *call_params, symbol_table &local, symbol_table &lglobal);
};
