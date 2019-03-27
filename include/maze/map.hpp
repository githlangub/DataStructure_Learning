#ifndef _MAP_HPP
#define _MAP_HPP

#include"../coordinate.hpp"

typedef enum
{
	WALL,EXIT,UNEXPLORED,FOOTPRINT
}MapType;

/*typedef struct
{
	Coordinate lat_ori;
	MapType lat_type;
}Lattice;*/

class Map
{
	public:
		Map(void);
		//MapTest(unsigned );
		~Map();

		MapType Read(Coordinate );
		void Write(MapType ,Coordinate );
		Coordinate GetEntrance(void);
		void Print(void);
	private:
		Coordinate GenerateDefault(void);

		unsigned map_size;
		MapType map[20][20];
		Coordinate ent;
};

#endif

