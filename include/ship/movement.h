#ifndef MOVEMENT_H
#define MOVEMENT_H

/*
*@file movement.h
*@author Christian Poli (christian.poli.1@studenti.unipd.it)
*
*@brief The interface consists of functions useful for working with coords  
*
*@date 17-01-2023
*
*/

#include <utility>
#include <vector>

//All possible way to place a ship
enum class asset {Vertical, Horizontal}; 

//A pair of two short coordinate used for tracking,move... the ship in the grid
typedef std::pair<short, short> coords;

//Translate user's input in a vector which contains two coords, first for the selected ship and second for the target box
std::vector<coords> coords_translation(std::string s);

//Return a vector of coordinates which contain all boxes occupied by the ship
std::vector<coords> get_position(coords&, short, asset);

//Check if the coords given are valid
bool valid_box(coords&);

#endif