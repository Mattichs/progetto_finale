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
        std::vector<coords> enemy_positions; 
      
    public:
        /// @brief constructor of attack_grid
        /// @param dg enemy's defense_grid
        attack_grid(defense_grid& dg);

        /// @brief shoots to a given position 
        /// @param c position to
        /// @return true if the player hits a ship 
        bool fire(coords& c);

        /// @brief overloading of the operator << for attack_grid
        /// @param os reference to an ostream
        /// @param ag reference to an attack_grid
        /// @return the reference to the modified ostream
        friend std::ostream& operator <<( std::ostream& os,const attack_grid& ag);

        /// @brief reveals the ships position in a 5x5 square starting from a given center  
        /// @param c center of the square
        void enemy_ships(coords& c);

        /// @brief clears the revealed positions
        void reset_enemy_pos();
        
        /// @brief returns an element of the matrix at a given position
        /// @param i row
        /// @param j column
        /// @return the char of the matrix at [i][j]
        char get_pos(int i, int j) {
            return matrix[i][j];
        }
};
#endif