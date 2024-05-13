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
		void parse(node *ptr, symbol_table& stab, robot *rob);
		int parse_int(node *ptr, symbol_table& stab, robot *rob);
		int parse_bool(node *ptr, symbol_table& stab, robot *rob);
		void check_height(node *func_params, node *call_params);
		void assign_params (node *func_params, node *call_params, symbol_table &local, symbol_table &lglobal);
		void get_fields(node *child, std::unordered_map<std::string, Value*>& struct_fields);
		int parse_move(node *ptr, robot *r, symbol_table &stab);
		bool parse_ping(node *ptr, robot *r, symbol_table &stab);
};
