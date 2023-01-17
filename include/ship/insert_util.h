/*
    BASTIANELLO MATTIA
*/
#ifndef INSERT_UTIL_H
#define INSERT_UTIL_H

#include "../include/grid/defense_grid.hpp"
#include "../include/utility.h"


// battaglia_navale functions

/**
 * @brief Create a corazzata object, generate random center and asset until position is valid then return corazzata, then add coords to out param
 * 
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return corazzata 
 */
corazzata create_corazzata(defense_grid& dg, std::vector<std::string>& out);

/**
 * @brief Create a supporto object, generate random center and asset until position is valid then return supporto, then add coords to out param
 * 
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return supporto 
 */
supporto create_supporto(defense_grid& dg, std::vector<std::string>& out);

/**
 * @brief Create a esploratore object, generate random center and asset until position is valid then return esploratore, then add coords to out param
 * 
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return esploratore 
 */
esploratore create_esploratore(defense_grid& dg, std::vector<std::string>& out);


/**
 * @brief insert corazzata from user input, return corazzata when the input is valid and add to out params
 * 
 * @param messaggio as 'std::string'
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return corazzata 
 */
corazzata insert_corazzata(std::string messaggio, defense_grid& dg, std::vector<std::string>& out);

/**
 * @brief insert supporto from user input, return supporto when the input is valid and add to out params
 * 
 * @param messaggio as 'std::string'
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return supporto 
 */
supporto insert_supporto(std::string messaggio, defense_grid& dg, std::vector<std::string>& out);

/**
 * @brief insert esploratore from user input, return esploratore when the input is valid and add to out params
 * 
 * @param messaggio as 'std::string'
 * @param dg as 'defense_grid&'
 * @param out as 'std::vector<std::string>&'
 * @return esploratore 
 */
esploratore insert_esploratore(std::string messaggio, defense_grid& dg, std::vector<std::string>& out);


// replay functions
/**
 * @brief insert corazzata from a string that contains valid coords
 * 
 * @param dg as 'defense_grid&'
 * @param s as 'std::string'
 * @return corazzata 
 */
corazzata insert_corazzata(defense_grid& dg, std::string s);

/**
 * @brief insert supporto from a string that contains valid coords
 * 
 * @param dg as 'defense_grid&'
 * @param s as 'std::string'
 * @return supporto 
 */
supporto insert_supporto(defense_grid& dg, std::string s);

/**
 * @brief insert esploratore from a string that contains valid coords
 * 
 * @param dg as 'defense_grid&'
 * @param s as 'std::string'
 * @return esploratore 
 */
esploratore insert_esploratore(defense_grid& dg, std::string s);

#endif