#ifndef SHIPS_H
#define SHIPS_H

#include "movement.h"
#include "ship.h"

//Empty ship
class empty : public ship {
	public:
		empty(coords& center);
}; 

//corazzata can only shoot
class corazzata : public ship {
	public:
		corazzata(asset, coords&);
};

//supporto can move and restore hp of other ships in a square 3x3 from its center
class supporto : public ship{
	public:
		supporto(asset, coords&);
};

//esploratore can move and search for enemy ships in a square 5x5 from its center
class esploratore : public ship{
	public:
		esploratore(asset, coords&);
};



#endif