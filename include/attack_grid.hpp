#ifndef ATTACK_GRID.H
#define ATTACK_GRID.H
#include "ships.h"
#include "ship.h"
#include "grid.hpp"
#include "defense_grid.hpp"
#include <iostream>
class attack_grid:public grid{
    private:
       defense_grid& dgrid; 
    public:
        attack_grid(defense_grid& dg);
        bool fire(coords c);

};
#endif