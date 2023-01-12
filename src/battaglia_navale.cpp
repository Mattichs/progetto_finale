/* 
    Bastianello Mattia
*/
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/utility.h"
#include "../include/bot.h"
#include <ctime>
#include <fstream>
#include <cstdlib>
//#include <memory>

/* 
    argc è un intero con il numero di argomenti passati a riga di comdando
    argv è un array di puntatori agli argomenti passati
    argv[0] è il nome del programma
*/

void giocatore_vs_computer();
void computer_vs_computer();

int main(int argc, char *argv[]) {

    srand ( time(NULL) );

    if(argc == 1) std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    else if(argc == 2) {
        if(strcmp(argv[1], "pc") == 0) {
            std::cout << "Hai scelto la partita giocatore vs computer \n";
            /* 
                gioco player vs bot
            */
            giocatore_vs_computer();
        } else if(strcmp(argv[1], "cc") == 0) {
            std::cout << "Hai scelto la partita computer vs computer \n";
            /* 
                gioco bot vs bot
            */
            computer_vs_computer();
        } else {
            std::cout << "Perfavore inserisci un argomento valido" << std::endl;
        }
    } else {
        std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    }
    
   return 0; 
}

void computer_vs_computer() {
    defense_grid dg_bot1;
    attack_grid ag_bot2(dg_bot1);
    defense_grid dg_bot2;
    attack_grid ag_bot1(dg_bot2);
    std::vector<std::string> set_bot1;
    std::vector<std::string> set_bot2;
    // inizio inserimento barche casuale
    bool status = false;
    coords rnd;
    asset rnd_asset;
    corazzata c;
    for(int i = 0 ; i < 3; i++) {
        while(!status) {
            try {
                rnd = generate_rnd_coords();
                rnd_asset = generate_rnd_asset();
                c = corazzata(rnd_asset,rnd); 
                dg_bot1.insert_ship(c);
                set_bot1.push_back(to_string(rnd, rnd_asset, c.get_alias()));
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    supporto s;
    for(int i = 0 ; i < 3; i++) {
        while(!status) {
            try {
                rnd = generate_rnd_coords();
                rnd_asset = generate_rnd_asset();
                s = supporto(rnd_asset,rnd); 
                dg_bot1.insert_ship(s);
                set_bot1.push_back(to_string(rnd, rnd_asset, s.get_alias()));
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    esploratore e;
    for(int i = 0 ; i < 2; i++) {
        while(!status) {
            try {
                rnd = generate_rnd_coords();
                rnd_asset = generate_rnd_asset();
                e = esploratore(rnd); 
                dg_bot1.insert_ship(e);
                set_bot1.push_back(to_string(rnd, rnd_asset, e.get_alias()));
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    // fine inserimento primo bot

    // inzio inserimento secondo bot
    corazzata c1;
    for(int i = 0 ; i < 3; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                c1 = corazzata(generate_rnd_asset(),rnd); 
                dg_bot2.insert_ship(c1);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    supporto s1;
    for(int i = 0 ; i < 3; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                s1 = supporto(generate_rnd_asset(),rnd); 
                dg_bot2.insert_ship(s1);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    esploratore e1;
    for(int i = 0 ; i < 2; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                e1 = esploratore(rnd); 
                dg_bot2.insert_ship(e1);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    // fine inserimento secondo bot
    
    bot bot1(dg_bot1, ag_bot1, set_bot1);

    bot bot2(dg_bot2, ag_bot2, set_bot2);
    int counter = 0;
    std::cout << dg_bot1;
    /* while(counter < 5) {
        //std::cout << "griglie bot 1 \n" << dg_bot1;
        //std::cout << "griglia difesa bot 2 \n";
        //bot2.print_grid();
        std::cout << "griglie bot 1 \n" << dg_bot1;
        bot1.rnd_move();
        std::cout << "Mossa eseguita \n";
        //std::string p;
        //std::cin >> p; 
        counter++;
    }   */
    std::ofstream outfile ("test.txt");

    for(std::string row : bot1.get_text()) {
        outfile << row;
    }
    outfile.close();
}

// per il momento l'utente deve essere sicuro che l'inserimento sia corretto
void giocatore_vs_computer() {
    // variabili utili
    defense_grid dg_player;
    defense_grid dg_bot1;
    attack_grid ag_player(dg_bot1);
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    /*
        inserimento corazzate     
    *//* 
    std::cout << "Inserisci posizione prima corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    center = get_center(coords_vec);
    corazzata c1(get_asset(coords_vec), center); 
    dg_player.insert_ship(c1);
 
    std::cout << "Inserisci posizione seconda corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    corazzata c2(get_asset(coords_vec), center);
    dg_player.insert_ship(c2);

    std::cout << "Inserisci posizione terza corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    corazzata c3(get_asset(coords_vec), center);
    dg_player.insert_ship(c3);
    
    /*
        inserimento supporti     
    
    std::cout << "Inserisci posizione primo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    
    center = get_center(coords_vec);
    supporto s1(get_asset(coords_vec), center); 
    dg_player.insert_ship(s1);
    
    ag_player.fire(center);

    std::cout << "Inserisci posizione secondo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    supporto s2(get_asset(coords_vec), center);
    dg_player.insert_ship(s2);

    std::cout << "Inserisci posizione terzo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    supporto s3(get_asset(coords_vec), center);
    dg_player.insert_ship(s3);
    
    /* 
        inserimento esploratori     
    
    std::cout << "Inserisci posizione primo esploratore: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    
    center = get_center(coords_vec);
    esploratore e1(get_asset(coords_vec), center); 
    dg_player.insert_ship(e1);
  */
    std::cout << "Inserisci posizione secondo esploratore: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    esploratore e2(center);
    dg_player.insert_ship(e2);

    // bot
    // inizio inserimento barche casuale
    bool status = false;
    coords rnd;
    asset rnd_asset;
    corazzata c;
    for(int i = 0 ; i < 3; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                c = corazzata(generate_rnd_asset(),rnd); 
                dg_bot1.insert_ship(c);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    supporto supp;
    for(int i = 0 ; i < 3; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                supp = supporto(generate_rnd_asset(),rnd); 
                dg_bot1.insert_ship(supp);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    esploratore e;
    for(int i = 0 ; i < 2; i++) {
         while(!status) {
            try {
                rnd = generate_rnd_coords();
                e = esploratore(rnd); 
                dg_bot1.insert_ship(e);
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
        }  
    status = false;
    }
    // bot
    std::cout << dg_bot1;
    std::cout << dg_player << ag_player;

    attack_grid ag_bot1(dg_player);
    //bot bot1(dg_bot1, ag_bot1);

    while(true) {
        std::cout << "muovi il sottomarino \n";
        std::getline(std::cin, s);
        coords_vec = coords_translation(s); 
        // prima muovo poi spotto
        dg_player.move(coords_vec[0], coords_vec[1]);
        ag_player.enemy_ships(coords_vec[1]);
        
        //bot1.rnd_move();

        std::cout << "player \n" << dg_player << ag_player;

        std::cout << "bot: \n" << dg_bot1;

    }

}