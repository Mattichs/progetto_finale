#include "../include/movement.h"

asset movement::get_way() const { return way; }

coords coords_translation(input totranslate){
    coords position;
    position.first = (short) totranslate.first - 65;
    position.second = (short) totranslate.second - 65;
}

std::vector<coords> get_position(coords center, short length, asset way){
    std::vector<coords> position;
    switch(way){
        case asset::Horizontal:
            for(int i = 0; i < length; i++){
                position[i].first = center.first - (length/2) + i;
                position[i].second = center.second;
            }
        break;

        case asset::Vertical:
            for(int i = 0; i < length; i++){
                position[i].first = center.first;
                position[i].second = center.second - (length/2) + i;
            }
        break;
    }                            
}