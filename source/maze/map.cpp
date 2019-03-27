#ifndef _MAP_CPP
#define _MAP_CPP

#include<iostream>
#include"../../include/maze/map.hpp"

Map::Map(void)
{
	this->map_size=20;
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
	this->map[ori.x-1][ori.y-1]=type;
}



inline Coordinate Map::GetEntrance(void)
{
	return this->ent;
}



void Map::Print(void)
{
	for(int i=0;i<map_size;i++)
	{
		for(int j=0;j<map_size;j++)
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
	for(int i=0;i<this->map_size;i++)
	{
		for(int j=0;j<this->map_size;j++)
		{
			this->map[i][j]=WALL;
		}
	}
	for(int i=1;i<this->map_size-1;i++)
	{
		for(int j=1;j</*this->map_size-1*/2;j++)
		{
			this->map[i][j]=UNEXPLORED;
		}
	}
	/*for(int i=2;i<this->map_size-2;i++)
	{
		for(int j=2;j<this->map_size-2;j++)
		{
			this->map[i][j]=WALL;
		}
	}*/
	//this->map[map_size-1][map_size-2]=EXIT;
	return {2,2};
}

#endif
