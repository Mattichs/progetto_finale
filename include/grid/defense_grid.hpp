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
#include <set>

class defense_grid : public grid {
    private:
        ship* matrix[12][12];
        std::vector<coords> ships;
        empty water;
    public:
        defense_grid();
        void insert_ship(ship& s);
        bool is_ship(coords& c);
        bool fire(coords& c);
        void move(coords& c, coords& s);
        void clear_position(ship& s);
        ship* get_ship(coords& c);
        char ship_at(coords& c);
        friend std::ostream& operator <<( std::ostream& os,  defense_grid& dg);
        std::vector<ship*> ship_in_range(coords& c);
        std::vector<coords> enemy_ships(coords& c);
        std::vector<coords> get_ships();
        void heal_ships(coords& c, coords& final_c);
        
        // aggiunta
        /*  
            ritorno il char di una casella specifica
        */
        char get_pos(int i, int j) {
            coords c = coords(i,j);
            if(is_ship(c))
                return ship_at(c);
            else
                return matrix[i][j]->get_alias();
        }
};

#endif