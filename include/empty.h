#ifndef EMPTY_H
#define EMPTY_H

#include "movement.h"
#include "ship.h"

class empty : public ship {
	public:
		empty(coords&);
};

#endif