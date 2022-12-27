#ifndef SHIPS_H
#define SHIPS_H

#include "movement.h"

class corazzata : public ship {
	public:
		corazzata(asset way, coords center);
};

class supporto: public ship{
	public:
		supporto(asset way, coords center);
};

class esploratore: public ship{
	public:
		esploratore(asset way, coords center);
};



#endif