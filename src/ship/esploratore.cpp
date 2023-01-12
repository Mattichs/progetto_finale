#include "../include/ship/esploratore.h"

esploratore::esploratore(asset way, coords& center) : ship(way, center){
	alias = 'E';
	hp = {1};
	length = 1;
	std::vector<coords> positions = get_position(center, length, way);
}

void esploratore::spot(attack_grid& ag,defense_grid& dg,coords& c){
	coords start=get_center();

	dg.move(start,c);
	ag.enemy_ships(c);


}