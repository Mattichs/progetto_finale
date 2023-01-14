#include "../../include/ship/movement.h"
#include <stdexcept>
#include <iostream>

bool valid_box(coords& target){
    // modificato siccome la matrice conta da 0 a 11 
    // probabilmente un sottomarino in (0,0) da errore
    if(target.first < 0 || target.first > 11 || target.second < 0 || target.second > 11) 
        return false;

    return true;
}

coords coords_translation(user_coords in){
    coords position;
	in.first = toupper(in.first);
	
	if((short) in.first > 73)	position.first = (short) in.first - 67;
	else position.first = (short) in.first - 65;
    
	position.second = in.second - 1;

    return position;
}

coords prendi_centro(coords& new_stern, coords& new_prow){
	short length;	

	if(new_stern.first == new_prow.first && new_stern.second == new_prow.second) return new_stern;

	if(new_stern.first == new_prow.first){
		length = std::abs(new_stern.second - new_prow.second);			

		for(int i = 0; i < length; i++){
			if(new_stern.second + i == new_prow.second - i) 
				return {new_stern.first, new_stern.second + i};
		
			else if(new_stern.second - i == new_prow.second + i) 
				return {new_stern.first, new_stern.second - i};
		} 
	}
	if(new_stern.second == new_prow.second){
		length = std::abs(new_stern.first - new_prow.first);
		
		for(int i = 0; i < length; i++){
			if(new_stern.first + i == new_prow.first - i)
				return {new_stern.first + i, new_stern.second};

			else if(new_stern.first - i == new_prow.first + i)
				return {new_stern.first - i, new_stern.second};
		}
	}
}

asset check_first_position(coords& stern, coords& prow, char c){
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

                else throw std::invalid_argument("La corazzata deve avere una differenza di 4 nella seconda coordinata");
            }
            //case same coloumn
            else if(stern.second == prow.second){
                short result = stern.first - prow.first;

                if(std::abs(result) == 4) return asset::Vertical;
            
                else throw std::invalid_argument("La corazzata deve avere una differenza di 4 nella prima coordinata");
            }

            else throw std::invalid_argument("Per essere posizionata la corazzata deve avere almeno una coordinata uguale");

        break;
    }
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