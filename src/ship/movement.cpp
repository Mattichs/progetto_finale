#include "../include/ship/movement.h"
#include <stdexcept>
#include <iostream>

/**
 * 
 * @file movement.cpp
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief Implementation of movement.h
 * 
 * @date 2023-01-17 
 * 
*/

bool valid_box(coords& target){
    if(target.first < 0 || target.first > 11 || target.second < 0 || target.second > 11) 
        return false;

    return true;
}

std::vector<coords> coords_translation(std::string s) {
    coords c1 {0,0};
    coords c2 {0,0};
    // Divide the string into the two coordinates
    std::string s1 = s.substr(0, s.find(" "));
    std::string s2 = s.substr(s.find(" ") + 1);

    if(s1[0] == 'K' || s1[0] == 'J' || s2[0] == 'K' || s2[0] == 'J') throw std::invalid_argument("J e K non fanno parte della griglia... \n");

    if(!(isalpha(s1[0]) && isalpha(s2[0]))) throw std::invalid_argument("Inserisci le coordinate in modo corretto! (il primo carattere deve essere una lettera)\n");
    
    if(s1.length() == 3) {
        // first coordinate
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = stoi(s1.substr(1,2)) - 1;
    } else {
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = s[1] - '0' - 1;
    }
    if(s2.length() == 3) {
        // second coordinate
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = stoi(s2.substr(1,2)) -1;
    } else if(s2.length() == 2){
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = s2[1] - '0' -1; // ex. conversion '0' -> 0
    } else {
        throw std::invalid_argument("Inserisci le coordinate in modo corretto \n");
    }
    std::vector<coords> v;

    if(valid_box(c1) && valid_box(c2)){
        v.push_back(c1);
        v.push_back(c2);
        return v;
    } else {
	throw std::invalid_argument("Coordinate non valide, reinsceriscile...\n");
    }
}

std::vector<coords> get_position(coords& center, short length, asset way){
    std::vector<coords> positions;
    if(length == 1){ //if length == 1 --> esploratore occupies only one box so it return only the center
        positions.push_back(center);
    } else {
        switch(way){
            case asset::Vertical: //if the ship is vertical the method change only the first coordinate (row)
                for(int i = 0; i < length; i++)
                    positions.push_back(coords(center.first - (length/2) + i, center.second)); //ex. corazzata center = (5,7) return:
            break;                                                                             // 5 - 2 + 0 = (3,7) , 5 - 2 + 1 = (4,7)
                                                                                               // 5 - 2 + 2 = (5,7) , 5 - 2 + 3 = (6,7)  
            case asset::Horizontal: //Ship horizontal change the second coordinate             // 5 - 2 + 4 = (7,7)
                for(int i = 0; i < length; i++)
                    positions.push_back(coords (center.first, center.second - (length/2) + i));
            break;
        }
    }
    //Check that all positions are valid
    for(int i = 0; i < length; i++){
        if(!valid_box(positions[i]))
            throw std::invalid_argument("Posizione non valida \n");
    }

    return positions;               
}
