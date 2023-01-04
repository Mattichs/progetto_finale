#ifndef ATTACK_GRID_H
#define ATTACK_GRID_H
#include "corazzata.h"
#include "esploratore.h"
#include "supporto.h"
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
        friend std::ostream& operator <<( std::ostream& os,const attack_grid&);

};
#endif