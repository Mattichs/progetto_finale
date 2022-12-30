#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <utility>
#include <vector>

enum class asset {Vertical, Horizontal};
typedef std::pair<short, short> coords; //Userei il primo numero per la riga e il secondo per la colonna
typedef std::pair<char,short> user_coords;

coords coords_translation(user_coords);
std::vector<coords> get_position(coords&, short, asset);
bool valid_box(coords&);

#endif