#include "../include/ship/esploratore.h"

/**
 * 
 * @file esploratore.cpp
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief Implementation of esploratore.h
 * 
 * @date 2023-01-17 
 * 
*/

esploratore::esploratore(coords& center) : ship(way, center){
	alias = 'E';
	hp = {1};
	length = 1;

	std::vector<coords> positions = get_position(center, length, way);
}