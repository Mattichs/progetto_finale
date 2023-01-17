#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <utility>
#include <vector>
#include <string>

/**
 * 
 * @file movement.h
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief The interface consists of useful functions for working with ships and coords
 * 
 * @date 2023-01-17 
 * 
*/

//All possible way to place a ship
enum class asset {Vertical, Horizontal}; 

//A pair of two short used as coordinate of the ship
typedef std::pair<short, short> coords;

//Translate user's input in a vector which contains two coords, first for the selected ship and second for the target box
std::vector<coords> coords_translation(std::string s);

//Return a vector of coordinates which contain all boxes occupied by the ship
std::vector<coords> get_position(coords&, short, asset);

//Check if the coords given are valid
bool valid_box(coords&);

#endif