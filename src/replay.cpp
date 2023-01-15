/* 
    Bastianello Mattia
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unistd.h>

#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/player.h"
#include "../include/utility.h"

void replay_terminale();
void replay_file();

int main(int argc, char *argv[]) {
    if(argc == 1) std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    else if(argc == 2) {
        if(strcmp(argv[1], "v") == 0) {
            std::cout << "Hai scelto il replay su terminale \n";
            /* 
                replay su terminale
            */
            replay_terminale();
        } else if(strcmp(argv[1], "f") == 0) {
            std::cout << "Hai scelto il replay su file \n";
            /* 
                replay su file
            */
            replay_file();
        } else {
            std::cout << "Perfavore inserisci un argomento valido" << std::endl;
        }
    } else {
        std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    }

    return 0;
}


/*  
    inserisco corazzata 
    passo come parametri una griglia e una stringa con le coordinate prua/poppa
*/
corazzata insert_corazzata(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    coords_vec = coords_translation(s);
    center = get_center(coords_vec);
    corazzata c = corazzata(get_asset(coords_vec), center); 
    dg.insert_ship(c);
    return c;
}
/*  
    inserisco supporto 
    passo come parametri una griglia e una stringa con le coordinate prua/poppa
*/
supporto insert_supporto(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    coords_vec = coords_translation(s);
    center = get_center(coords_vec);
    supporto supp = supporto(get_asset(coords_vec), center); 
    dg.insert_ship(supp);
    return supp;
}
/*  
    inserisco supporto 
    passo come parametri una griglia e una stringa con le coordinate prua/poppa
*/
esploratore insert_esploratore(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    coords_vec = coords_translation(s);
    center = get_center(coords_vec);
    esploratore e = esploratore(center); 
    dg.insert_ship(e);
    return e;
}

void replay_file() {

    std::ifstream log_file;
    try {
        log_file.open("test.txt");
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    std::string s;
    // verifico che il file sia stato aperto correttamente
    if(log_file.is_open()) {
        // leggo tutte le linee del file

        defense_grid dg_player1;
        defense_grid dg_player2;
        attack_grid ag_player1(dg_player2);
        attack_grid ag_player2(dg_player1);
        
        // primo player
        std::getline(log_file, s);
        corazzata c1_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        corazzata c2_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        corazzata c3_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        supporto s1_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        supporto s2_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        supporto s3_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        esploratore e1_p1 = insert_esploratore(dg_player1, s);
        std::getline(log_file, s);
        esploratore e2_p1 = insert_esploratore(dg_player1, s);        
        
        // secondo player
        std::getline(log_file, s);
        corazzata c1_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        corazzata c2_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        corazzata c3_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        supporto s1_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        supporto s2_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        supporto s3_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        esploratore e1_p2 = insert_esploratore(dg_player2, s);
        std::getline(log_file, s);
        esploratore e2_p2 = insert_esploratore(dg_player2, s);
        
        player player1(dg_player1, ag_player1);
        player player2(dg_player2, ag_player2);

        std::ofstream out("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); 
        
        // TODO funziona solo per partite patte, se vince il player 1 interrompo prima 
        while(std::getline(log_file, s)) {
            
            /* 
                aspetto i comandi per fare giocare la parita

                aspetto i print delle vare griglie
            */
           std::cout << "Griglia giocatore 1:"<< std::endl << player1;
           std::cout << "Griglia giocatore 2:"<< std::endl << player2;
           player1.move(s);
           std::getline(log_file, s);
           player2.move(s);
        }
        // reset to standard output
        std::cout.rdbuf(coutbuf); 

        // ho chiuso out.txt???
    } else { 
        std::cout << "Impossibile aprire il file";
    }
    log_file.close();
}


void replay_terminale() {
    std::ifstream log_file;
    try {
        log_file.open("test.txt");
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    std::string s;
    // verifico che il file sia stato aperto correttamente
    if(log_file.is_open()) {
        // leggo tutte le linee del file

        defense_grid dg_player1;
        defense_grid dg_player2;
        attack_grid ag_player1(dg_player2);
        attack_grid ag_player2(dg_player1);
        
        // primo player
        std::getline(log_file, s);
        corazzata c1_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        corazzata c2_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        corazzata c3_p1 = insert_corazzata(dg_player1, s);
        std::getline(log_file, s);
        supporto s1_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        supporto s2_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        supporto s3_p1 = insert_supporto(dg_player1, s);
        std::getline(log_file, s);
        esploratore e1_p1 = insert_esploratore(dg_player1, s);
        std::getline(log_file, s);
        esploratore e2_p1 = insert_esploratore(dg_player1, s);        
        
        // secondo player
        std::getline(log_file, s);
        corazzata c1_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        corazzata c2_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        corazzata c3_p2 = insert_corazzata(dg_player2, s);
        std::getline(log_file, s);
        supporto s1_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        supporto s2_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        supporto s3_p2 = insert_supporto(dg_player2, s);
        std::getline(log_file, s);
        esploratore e1_p2 = insert_esploratore(dg_player2, s);
        std::getline(log_file, s);
        esploratore e2_p2 = insert_esploratore(dg_player2, s);
        
        player player1(dg_player1, ag_player1);
        player player2(dg_player2, ag_player2);

        std::cout << "Griglia giocatore 1:"<< std::endl << player1;
        std::cout << "Griglia giocatore 2:"<< std::endl << player2;
        // TODO funziona solo per partite patte, se vince il player 1 interrompo prima 
        while(std::getline(log_file, s)) {
           player1.move(s);
           std::getline(log_file, s);
           player2.move(s);
           std::cout << "Griglia giocatore 1:"<< std::endl << player1;
           std::cout << "Griglia giocatore 2:"<< std::endl << player2;
            sleep(5);
        }
        // ho chiuso out.txt???
    } else { 
        std::cout << "Impossibile aprire il file";
    }
    log_file.close();
}