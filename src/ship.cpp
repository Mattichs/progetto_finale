#include "../include/ship.h"
#include <stdexcept>

char ship::get_alias() const { return alias; }
//asset ship::get_way() const { return way; }
std::vector<short> ship::get_hp() const { return hp; }
short ship::get_length() const { return length; }

bool valid_box(coords& target){
    if(target.first < 1 || target.first > 12 || target.second < 1 || target.second > 12) 
        return false; //if false --> throw std::invalid_argument("Coordinate non valide");

    return true;
}

