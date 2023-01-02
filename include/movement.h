#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <utility>
#include <vector>
#include <esploratore.h>
#include <supporto.h>
#include <corazzata.h>
#include <empty.h>

//All possible way to place a ship
enum class asset {Vertical, Horizontal};

//User input coordinates to translate --> Char for row and short for column
typedef std::pair<char,short> user_coords;

//A two short coordinate used for the methods instead of the char,short coordinate
typedef std::pair<short, short> coords;

//Translate the user input (char,short) in a (short,short) coordinate
coords coords_translation(user_coords);

//Return a vector of coordinates which contain all boxes occupied by the ship
std::vector<coords> get_position(coords&, short, asset);

//Check if the coords given are valid
bool valid_box(coords&);

#endif