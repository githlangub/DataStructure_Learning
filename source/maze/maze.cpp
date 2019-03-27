#ifndef _MAZE_CPP
#define _MAZE_CPP

#include<iostream>
#include"../../include/maze/maze.hpp"
#include"../../include/maze/map.hpp"
#include"map.cpp"
#include"../../include/stack.hpp"

Maze::Maze(void)
{
	this->cur=this->map.GetEntrance();
	this->map.Print();
}



Maze::Maze(Map map)
{
	this->map=map;
	this->cur=this->map.GetEntrance();
}



Maze::~Maze()
{
	;
}



void Maze::path(void)
{
	//Stack<Coordinate> path;
	Stack<unsigned> path;
	while(this->map.Read(cur)!=EXIT)
	{
		this->map.Write(FOOTPRINT,cur);
		Coordinate next=Explore(cur);
		if(next.x!=0&&next.y!=0)
		{
			//path.Push(this->cur);
			path.Push(this->cur.x);
			path.Push(this->cur.y);
			this->cur=next;
		}
		else
		{
			try
			{
				//this->cur=path.Pop();
				this->cur.y=path.Pop();
				this->cur.x=path.Pop();
			}
			catch(unsigned )
			{
				throw "No valid way in this maze!";
				break;
			}
		}
	}
	std::cout<<"Success!"<<std::endl;
	this->map.Print();
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
