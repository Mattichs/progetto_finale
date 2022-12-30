#ifndef GRIDS.H
#define GRIDS.H
#include "ships.h"
#include "ship.h"
#include "grid.hpp"
#include <vector>
#include <iostream>

class defense_grid:public grid{
    private:
        std::vector<corazzata> corazzate;
        std::vector<supporto> navisupp;
        std::vector<esploratore> esploratori;
    public:
        defense_grid( std::vector<corazzata> c, std::vector<supporto> s, std::vector<esploratore> e);
        ship& get_ship(coords c);
       
        friend std::ostream operator <<(const std::ostream& os,const defense_grid&);

};
std::ostream operator <<(const std::ostream& os,const defense_grid&);
class attack_grid:public grid{
    private:
       defense_grid& dgrid; 
    public:
        attack_grid(defense_grid& dg);
        bool fire(coords c);
        friend std::ostream operator <<(const std::ostream& os,const attack_grid&);

};
std::ostream operator <<(const std::ostream& os,const attack_grid&);
#endif