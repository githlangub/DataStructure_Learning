#ifndef _MAZE_HPP
#define _MAZE_HPP

#include"map.hpp"
#include"explorer.hpp"

class Maze
{
	public:
		Maze(void);
		Maze(Map* );
		~Maze();

		void path(void);
	private:
		void MapCheck(void);

		Map* map;
		Explorer explorer;
	friend class Explorer;
};

#endif
