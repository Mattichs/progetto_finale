#include "../include/bot.h"
#include <iostream>
#include <iterator>

void bot::get_total_ship() {
    // provo a prendere una corazzata
    coords a = dg.get_ship(coords{3,3}).get_center();
    std::cout << a.first << "," << a.second << std::endl; 
    std::cout << "total ship \n";
}