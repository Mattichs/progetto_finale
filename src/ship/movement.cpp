#include "../include/ship/movement.h"
#include <stdexcept>

bool valid_box(coords& target){
    if(target.first < 0 || target.first > 11 || target.second < 0 || target.second > 11) 
        return false;

    return true;
}

std::vector<coords> coords_translation(std::string s) {
    coords c1 {0,0};
    coords c2 {0,0};
    // prendo la stringa la divido in due e procedo
    std::string s1 = s.substr(0, s.find(" "));
    std::string s2 = s.substr(s.find(" ") + 1);

    if(!(isalpha(s1[0]) && isalpha(s2[0]))) throw std::invalid_argument("Inserisci le coordinate in modo corretto! (il primo carattere deve essere una lettera)\n");
    if(s1.length() == 3) {
        // prima coordinata
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = stoi(s1.substr(1,2)) - 1;
    } else {
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = s[1] - '0' - 1;
    }
    if(s2.length() == 3) {
        // seconda coordinata
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = stoi(s2.substr(1,2)) -1;
    } else if(s2.length() == 2){
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = s2[1] - '0' -1; // es. conversione '0' -> 0
    } else {
        throw std::invalid_argument("Inserisci le coordinate in modo corretto \n");
    }
    std::vector<coords> v;
    v.push_back(c1);
    v.push_back(c2);
    return v;
}

std::vector<coords> get_position(coords& center, short length, asset way){
    std::vector<coords> positions;
    if(length == 1){ 
        positions.push_back(center);
    } else {
        switch(way){
            case asset::Vertical:
                for(int i = 0; i < length; i++)
                    positions.push_back(coords(center.first - (length/2) + i, center.second));
            break;

            case asset::Horizontal:
                for(int i = 0; i < length; i++)
                    positions.push_back(coords (center.first, center.second - (length/2) + i));
            break;
        }
    }

    for(int i = 0; i < length; i++){
        if(!valid_box(positions[i]))
            throw std::invalid_argument("Posizione non valida \n");
    }

    return positions;               
}