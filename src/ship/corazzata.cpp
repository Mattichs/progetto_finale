#include "../include/ship/corazzata.h"
#include <iostream>

corazzata::corazzata(asset way, coords& center) : ship(way, center){
	alias = 'C';
	hp = {1, 1, 1, 1, 1};
	length = 5;
	std::vector<coords> positions = get_position(center, length, way);
	for(coords c : positions) {
		std::cout << c.first << "," << c.second << std::endl;
	}
}