/* 
    BASTIANELLO MATTIA
*/
#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include <iostream>
#include "../include/ship/movement.h"
#include <ctime>
#include <cstdlib>


/**
 * @brief Get the prow stern object
 * 
 * @param c as 'coords&'
 * @param a as 'asset'
 * @param alias as 'char'
 * @return std::string 
 */
std::string get_prow_stern(coords& c, asset a, char alias);
std::string two_coords_to_string(coords& c1, coords& c2);

/**
 * @brief change input string in two coords returned in a std::vector
 * 
 * @param s as 'std::string'
 * @return std::vector<coords> 
 */
std::vector<coords> coords_translation(std::string s);

/**
 * @brief Get the center of the ship 
 * 
 * @param v as 'std::vector<coords>'
 * @return coords 
 */
coords get_center(std::vector<coords> v);

/**
 * @brief Get the asset of the ship
 * 
 * @param v as 'std::vector<coords>'
 * @param letter as 'char'
 * @return asset 
 */
asset get_asset(std::vector<coords> v, char letter);

/**
 * @brief generate random coords range of x,y [0,11]
 * 
 * @return coords 
 */
coords generate_rnd_coords();

/**
 * @brief generate random asset
 * 
 * @return asset 
 */
asset generate_rnd_asset();

#endif