#include "../include/corazzata.h"

corazzata::corazzata(asset way, coords& center) : ship(way, center){
	alias = 'C';
	hp = {1, 1, 1, 1, 1};
	length = 5;
}