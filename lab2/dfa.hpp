#include <iostream>
#include "syntax_tree.hpp"

struct State;

struct Transition
{
		State *to;
		Transition(State *_to)
		{
			to = _to;
		}
};

struct State
{
		int s_num;
		std::string s;
		std::vector <Transition*> tr;
		State(std::string _s, int _num)
		{
			s_num = _num;
			s = _s;
		}
};

class DFA
{
	private:
		std::vector<State*> StartStates;
		std::vector<State*> InterStates;
		State *EndState;
	public:
		DFA() = default;
		~DFA() {}
		void create(std::string &s)
		{
			//creating of abstract syntax tree
        		Syntax_Tree *t = new Syntax_Tree();
        		t->create_ast();
			DStates.reserve(t->follow_pos.size());

			//start states definition
			for (int i = 0; i < t->root.f.size(); i++)
			{
				State *start = new State(t->root.f[i].s, t->root.l[0].n);
				StartStates.push_back(start);
			}

			//end state definition
			EndState = new State(t->root.l[0].s, t->root.l[0].n);

			for (int i = 0; i <  t->root.f.size(); i++)
			{
				for (int j = 0; j < t->follow_pos(t->root.f[i]).size(); j++)
				{
					State *next = new State(t->follow_pos(t->root.f[i]).s,
					t->follow_pos(t->root.f[i]).n);
					Transition *tr = new Transition(next);
					st
				}
			}
		}
};
