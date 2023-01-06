#include "../include/ship/supporto.h"

supporto::supporto(asset way, coords& center) : ship(way, center){
	alias = 'S';
	hp = {1, 1, 1};
	length = 3;
	std::vector<coords> positions = get_position(center, length, way);
}