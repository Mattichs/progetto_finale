//@FedericoCognolatto
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include <stdexcept>

int main(){
    defense_grid dg=defense_grid();

    try{
        for(int i=0;i<3;i++){
            // coords c {row, column}
            coords center {3 + i, 5};
            corazzata c(asset::Horizontal, center);
            dg.insert_ship(c);  
        } 
    }catch(const char& e){
       std::cout<<e;
    }
    
    try{
        for(int i=0;i<3;i++){
        coords center {9 + i, 4};
        supporto c(asset::Horizontal, center);
        dg.insert_ship(c);
    }
     }catch(const char& e){
        std::cout<<e;
     }
    std::vector<esploratore> scouts;
    try{
    for(int i=0;i<2;i++){
        coords center {7 + i, 8};
        esploratore c(asset::Horizontal, center);
        dg.insert_ship(c);        
    }
     }catch(const char& e){
        std::cout<<e;
     }

    std::cout << dg; 
}