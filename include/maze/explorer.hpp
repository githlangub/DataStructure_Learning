#ifndef _EXPLORER_HPP
#define _EXPLORER_HPP

#include"../coordinate.hpp"
#include"../stack.hpp"

class Explorer
{
	public:
		Explorer(Coordinate );
		~Explorer()=default;

		Coordinate Explore(void);   //
		void Walk(Coordinate );   //
	private:
		Coordinate cur;
		Stack<unsigned> path;
		//Stack<Coordinate> path;
}

#endif
