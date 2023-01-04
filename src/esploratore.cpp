#include "../include/esploratore.h"

esploratore::esploratore(asset way, coords& center) : ship(way, center){
	alias = 'E';
	hp = {1};
	length = 1;
	std::vector<coords> positions = get_position(center, length, way);
}