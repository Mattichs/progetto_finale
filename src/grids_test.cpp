//@FedericoCognolatto
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
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
    std::vector<corazzata> battleships;
    try{
    for(int i=0;i<3;i++){
        coords center {3+i,5};
        battleships.push_back(corazzata(asset::Horizontal, center));
        
    } 
    }catch(const char& e){
        std::cout<<e;
     }
   
    std::vector<supporto> healers;
    try{
        for(int i=0;i<3;i++){
        coords center {10,4+i};
        healers.push_back(supporto(asset::Vertical, center));
        
    }
     }catch(const char& e){
        std::cout<<e;
     }
    std::vector<esploratore> scouts;
    try{
    for(int i=0;i<2;i++){
        coords center {7+i,8};
        scouts.push_back(esploratore(asset::Vertical,center));
        
    }
     }catch(const char& e){
        std::cout<<e;
     }
  
    defense_grid dg=defense_grid(battleships,healers,scouts);
    attack_grid ag=attack_grid(dg);
  
    std::cout<<dg << std::endl; 

    /* 
        commento in italiano

        - creo array delle barche rimanenti (o lo sposto su defense_grid o creerò una classe bot con questo membro)
        - scelgo a caso una barca tra queste
        - faccio la mossa con una posizione a caso
    */

    // create a vector of pointer to ship to get total of the ships on the defense board
    vector<corazzata> tot_battles;
    vector<esploratore> tot_scouts;
    vector<supporto> tot_supports;

    tot_battles = dg.get_battleships();
    tot_scouts = dg.get_scouts();
    tot_supports = dg.get_healers();

    vector<ship*> total_ship;

    for(corazzata &x : tot_battles) {
        total_ship.push_back(&x);
    }
    for(esploratore &x : tot_scouts) {
        total_ship.push_back(&x);
    }
    for(supporto &x : tot_supports) {
        total_ship.push_back(&x);
    } 
    
    coords action_coord = generate_rnd_coords();
    // generate random choose from remaining ships
    int rnd_value =  rand() % total_ship.size();
    if(total_ship[rnd_value]->get_alias() == 'C') {
        // action battleship    
        /* 
            magic move
        */
    } else if(total_ship[rnd_value]->get_alias() == 'S') {
        // action support
        /* 
            magic move
        */
    } else if (total_ship[rnd_value]->get_alias() == 'E') {
        // action scout
        /* 
            magic move
        */
    }
    /* for(int i = 0; i < total_ship.size();i++) {
        print_coords(total_ship[i]->get_center());
    } */
} 