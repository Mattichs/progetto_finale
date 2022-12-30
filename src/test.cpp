#include "../include/ships.h"
#include "../include/ship.h"
#include "../include/movement.h"
#include <exception>
#include <iostream>


bool ver_place_test(coords& c){
    bool result;
    try{
    corazzata s = corazzata(asset::Horizontal, c);
    result = true;
    }
    catch(std::invalid_argument exc){ result = false; }
    return result;
}

int main(void){

    coords center = {5,5};
    ship s = ship(asset::Horizontal, center);
    
    bool k = ver_place_test(center);
    std::cout << k;

    return 0;
}