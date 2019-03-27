#ifndef _MAZE_CPP
#define _MAZE_CPP

#include<iostream>
#include"../../include/maze/maze.hpp"
#include"../../include/maze/map.hpp"
#include"../../include/stack.hpp"

Maze::Maze(void)
{
	this->cur=this->map.GetEntrance();
}



//Maze::Maze(Map map)



Maze::~Maze()
{
	;
}



void Maze::path(void)
{
	Stack<Coordinate> path;
	while(this->map.Read(cur)!=EXIT)
	{
		Coordinate next=Explore(cur);
		if(next.x!=0&&next.y!=0)
		{
			this->map.Write(FOOTPRINT,cur);
			path.Push(this->cur);
			this->cur=next;
		}
		else
		{
			try
			{
				this->cur=path.Pop();
			}
			catch(unsigned )
			{
				throw "No valid way in this maze!";
				break;
			}
		}
	}
	std::cout<<"Success!"<<std::endl;
}



Coordinate Maze::Explore(Coordinate cur)
{
	Coordinate west{cur.x-1,cur.y},
		   north{cur.x,cur.y+1},
		   east{cur.x+1,cur.y},
		   south{cur.x,cur.y-1},
		   none{0,0};
	if(this->map.Read(west)==UNEXPLORED||this->map.Read(west)==EXIT)
	{
		return west;
	}
	else if(this->map.Read(north)==UNEXPLORED||this->map.Read(north)==EXIT)
	{
		return north;
	}
	else if(this->map.Read(east)==UNEXPLORED||this->map.Read(east)==EXIT)
	{
		return east;
	}
	else if(this->map.Read(south)==UNEXPLORED||this->map.Read(south)==EXIT)
	{
		return south;
	}
	else
	{
		return none;
	}
}

#endif
