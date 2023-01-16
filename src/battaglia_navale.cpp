/* 
    Bastianello Mattia
*/
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/utility.h"
#include "../include/player.h"
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cstring>
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
        if(strcmp(argv[1], "-pc") == 0) {
            std::cout << "Hai scelto la partita giocatore vs computer \n";
            /* 
                gioco player vs bot
            */
            giocatore_vs_computer();
        } else if(strcmp(argv[1], "-cc") == 0) {
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


/* 
    creo una corazzata randomicamente 
    passo come parametri la griglia di difesa e un vettore di stringhe dove aggiungere le coordinate di prua e di poppa
*/
corazzata create_corazzata(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    
    // creo 8 navi per avere 8 oggetti diversi e non avere problemi con la griglia

    corazzata c;
    while(!status) {
            try { 
                rnd = generate_rnd_coords();
                rnd_asset = generate_rnd_asset();
                c = corazzata(rnd_asset,rnd); 
                dg.insert_ship(c);
                out.push_back(to_string(rnd, rnd_asset, c.get_alias()));
                status = true;
            } catch(std::invalid_argument e) {
                std::cout << e.what() << std::endl;
            }
    }
    return c;  
}

/* 
    creo un supporto randomicamente 
    passo come parametri la griglia di difesa e un vettore di stringhe dove aggiungere le coordinate di prua e di poppa
*/
supporto create_supporto(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    
    supporto s;
    while(!status) {
        try { 
            rnd = generate_rnd_coords();
            rnd_asset = generate_rnd_asset();
            s = supporto(rnd_asset,rnd);
            dg.insert_ship(s); 
            out.push_back(to_string(rnd, rnd_asset, s.get_alias()));
            status = true;
        } catch(std::invalid_argument e) {
            std::cout << e.what() << std::endl;
        }
    }
    return s;
}
/* 
    creo un esploratore randomicamente 
    passo come parametri la griglia di difesa e un vettore di stringhe dove aggiungere le coordinate di prua e di poppa
*/
esploratore create_esploratore(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    
    esploratore e;
    while(!status) {
        try { 
            rnd = generate_rnd_coords();
            e = esploratore(rnd); 
            dg.insert_ship(e);
            out.push_back(to_string(rnd, rnd_asset, e.get_alias()));
            status = true;
        } catch(std::invalid_argument e) {
            std::cout << e.what() << std::endl;
        }
    }
    return e;
}


void computer_vs_computer() {
    defense_grid dg_bot1;
    defense_grid dg_bot2;
    attack_grid ag_bot1(dg_bot2);
    attack_grid ag_bot2(dg_bot1);
    
    // inizio inserimento barche casuale

    std::vector<std::string> out;

    corazzata bot1_c1 = create_corazzata(dg_bot1, out);
    corazzata bot1_c2= create_corazzata(dg_bot1, out);
    corazzata bot1_c3= create_corazzata(dg_bot1, out);

    supporto bot1_s1 = create_supporto(dg_bot1, out);
    supporto bot1_s2 = create_supporto(dg_bot1, out);
    supporto bot1_s3 = create_supporto(dg_bot1, out);
 
    esploratore bot1_e1 = create_esploratore(dg_bot1, out);
    esploratore bot1_e2 = create_esploratore(dg_bot1, out);

    // fine inserimento primo bot

    corazzata bot2_c1 = create_corazzata(dg_bot2, out);
    corazzata bot2_c2= create_corazzata(dg_bot2, out);
    corazzata bot2_c3= create_corazzata(dg_bot2, out);

    supporto bot2_s1 = create_supporto(dg_bot2, out);
    supporto bot2_s2 = create_supporto(dg_bot2, out);
    supporto bot2_s3 = create_supporto(dg_bot2, out);
 
    esploratore bot2_e1 = create_esploratore(dg_bot2, out);
    esploratore bot2_e2 = create_esploratore(dg_bot2, out);


    player bot1(dg_bot1, ag_bot1);
    player bot2(dg_bot2, ag_bot2);

    int turni_max = 10000;
    while(turni_max > 0) {
        std::cout << "Griglia bot 1:"<< std::endl << bot1;
        std::cout << "Griglia bot 2:"<< std::endl << bot2;   
        out.push_back(bot1.rnd_move());
        // controllo se il bot1 ha vinto
        if(dg_bot2.is_empty()) break;
        // controllo se il bot2 ha vinto
        out.push_back(bot2.rnd_move());
        if(dg_bot1.is_empty()) break;
        turni_max--;
    }   
    std::ofstream outfile ("file_log_cc.txt");

    for(std::string row : out) {
        outfile << row;
    }
    outfile.close();    
}

corazzata insert_corazzata(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    corazzata c;
    while(!status) {
        try {
            std::cout << "Inserisci posizione corazzata nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            center = get_center(coords_vec);
            // ottengo e controllo
            a = get_asset(coords_vec, 'c');
            c = corazzata(a, center); 
            dg.insert_ship(c);
            out.push_back(s += "\n");
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return c;
}
supporto insert_supporto(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    supporto supp;
    while(!status) {
        try {
            std::cout << "Inserisci posizione supporto nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            // ottengo e controllo
            a = get_asset(coords_vec, 's');
            center = get_center(coords_vec);
            supp = supporto(a, center); 
            dg.insert_ship(supp);
            out.push_back(s+= "\n");
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return supp;
}
esploratore insert_esploratore(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    esploratore e;
    while(!status) {
        try {
            std::cout << "Inserisci posizione supporto nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            // ottengo e controllo
            a = get_asset(coords_vec, 'e');
            center = get_center(coords_vec);
            e = esploratore( center); 
            dg.insert_ship(e);
            out.push_back(s += "\n");
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return e;
}

void giocatore_vs_computer() {
    defense_grid dg_human;
    defense_grid dg_bot;
    std::string s;

    std::vector<std::string> out;

	corazzata c1 = insert_corazzata("1", dg_human, out);	
    corazzata c2 = insert_corazzata("2", dg_human, out);	
    corazzata c3 = insert_corazzata("3", dg_human, out);	
	//std::cout << dg_human;
    supporto s1 = insert_supporto("1", dg_human, out); 
    supporto s2 = insert_supporto("2", dg_human, out); 
    supporto s3 = insert_supporto("3", dg_human, out);   
    //std::cout << dg_human;
    esploratore e1 = insert_esploratore("1", dg_human, out);
    esploratore e2 = insert_esploratore("2", dg_human, out);

    std::cout << dg_human;
      
    // bot
    // inizio inserimento barche casuale
    // creo 8 navi per avere 8 oggetti diversi e non avere problemi con la griglia


    corazzata bot_c1 = create_corazzata(dg_bot, out);
    corazzata bot_c2= create_corazzata(dg_bot, out);
    corazzata bot_c3= create_corazzata(dg_bot, out);
    supporto bot_s1 = create_supporto(dg_bot, out);
    supporto bot_s2 = create_supporto(dg_bot, out);
    supporto bot_s3 = create_supporto(dg_bot, out);
    esploratore bot_e1 = create_esploratore(dg_bot, out);
    esploratore bot_e2 = create_esploratore(dg_bot, out);

    attack_grid ag_bot(dg_human);
    attack_grid ag_human(dg_bot);
    player human(dg_human, ag_human);
    player bot_(dg_bot, ag_bot);
    

    int turni_max = 20;
    
    // o finiscoo i turni oppure una delle due griglie non ha più barche
    while(turni_max > 0 || dg_human.is_empty() || dg_bot.is_empty()) {
        std::cout << "Coordinate per l'azione che vuoi eseguire \n";
        std::getline(std::cin, s);

        // mossa del player e inserimento su out
        if(s == "AA AA") {
            // sistemare sta parte o tenere continue?
            ag_human.reset_enemy_pos();
            continue;
        } else if(s == "XX XX") {
            std::cout << human;
            continue;
        } else {
            try {
                human.make_move(s);    
                out.push_back(s += "\n");
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
                continue;
            }
        }
        // controllo se human ha vinto
        if(dg_bot.is_empty()) break;

        // il bot fa la mossa e la inserisco su out
        out.push_back(bot_.rnd_move());

        // controllo se il bot ha vinto
        if(dg_human.is_empty()) break;
        /* std::cout << "Griglia giocatore 1:"<< std::endl << human;
        std::cout << "Griglia bot:"<< std::endl << bot_; */
        turni_max--;
    } 
     std::ofstream outfile ("file_log_pc.txt");

    for(std::string row : out) {
        outfile << row;
    }

    outfile.close();
}