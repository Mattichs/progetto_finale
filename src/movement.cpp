#include "../include/movement.h"
#include <stdexcept>

bool valid_box(coords& target){
    if(target.first < 1 || target.first > 12 || target.second < 1 || target.second > 12) 
        return false;

    return true;
}

coords coords_translation(user_coords in){
    coords position;
    position.first = (short) in.first - 65;

    return position;
}

/*
*
*Funzione che ritorna un array di coords con le coordinate di ogni casella occupata dalla barca
*
*/

std::vector<coords> get_position(coords& center, short length, asset way){
    std::vector<coords> positions;

    if(length == 1){ 
        positions[0] = center;
    }

    switch(way){
        case asset::Horizontal:
            for(int i = 0; i < length; i++){
                positions[i].first = center.first - (length/2) + i; //first = riga
                positions[i].second = center.second;                //second = colonna
            }
        break;

        case asset::Vertical:
            for(int i = 0; i < length; i++){
                positions[i].first = center.first;
                positions[i].second = center.second - (length/2) + i;
            }
        break;
    }

    for(int i = 0; i < length; i++){
        if(!valid_box(positions[i]))
            throw std::invalid_argument("");
    }

    return positions;                            
}