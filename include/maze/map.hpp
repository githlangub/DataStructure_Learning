#ifndef _MAP_HPP
#define _MAP_HPP

#include"../coordinate.hpp"

typedef enum
{
	WALL,EXIT,ENTRANCE,UNEXPLORED,FOOTPRINT
}MapType;

/*typedef struct
{
	Coordinate lat_ori;
	MapType lat_type;
}Lattice;*/

class Map
{
	public:
		Map(void);   //生成地图
		~Map();

		MapType Read(Coordinate );   //根据坐标返回区域类型
		void Write(MapType ,Coordinate );   //根据坐标改变区域类型
		Coordinate GetEntrance(void);   //查看入口坐标
		void Print(void);   //打印地图
	private:
		unsigned side_len;   //地图边长(统一为正方形)
		MapType map[20][20];   //地图(暂时用二维数组)
		//Lattice* map;   //地图
		Coordinate ent;   //入口
};

#endif

