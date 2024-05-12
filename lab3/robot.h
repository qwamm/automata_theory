#include <iostream>
#include <vector>
#include <utility>
#define FREE 1
#define OBST 2
#define EXIT 3

class robot
{
	public:
		virtual int UP() = 0;
		virtual int DOWN() = 0;
		virtual int RIGHT() = 0;
		virtual int LEFT() = 0;
		virtual std::vector<std::string> VISION() = 0;
		virtual std::string VOICE() = 0;
		virtual void print_field() = 0;
};

// class cell_robot : public interface
// {

// };

// dfs для программы поиска выхода из произвольного лабиринта

// class maze_interface по желанию
// {

// };

// class maze
// {
// 	public:
// 		void look_for_obstacle_between_two_points() {

// 		}
// };

class cell
{
	public:
		int type;
		std::string password;
		cell (int type)
		{
			this->type = type;
		}
		~cell() {}
};

class cell_robot : public robot
{
	public:
		std::vector<std::vector<cell*>> maze;
		std::pair<int,int> coordinats;
		int UP() override {}
		int DOWN() override {}
		int RIGHT() override {}
		int LEFT() override {}
		std::vector<std::string> VISION() override {}
		std::string VOICE() override {}
		cell_robot(std::vector<std::string> maze)
		{
			std::pair<int,int> exit_coordinats;
			for (int i = 0; i < maze.size(); i++)
			{
				std::vector<cell*> t;
				this->maze.push_back(t);
				for (int j = 0; j < maze[i].size(); j++)
				{
					if (maze[i][j] == '#')
					{
						cell *c = new cell(OBST);
						this->maze[i].push_back(c);
					}
					else if (maze[i][j] == '@')
					{
						cell *c = new cell(EXIT);
						this->maze[i].push_back(c);
						exit_coordinats = std::make_pair(i,j);
					}
					else if (maze[i][j] == '^' || maze[i][j] == 'v' || maze[i][j] == '>' || maze[i][j] == '<')
					{
						cell *c = new cell(FREE);
						coordinats.first = i;
						coordinats.second = j;
						this->maze[i].push_back(c);
					}
					else
					{
						cell *c = new cell(FREE);
						this->maze[i].push_back(c);
					}
				}
			}
			for (int i = -1; i < 1; i++)
			{
				for (int j = -1; j < 1; j++)
				{
					if (exit_coordinats.first + i < this->maze.size() && exit_coordinats.second + j < this->maze[exit_coordinats.first + i].size())
					{
							this->maze[exit_coordinats.first + i][exit_coordinats.second + j]->password = "avra kadavra";
					}
				}
			}
		}
		~cell_robot() {}
		void print_field()
		{
			for (int i = 0; i < maze.size(); i++)
			{
				for (int j = 0; j < maze[i].size(); j++)
				{
					if (i == coordinats.first && j == coordinats.second)
					{
							std::cout << "^";
					}
					else if (maze[i][j]->type == OBST)
					{
						std::cout << "#";
					}
					else if (maze[i][j]->type == EXIT)
					{
						std::cout << "@";
					}
					else
					{
						std::cout << "0";
					}
				}
				std::cout << "\n";
			}
		}
};
