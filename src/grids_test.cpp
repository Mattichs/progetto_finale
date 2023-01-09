//@FedericoCognolatto
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "bot.h"
#include <stdexcept>

// per random 
#include <stdlib.h>

using namespace std;

/* 
    gestisco la matrice direttamente dal main, se l'utente inserisce 5,5 vuol dire che dovrò passare 
    alle funzioni 4,4 siccome i vettori contano a partire da 0 (da trascrivere a fine progetto sul README)
*/

// print coords 
void print_coords(coords c) {
    cout << "(" << c.first << "," << c.second << ")" << endl;
}

// generate random coords
coords generate_rnd_coords() {
    int x = rand() % 12 + 1;
    int y = rand() % 12 + 1;
    return coords(x,y);
}

int main(){
    defense_grid dg=defense_grid();

    try{
        for(int i=0;i<2;i++){
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
    ship& s = dg.get_ship(coords{3,3});
    std::cout << s.get_alias() << std::endl;
    coords a = s.get_center();
    std::cout << a.first << "," << a.second << std::endl; 
    //bot robot(dg);  
}