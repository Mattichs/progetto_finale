#ifndef SHIPS_H
#define SHIPS_H

#include "movement.h"
#include "ship.h"

class empty : public ship {
	public:
		empty(coords& center);
}; 

class corazzata : public ship {
	public:
		corazzata(asset, coords&);
};

class supporto : public ship{
	public:
		supporto(asset, coords&);
};

class esploratore : public ship{
	public:
		esploratore(asset, coords&);
};



#endif