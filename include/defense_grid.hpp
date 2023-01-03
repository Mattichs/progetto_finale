#ifndef DEFENSE_GRID.H
#define DEFENSE_GRID.H
#include "ships.h"
#include "ship.h"
#include "grid.hpp"
#include <vector>
#include <iostream>
class defense_grid:public grid{
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
        

};
#endif