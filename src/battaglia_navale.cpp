/* 
    Bastianello Mattia
*/
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/utility.h"
#include "../include/bot.h"
#include "../include/ship/movement.h"
#include "../include/ship/ship.h"
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
esploratore create_esploratore(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    
    esploratore e;
    while(!status) {
        try { 
            rnd = generate_rnd_coords();
            e = esploratore(asset::Horizontal, rnd); 
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
/*
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


    bot bot1(dg_bot1, ag_bot1);
    bot bot2(dg_bot2, ag_bot2);

    int turni_max = 20;
    std::cout << dg_bot1;
    while(turni_max > 0) {
        out.push_back(bot1.rnd_move());
        out.push_back(bot2.rnd_move());
        turni_max--;
    }   
    std::ofstream outfile ("test.txt");

    for(std::string row : out) {
        outfile << row;
    }
    outfile.close();
*/
}

// per il momento l'utente deve essere sicuro che l'inserimento sia corretto
void giocatore_vs_computer() {
    // variabili utili
    defense_grid dg_player;
    defense_grid dg_bot;
    std::string s;
    std::vector<coords> coords_vec;

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("clear");

	/*
	inserimento corazzate     
	*/ 

	std::cout << dg_player;
	corazzata c1 = insert_corazzata("prima corazzata");	
	dg_player.insert_ship(c1);

	std::cout << dg_player;
	corazzata c2 = insert_corazzata("seconda corazzata");
	dg_player.insert_ship(c2);

	std::cout << dg_player;
	corazzata c3 = insert_corazzata("terza corazzata");
	dg_player.insert_ship(c3);

	std::cout << dg_player;
	supporto s1 = insert_supporto("primo supporto");
	dg_player.insert_ship(s1);

	std::cout << dg_player;
	supporto s2 = insert_supporto("secondo supporto");
	dg_player.insert_ship(s2);

	std::cout << dg_player;
	supporto s3 = insert_supporto("terzo supporto");
	dg_player.insert_ship(s3);

	std::cout << dg_player;
	esploratore e1 = insert_esploratore("primo esploratore");
	dg_player.insert_ship(e1);

	std::cout << dg_player;
	esploratore e2 = insert_esploratore("secondo esploratore");
	dg_player.insert_ship(e2);

	std::cout << dg_player;

    // bot
    // inizio inserimento barche casuale
    // creo 8 navi per avere 8 oggetti diversi e non avere problemi con la griglia

    // TODO stampare il log (aggiungere parametro& e fare push_back)
    std::vector<std::string> out_bot;

    corazzata bot_c1 = create_corazzata(dg_bot, out_bot);
    corazzata bot_c2= create_corazzata(dg_bot, out_bot);
    corazzata bot_c3= create_corazzata(dg_bot, out_bot);

    supporto bot_s1 = create_supporto(dg_bot, out_bot);
    supporto bot_s2 = create_supporto(dg_bot, out_bot);
    supporto bot_s3 = create_supporto(dg_bot, out_bot);
 
    esploratore bot_e1 = create_esploratore(dg_bot, out_bot);
    esploratore bot_e2 = create_esploratore(dg_bot, out_bot);

    attack_grid ag_bot(dg_player);
    bot bot_(dg_bot, ag_bot);
    
    std::cout << dg_bot;

    attack_grid ag_player(dg_bot);

    int turni_max = 0;
    
    while(turni_max < 20) {
        
		std::cin.ignore();
		std::cout << "Coordinate per l'azione che vuoi eseguire \n";
        std::getline(std::cin, s);
		
        // il player vuole togliere le Y
        if(s == "YY YY") {
            // sistemare sta parte
            ag_player.reset_enemy_pos();
            continue;
        } else {
            coords_vec = coords_translation(s);

			std::cout << "Suca scimmia " << coords_vec[0].first << " , " << coords_vec[0].second << std::endl;			
 
            // switch per capire che barca ha selezionato il player
            switch(dg_player.get_ship(coords_vec[0])->get_alias()) {
                case 'C':
                    ag_player.fire(coords_vec[1], dg_bot);
                break;
                case 'S':
                    dg_player.heal_ships(coords_vec[0], coords_vec[1]);
                break;
                case 'E':
                    dg_player.move(coords_vec[0], coords_vec[1]);
                    ag_player.enemy_ships(coords_vec[1], dg_bot);
                break;
            }
			std::cout << std::endl << turni_max << std::endl;
        }
        
        
        bot_.rnd_move(dg_player);

        std::cout << "PLAYER \n" << dg_player << ag_player;

        std::cout << "BOT: \n" << dg_bot << ag_bot;
        turni_max++;
    
		std::cout << std::endl << turni_max << std::endl;
	}
	std::cout << std::endl << turni_max << std::endl;
}
