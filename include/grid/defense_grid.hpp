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
        /// @brief default constructor
        defense_grid();

        /// @brief inserts a ship into the matrix
        /// @param s ship to insert
        void insert_ship(ship& s);

        /// @brief checks if there is a ship at the given position
        /// @param c postion to check
        /// @return true if there is a ship
        bool is_ship(coords& c);

        /// @brief checks if a ship has been hit
        /// @param c 
        /// @return true if a ship has been hit
        bool fire(coords& c);

        /// @brief moves a ship 
        /// @param start old center of the ship
        /// @param s new center of the ship
        void move(coords& start, coords& end);

        /// @brief clears all the positions of a given ship in the matrix 
        /// @param s ship to clear
        void clear_positions(ship& s);

        /// @brief rerturns a ship at a given position
        /// @param c position of the ship
        /// @return element of the matrix at the given position
        ship* get_ship(coords& c);

        /// @brief returns the alias of a ship based on it's hp
        /// @param c position of the ship
        /// @return ship's alias, if the postion's hp is set to 1, or alias to lower case if the hp is set to 0
        char ship_at(coords& c);

        /// @brief checks if a poistion is the center of a ship
        /// @param c position to check
        /// @return true if c is the center of a ship
        bool is_center(coords& c);

        /// @brief checks if there is any ship in the grid
        /// @return true if the grid is empty
        bool is_empty();

        /// @brief overloading of the operator << for defense_grid
        /// @param os reference to an ostream
        /// @param ag reference to an defense_grid
        /// @return the reference to the modified ostream 
        friend std::ostream& operator <<( std::ostream& os,  defense_grid& dg);

        /// @brief finds the ships in a 3x3 square having a ship as its center
        /// @param c center of the ship
        /// @return vector containing pointers of the ships that have been found
        std::vector<ship*> ships_in_range(coords& c);

        /// @brief returns the ships vector
        /// @return vector containing all the centers of the ships
        std::vector<coords> get_ships();

        /// @brief moves a ship and heals all ships in a 3x3 square starting from the ship's new center
        /// @param c old center
        /// @param final_c new center
        void heal_ships(coords& c, coords& final_c);
        
        /// @brief returns the alias of the element at [i][j] of the matrix
        /// @param i row
        /// @param j column
        /// @return alias of the element
        char get_pos(int i, int j);
};

#endif