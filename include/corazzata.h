#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "movement.h"
#include "ship.h"

class corazzata : public ship {
	public:
		corazzata(asset, coords&);
};

#endif