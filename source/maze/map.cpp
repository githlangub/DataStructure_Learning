#ifndef _MAP_CPP
#define _MAP_CPP

#include<iostream>
#include"../../include/maze/map.hpp"
#include"../../include/coordinate.hpp"

Map::Map(void)
{
	//生成默认简易地图
	this->side_len=20;   //确定边长
	for(int i=0;i<this->side_len;i++)
	{
		for(int j=0;j<this->side_len;j++)
		{
			this->map[i][j]=WALL;
		}
	}
	for(int i=1;i<this->side_len-1;i++)
	{
		for(int j=1;j<this->side_len-1;j++)
		{
			this->map[i][j]=UNEXPLORED;
		}
	}
	for(int i=2;i<this->side_len-2;i++)
	{
		for(int j=2;j<this->side_len-2;j++)
		{
			this->map[i][j]=WALL;
		}
	}
	this->map[side_len-1][side_len-5]=EXIT;   //确定出口
	this->map[1+1][1+1]=ENTRANCE;	//确定入口
	this->ent={1+1,1+1};

	std::cout<<"A maze map in default type is generated!"<<std::endl;
}



Map::~Map()
{

	std::cout<<"GoodBye!"<<std::endl;
}



inline MapType Map::Read(Coordinate ori)
{
	return this->map[ori.x-1][ori.y-1];
}



inline void Map::Write(MapType type,Coordinate ori)
{
	this->map[ori.x-1][ori.y-1]=type;
}



inline Coordinate Map::GetEntrance(void)
{
	return this->ent;
}



void Map::Print(void)
{
	for(int i=0;i<side_len;i++)
	{
		for(int j=0;j<side_len;j++)
		{
			switch(this->map[i][j])
			{
				case WALL: std::cout<<'#';break;
				case EXIT: std::cout<<'*';break;
				case UNEXPLORED: std::cout<<' ';break;
				case FOOTPRINT: std::cout<<'.';break;
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

#endif
