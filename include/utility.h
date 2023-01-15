#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include <iostream>
#include "../include/ship/movement.h"
#include <ctime>
#include <cstdlib>

std::string to_string(coords& c, asset a , char alias);
std::string to_string_helper(coords& c1, coords& c2);

// cambio coordinate char,int ---> int,int 
std::vector<coords> coords_translation(std::string s);

// ottengo il centro da due coordinate
// siccome gestiamo la matrice da 0 a 11 qui sottraggo uno a quello che inserisce l'utente ottenendo il risultato corretto per l'inserimento
coords get_center(std::vector<coords> v);


// non gestisco la barca in diagonale per il momento, sarebbe errore
asset get_asset(std::vector<coords> v);

void print_coords(coords c);

// generate random coords (0 to 11)
coords generate_rnd_coords();

asset generate_rnd_asset();

#endif