#include "../include/ship/empty.h"

empty::empty() : ship(asset::Horizontal, center){
	alias = '~';
	length = 1;
}