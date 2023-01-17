/*  
    BASTIANELLO MATTIA
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "grid/defense_grid.hpp"
#include "grid/attack_grid.hpp"
#include "utility.h"

#include <cstdlib>

/**
 * @brief class player can be human or bot there are two function that player can use rnd_move, for bot player, and make_move for human player
 * 
 */
class player {
    defense_grid& dg;
    attack_grid& ag;
    public:
        /**
         * @brief Construct a new player object
         * 
         * @param dg_ as 'defense_grid&'
         * @param ag_ as 'attack_grid&'
         */
        player(defense_grid& dg_, attack_grid& ag_) : dg{dg_}, ag{ag_} {}
        
        /**
         * @brief make random move, choose a center from all alive ships, then try to do an action until that is valid
         * 
         * @return std::string 
         */
        std::string rnd_move();

        /**
         * @brief make move from a string input that contains two coordinates
         * 
         * @param s as 'std::string'
         * 
         * @throw std::invalid_argument if move is illegal
         */
        void make_move(std::string s);  

        /**
         * @brief overload operator <<
         * 
         * @param os 
         * @param p
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& os,  player& p);
};


#endif