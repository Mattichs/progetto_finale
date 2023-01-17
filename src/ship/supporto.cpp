#include "../include/ship/supporto.h"

/**
 * 
 * @file supporto.cpp
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief Implementation of supporto.h
 * 
 * @date 2023-01-17 
 * 
*/

supporto::supporto(asset way, coords& center) : ship(way, center){
	alias = 'S';
	hp = {1, 1, 1};
	length = 3;

	std::vector<coords> positions = get_position(center, length, way);
}