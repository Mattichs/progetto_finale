#include "../include/ships.h"
#include "../include/movement.h"
#include "../include/grids.hpp"
#include <stdexcept>
#include <vector>

defense_grid::defense_grid( std::vector<corazzata>& c, std::vector<supporto>& s, std::vector<esploratore>& e): corazzate(c), navi_supp(s),esploratori(e){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            grid[i][j]=' ';
    }
    try{        
        for(corazzata el:corazzate){
            
        }
    }catch(const char& e){

    }

}