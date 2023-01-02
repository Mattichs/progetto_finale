#include "../include/empty.h"

empty::empty(coords& center) : ship(asset::Horizontal, center){
	alias = ' ';
	length = 1;
}