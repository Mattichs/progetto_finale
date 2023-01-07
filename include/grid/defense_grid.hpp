//@FedericoCognolatto
#ifndef DEFENSE_GRID_H
#define DEFENSE_GRID_H
#include "../ship/corazzata.h"
#include "../ship/esploratore.h"
#include "../ship/supporto.h"
#include "../ship/ship.h"
#include "../ship/empty.h"
#include "grid.hpp"
#include <vector>
#include <iostream>
class defense_grid : public grid {
    private:
        ship* matrix[12][12];
        empty water;
    public:
        defense_grid();
        ship& get_ship(coords c);
        void insert_ship(ship& s);
        bool is_ship(coords c);
        bool fire(coords c);
        coords move(coords c, short i);
        std::vector<corazzata> get_battleships();
        std::vector<supporto> get_healers();
        std::vector<esploratore> get_scouts();
        friend std::ostream& operator <<( std::ostream& os,  defense_grid& dg);

};

#endif