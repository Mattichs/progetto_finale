#include "../include/ships.h"
#include "../include/movement.h"
#include "../include/attack_grid.hpp"
#include <stdexcept>
#include <vector>
attack_grid::attack_grid( defense_grid& dg): dgrid(dg){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=' ';
    }
}//fine costruttore attack_grid