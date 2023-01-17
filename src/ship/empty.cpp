#include "../include/ship/empty.h"

/**
 * 
 * @file empty.cpp
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief Implementation of empty.h
 * 
 * @date 2023-01-17 
 * 
*/

empty::empty() : ship(asset::Horizontal, center){
	alias = ' ';
	length = 1;
}