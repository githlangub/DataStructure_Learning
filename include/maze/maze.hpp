#ifndef _MAZE_HPP
#define _MAZE_HPP

#include"map.hpp"
#include"../coordinate.hpp"

class Maze
{
	public:
		Maze(void);
		Maze(Map );
		~Maze();

		void path(void);
	private:
		Coordinate Explore(Coordinate );

		Map map;
		Coordinate cur;
};

#endif
