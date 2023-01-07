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
        void insert_ship(ship& s);
        bool is_ship(coords c);
        bool fire(coords c);
        void move(coords c, ship& s);
        ship& get_ship(coords c);
        friend std::ostream& operator <<( std::ostream& os,  defense_grid& dg);

};

#endif