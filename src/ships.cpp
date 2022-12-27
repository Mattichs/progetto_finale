#include "../include/ships.h"
#include <stdexcept>

bool valid_coords(coords center);

corazzata::corazzata(asset way, coords center){
		way = way;
		center = center;
		alias = 'C';
		hp = {1, 1, 1, 1, 1}; //Cosi da stampare C maiuscola nel caso sia 1 e c nel caso sia 0
		length = 5;
}

supporto::supporto(asset way, coords center){
	way = way;
	center = center;
	alias = 'S';
	hp = {1, 1, 1};
	length = 3;
}

esploratore::esploratore(asset way, coords center){
	way = way;
	center = center;
	alias = 'E';
	hp = {1};
	length = 1;
}

void esploratore::find(coords center){
	
}

/*void movable::move(movable s,coords target){
	if(!valid_coords(target)) throw std::invalid_argument("Inserisci coordinate giuste la prossima volta, coglione");
	
	char alias = tolower(s.get_alias());
	switch(alias)
	case 'e': 
		break;
	case 's': 
		set way = get_way();
		if(valid_movement(s, way, target){}
		break;
}*/

/*bool valid_coords(coords center){
	if(center.first >= 12 || center.second < 0)
		return false;
	else
		return true;
}*/

/*bool valid_movement(movable s, set::way, coords target){
	if(tolower(s.get_alias() == 'e') return valid_coords(target);
	
	else if (tolower(s.get_alias() == 's'){
		switch(way){
			case set::Horizontal:
				 if(coords.second >= 1 || coords.second <= 11){
					std::cout << "Movimento accettato\n";
					
				}
				 
				 
			case set::Vertical:
		}
	
	}
	
	
}*/