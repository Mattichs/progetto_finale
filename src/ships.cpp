#include "../include/ships.h"
#include <stdexcept>

empty::empty(coords& center) : ship(asset::Horizontal, center){
	alias = ' ';
	length = 1;
}

corazzata::corazzata(asset way, coords& center) : ship(way, center){
	alias = 'C';
	hp = {1, 1, 1, 1, 1}; //Cosi da stampare C maiuscola nel caso sia 1 e c nel caso sia 0
	length = 5;

	std::vector<coords> positions = get_position(center, length, way);
}

supporto::supporto(asset way, coords& center) : ship(way, center){
	alias = 'S';
	hp = {1, 1, 1};
	length = 3;

	std::vector<coords> positions = get_position(center, length, way);
}

esploratore::esploratore(asset way, coords& center) : ship(way, center){
	alias = 'E';
	hp = {1};
	length = 1;

	std::vector<coords> positions = get_position(center, length, way);
}
