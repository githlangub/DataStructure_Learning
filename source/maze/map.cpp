#ifndef _MAP_CPP
#define _MAP_CPP

#include<iostream>
#include"../../include/maze/map.hpp"

Map::Map(void)
{
	this->map_size=10;
	ent=this->GenerateDefault();

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
	this->map[ori.x-1][ori.y-1]==type;
}



inline Coordinate Map::GetEntrance(void)
{
	return this->ent;
}



void Map::Print(void)
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
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



Coordinate Map::GenerateDefault(void)
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(
			   ((i==1||i==8)&&(j!=0&&j!=9))||
			   ((j==1||j==8)&&(i!=0&&i!=9))
			  )
			{
				this->map[i][j]=UNEXPLORED;
			}
			else
			{
				this->map[i][j]=WALL;
			}
		}
	}
	this->map[8][9]=EXIT;
	return {1,1};
}

#endif
