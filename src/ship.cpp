#include "../include/ship.h"
#include <stdexcept>
#include <vector>

ship::ship(asset _way, coords& _center) {
    way = _way;
    center = _center;
    std::vector<coords> positions = get_position(center, length, way);
}

char ship::get_alias() const { return alias; }
asset ship::get_way() const { return way; }
std::vector<short> ship::get_hp() const { return hp; }
short ship::get_length() const { return length; }
coords ship::get_center() const {return center; }

void ship::get_hit(coords& target){
    std::vector<coords> positions;
    positions = get_position(center, length, way);
    
    for(int i = 0; i < length; i++){
        if(positions[i].first == target.first && positions[i].second == target.second)
            hp[i] = 0;
    }
}

bool ship::is_dead(){
    short count;
    
    for(int i = 0; i < hp.size(); i++){
        if(hp[i] == 0) count++;    
    }
    
    return hp.size() == count;
}

void ship::heal(){
    for(int i = 0; i < hp.size(); i++){
        hp[i] = 1;
    }
}

char ship::print(coords& target){
    std::vector<coords> positions;
    positions = get_position(center, length, way);

    for(int i = 0; i < length; i++){
        if(target.first == positions[i].first && target.second == positions[i].second){
            if(hp[i] == 0) return tolower(alias);
        }
    }
    return alias;
}