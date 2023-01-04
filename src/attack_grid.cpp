//@FedericoCognolatto
#include "../include/corazzata.h"
#include "../include/esploratore.h"
#include "../include/supporto.h"
#include "../include/movement.h"
#include "../include/attack_grid.hpp"
#include <stdexcept>
attack_grid::attack_grid( defense_grid& dg): dgrid(dg), grid(){
}//fine costruttore attack_grid

bool attack_grid::fire(coords c){
    if(dgrid.fire(c)){
        matrix[c.first][c.second]='X';
        return true;
    }
    matrix[c.first][c.second]='O';
    return false;
}

std::ostream& operator <<(std::ostream& os,const attack_grid& ag){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            os<<ag.matrix[i][j]<<" ";
        }
         os<<'\n';
    }
    return os;
}