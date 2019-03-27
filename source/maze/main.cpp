#include<iostream>
#include"../../include/maze/map.hpp"
#include"../../include/maze/maze.hpp"
using namespace std;

int main()
{
	try
	{
		Maze maze1;
		maze1.path();
		//Map map1;
		//map1.Print();
	}
	catch(const char* warn)
	{
		cout<<warn<<endl;
	}
	return 0;
}
