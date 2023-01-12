#ifndef ESPLORATORE_H
#define ESPLORATORE_H

#include "ship.h"
#include "../grid/attack_grid.hpp"
#include "../grid/defense_grid.hpp"

class esploratore : public ship {
	public:
		esploratore(asset, coords&);
		esploratore() {}
		void spot(attack_grid& ag,defense_grid& dg,coords& c);
};

#endif