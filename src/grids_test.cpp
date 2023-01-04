#include <iostream>
#include "../include/defense_grid.hpp"
#include "../include/attack_grid.hpp"
#include <stdexcept>

int main(){
    std::vector<corazzata> battleships;
     try{
    for(int i=0;i<3;i++){
        coords center {3+i,5};
        std::cout<<"dio cane";
        battleships[i]=corazzata(asset::Horizontal, center);
        
    } 
    }catch(const char& e){
        std::cout<<e;
     }
   
    std::vector<supporto> healers;
    try{
        for(int i=0;i<3;i++){
        coords center {11,4+i};
        std::cout<<"dio porco";
        healers[i]=supporto(asset::Vertical, center);
        
    }
     }catch(const char& e){
        std::cout<<e;
     }
    std::vector<esploratore> scouts;
    try{
    for(int i=0;i<3;i++){
        coords center {7+i,8};
        std::cout<<"dio bastardo";
        scouts[i]=esploratore(asset::Vertical,center);
        
    }
     }catch(const char& e){
        std::cout<<e;
     }
  
    defense_grid dg=defense_grid(battleships,healers,scouts);
    attack_grid ag=attack_grid(dg);
  
    std::cout<<dg; 
    
}