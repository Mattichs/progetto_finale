#ifndef ESPLORATORE_H
#define ESPLORATORE_H

#include "movement.h"
#include "ship.h"

class esploratore : public ship{
	public:
		esploratore(asset, coords&);
};

#endif