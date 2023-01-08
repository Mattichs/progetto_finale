//@FedericoCognolatto
#ifndef ATTACK_GRID_H
#define ATTACK_GRID_H
#include "../ship/corazzata.h"
#include "../ship/esploratore.h"
#include "../ship/supporto.h"
#include "../ship/ship.h"
#include "grid.hpp"
#include "defense_grid.hpp"
#include <iostream>
class attack_grid : public grid {
    private:
        char matrix[12][12];
       defense_grid& dgrid; 
    public:
        attack_grid(defense_grid& dg);
        bool fire(coords c);
        friend std::ostream& operator <<( std::ostream& os,const attack_grid&);

};
#endif