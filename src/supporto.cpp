#include "../include/supporto.h"

supporto::supporto(asset way, coords& center) : ship(way, center){
	alias = 'S';
	hp = {1, 1, 1};
	length = 3;
}