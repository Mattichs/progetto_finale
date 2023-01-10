#include "../../include/ship/movement.h"
#include <stdexcept>

bool valid_box(coords& target){
    if(target.first < 1 || target.first > 12 || target.second < 1 || target.second > 12) 
        return false;

    return true;
}

asset check_first_position(coords& stern, coords& prow, char c){
    c = std::tolower(c);

    switch(c){
        case 'e':
            if(stern != prow) throw std::invalid_argument("L'esploratore deve avere poppa e prua uguali");

            else return asset::Horizontal; //default choice
        break;

        case 's':
            //Case same row
            if(stern.first == prow.first){
                short result = stern.second - prow.second;

                if(std::abs(result) == 2) return asset::Horizontal;

                else throw std::invalid_argument("Il supporto deve avere una differenza di 2 nella seconda coordinata");
            }
            else if(stern.second == prow.second){
                short result = stern.first - prow.first;

                if(std::abs(result) == 2) return asset::Vertical;
            
                else throw std::invalid_argument("Il supporto deve avere una differenza di 2 nella prima coordinata");
            }
            else throw std::invalid_argument("Per essere posizionato l'esploratore deve avere almeno una coordinata uguale");
        break;
        
        case 'c':
            //Case same row
            if(stern.first == prow.first){
                short result = stern.second - prow.second;
                if(std::abs(result) == 4) return asset::Horizontal;

                else throw std::invalid_argument("La corazzata deve avere una differenza di 2 nella seconda coordinata");
            }
            //case same coloumn
            else if(stern.second == prow.second){
                short result = stern.first - prow.first;

                if(std::abs(result) == 4) return asset::Vertical;
            
                else throw std::invalid_argument("La corazzata deve avere una differenza di 2 nella prima coordinata");
            }

            else throw std::invalid_argument("Per essere posizionata la corazzata deve avere almeno una coordinata uguale");

        break;
    }
}

coords coords_translation(user_coords in){
    coords position;
    
    if(((short) in.first - 65) > 8)
        position.first = (short) in.first - 67;

    else 
        position.first = (short) in.first - 65;

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