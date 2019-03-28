#ifndef _EXPLORER_CPP
#define _EXPLORER_CPP

#include<iostream>
#include"../../include/maze/explorer.hpp"
#include"../../include/maze/map->hpp"
#include"../../include/coordinate.hpp"
#include"../../include/stack.hpp"

Explorer::Explorer(Coordinate ent)
{
	this->cur=ent;
}



Coordinate Explorer::Explore(void)
{
	//按照西,北,东,南方向依次判断是否可以,是则直接返回坐标
	Coordinate west{cur.x-1,cur.y},
		   north{cur.x,cur.y+1},
		   east{cur.x+1,cur.y},
		   south{cur.x,cur.y-1},
		   none{0,0};
	if(Maze::map->Read(west)==UNEXPLORED||Maze::map->Read(west)==EXIT)
	{
		return west;
	}
	else if(Maze::map->Read(north)==UNEXPLORED||Maze::map->Read(north)==EXIT)
	{
		return north;
	}
	else if(Maze::map->Read(east)==UNEXPLORED||Maze::map->Read(east)==EXIT)
	{
		return east;
	}
	else if(Maze::map->Read(south)==UNEXPLORED||Maze::map->Read(south)==EXIT)
	{
		return south;
	}
	else   //否则,返回{0,0}(地图不存在此坐标)
	{
		return none;
	}
}



void Explorer::Walk(Coordinate next)
{
	if(/*next!={0,0}*/next.x!=0&&next.y!=0)   //需要重载!=
	{
		//path.Push(this->cur);
		path.Push(this->cur.x);
		path.Push(this->cur.y);
		this->cur=next;
		Maze::map->Write(FOOTPRINT,cur);
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
	std::cout<<"Success!"<<std::endl;
	Maze::map->Print();
}

#endif
