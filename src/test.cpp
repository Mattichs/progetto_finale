#include "../include/ships.h"
#include "../include/ship.h"
#include "../include/movement.h"
#include <exception>
#include <iostream>
#include <vector>

int main(void){
    coords center_s = {0,1};
    coords center_e = {10,7};
    coords center_c = {5,5};
    
    corazzata co = corazzata(asset::Horizontal, center_c);
    supporto s = supporto(asset::Horizontal, center_s);
    esploratore e = esploratore(asset::Horizontal, center_e);



/*
*
*Provo a stampare le informazioni della barca tanto per
*
*/
    short coordinata_uno = co.get_center().first;
    short coordinata_due = co.get_center().second;
    
    std::cout << "\nInformazioni della corazzata" 
              << "\nAlias: " << co.get_alias() 
              << "\nLength: " << co.get_length()
              << "\nCentro: " << coordinata_uno << "," << coordinata_due;
    
    coordinata_uno = s.get_center().first;
    coordinata_due = s.get_center().second;
        
    std::cout << "\nInformazioni del supporto" 
              << "\nAlias: " << s.get_alias() 
              << "\nLength: " << s.get_length()
              << "\nCentro: " << coordinata_uno << "," << coordinata_due;
   
    coordinata_uno = e.get_center().first;
    coordinata_due = e.get_center().second;
    
    std::cout << "\nInformazioni dell'esploratore" 
              << "\nAlias: " << e.get_alias() 
              << "\nLength: " << e.get_length()
              << "\nCentro: " << coordinata_uno << "," << coordinata_due <<"\n\n";

/*
*
*Testo la funzione hit, is_dead e heal
*
*/

    e.get_hit(center_e);
    std::cout << "Dovrebbe essere true: " << e.is_dead();

    coords hit_corazzata = {5,4}; 
    co.get_hit(hit_corazzata);
    std::vector<short> health = co.get_hp();
    
    std::cout << "\nHp della corazzata dovrebbero essere qualcosa tipo 1 0 1 1 1";
    for(int i = 0; i < co.get_length(); i++){
        std::cout << health[i] << " ";
    }

    //Dovrebbe stampare c minuscola
    std::cout << "\nAlias della parte colpita (dovrebbe essere 0): " <<co.print(hit_corazzata);

    co.heal();
    std::cout << "\nHp della corazzata dovrebbero essere qualcosa tipo 1 1 1 1 1";
    for(int i = 0; i < co.get_length(); i++){
        std::cout << health[i] << " ";
    }

    //Dovrebbe stampare c MAIUSCOLA
    std::cout << co.print(hit_corazzata);
    std::cout << "\nAlias della parte colpita e poi riparata (dovrebbe essere 1): " <<co.print(hit_corazzata);

/*
*
*Testo la funzione get_positions che dovrebbe ritornare un array di coords con tutte le caselle occupate dalla nave
*
*/

    std::vector<short> posizioni_corazzata;
    std::vector<coords> posizioni = get_position(center_c, co.get_length(), co.get_way());
    
    for(int i = 0; i < co.get_length()*2; i+2){
        posizioni_corazzata[i] = posizioni[i].first;
        posizioni_corazzata[i+1] = posizioni[i].second;
    }

    std::cout << "\nMi aspetto 5,3 | 5,4 | 5,5 | 5,6 | 5,7  tipo...";
    std::cout << "\nLa corazzata di centro 5,5 in orizzontale occupa le caselle: ";
    for(int i = 0; i < co.get_length()*2; i+2){
        std::cout << posizioni_corazzata[i] << "," << posizioni_corazzata[i+1] << " | ";
    }

    return 0;
}