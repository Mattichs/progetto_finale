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
    std::vector<ship*> v;
    defense_grid dg=defense_grid();

    coords center {3, 5};
    corazzata c(asset::Vertical, center);
    dg.insert_ship(c);  
    v.push_back(&c);
    /* center = {4, 5};
    corazzata c1(asset::Vertical, center);
    dg.insert_ship(c1);  
    v.push_back(&c1); */
    std::cout << "Corazzata" << std::endl;

    center = {9, 4};
    supporto s(asset::Horizontal, center);
    dg.insert_ship(s);

    center = {7, 8};
    esploratore e(asset::Horizontal, center);
    dg.insert_ship(e);
    /* 
    coords coord {1,1};
    coords coord1 {2,2};
    ship* s = dg.get_ship(coord);
    ship* s1 = dg.get_ship(coord1);
    std::cout << "Centro: " << s->get_center().first << "," << s->get_center().second << std::endl;
    std::cout << "Centro: " << s1->get_center().first << "," << s1->get_center().second << std::endl;
     */
    coords fire{5,5};
    if(dg.fire(fire)) {
        std::cout << "Colpito!" << std::endl;
    } else {
        std::cout << "Acqua coglione" << std::endl;
    }

    std::cout << dg; 

    /* coords c {3,3};
    ship* s = dg.get_ship(c);
    std::cout << s->get_alias() << std::endl;
    coords a = s->get_center();
    std::cout << a.first << "," << a.second << std::endl; 
    //bot robot(dg);  */ 
}