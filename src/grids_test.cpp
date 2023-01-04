#include <iostream>
#include "../include/defense_grid.hpp"
#include "../include/attack_grid.hpp"
#include <stdexcept>

int main(){
    std::vector<corazzata> battleships;
    for(int i=0;i<3;i++){
        coords center {5+i,5};
        battleships[i]=corazzata(asset::Horizontal, center);
    }
    std::vector<supporto> healers;
        for(int i=0;i<3;i++){
        coords center {3,7+i};
        healers[i]=supporto(asset::Vertical, center);
    }
    std::vector<esploratore> scouts;
    for(int i=0;i<3;i++){
        coords center {7+i,8};
        scouts[i]=esploratore(asset::Vertical,center);
    }
    defense_grid dg=defense_grid(battleships,healers,scouts);
    attack_grid ag=attack_grid(dg);
  
    std::cout<<dg;
}