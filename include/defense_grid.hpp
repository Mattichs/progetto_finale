#ifndef DEFENSE_GRID_H
#define DEFENSE_GRID_H
#include "corazzata.h"
#include "esploratore.h"
#include "supporto.h"
#include "ship.h"
#include "grid.hpp"
#include <vector>
#include <iostream>
class defense_grid : public grid {
    private:
        std::vector<corazzata> battleships;
        std::vector<supporto> healers;
        std::vector<esploratore> scouts;
    public:
        defense_grid( std::vector<corazzata>& c, std::vector<supporto>& s, std::vector<esploratore>& e);
        ship& get_ship(coords c);
        bool is_ship(coords c);
        bool fire(coords c);
        coords move(coords c, short i);
        friend std::ostream& operator <<( std::ostream& os,const defense_grid&);

};

#endif