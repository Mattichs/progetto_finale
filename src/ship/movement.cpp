#include "../../include/ship/movement.h"
#include <stdexcept>

bool valid_box(coords& target){
    if(target.first < 1 || target.first > 12 || target.second < 1 || target.second > 12) 
        return false;

    return true;
}

coords coords_translation(user_coords in){
    coords position;
    position.first = (short) in.first - 65;
    position.second = in.second;
    position.second = in.second; 

    return position;
}

/*
*
* Funzione che ritorna un array di coords con le coordinate di ogni casella occupata dalla barca
*
*/

std::vector<coords> get_position(coords& center, short length, asset way){
    std::vector<coords> positions;
    if(length == 1){ 
        positions.push_back(center);
    } else {
        switch(way){
            case asset::Vertical:
                for(int i = 0; i < length; i++){
                    positions.push_back(coords(center.first - (length/2) + i, center.second));
                    //std::cout << positions[i].first << "," << positions[i].second << std::endl;
                }
            break;

            case asset::Horizontal:
                for(int i = 0; i < length; i++){
                    positions.push_back(coords (center.first, center.second - (length/2) + i));
                }
            break;
        }
    }

    // controllo che le posizioni della barca sia valida
    for(int i = 0; i < length; i++){
        if(!valid_box(positions[i])) {
            //std::cout << positions[i].first << "," << positions[i].second << std::endl; 
            //std::cout << "errore" << std::endl;
            throw std::invalid_argument("Position not valid");
        }
    }

    return positions;               
}