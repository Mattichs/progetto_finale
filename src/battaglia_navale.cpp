/* 
    BASTIANELLO MATTIA
*/
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/utility.h"
#include "../include/ship/insert_util.h"
#include "../include/player.h"

#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cstring> 

/* 
    argc as 'int' --> contains number of element passed in command line
    argv as 'char* []' --> contains the elements
    argv[0] is the name of the program
*/

/**
 * @brief human vs bot, human inserts ship from user input. bot makes random insert. Then choose who starts and play the game
 * 
 */
void giocatore_vs_computer();

/**
 * @brief computer vs computer, inserts and moves are random
 * 
 */
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

void computer_vs_computer() {
    defense_grid dg_bot1;
    defense_grid dg_bot2;
    attack_grid ag_bot1(dg_bot2);
    attack_grid ag_bot2(dg_bot1);
    
    // ship insert random first bot

    std::vector<std::string> out;

    corazzata bot1_c1 = create_corazzata(dg_bot1, out);
    corazzata bot1_c2= create_corazzata(dg_bot1, out);
    corazzata bot1_c3= create_corazzata(dg_bot1, out);

    supporto bot1_s1 = create_supporto(dg_bot1, out);
    supporto bot1_s2 = create_supporto(dg_bot1, out);
    supporto bot1_s3 = create_supporto(dg_bot1, out);
 
    esploratore bot1_e1 = create_esploratore(dg_bot1, out);
    esploratore bot1_e2 = create_esploratore(dg_bot1, out);

    // ship insert random second bot

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
    // print to output file
    std::ofstream outfile ("file_log_cc.txt");

    for(std::string row : out) {
        outfile << row;
    }
    outfile.close();    
}

void giocatore_vs_computer() {
    defense_grid dg_human;
    defense_grid dg_bot;
    std::string s;

    std::vector<std::string> out;

    // human insert
	corazzata c1 = insert_corazzata("1", dg_human, out);	
    corazzata c2 = insert_corazzata("2", dg_human, out);	
    corazzata c3 = insert_corazzata("3", dg_human, out);	
    std::cout << dg_human;
    supporto s1 = insert_supporto("1", dg_human, out); 
    supporto s2 = insert_supporto("2", dg_human, out); 
    supporto s3 = insert_supporto("3", dg_human, out);   
    std::cout << dg_human;
    esploratore e1 = insert_esploratore("1", dg_human, out);
    esploratore e2 = insert_esploratore("2", dg_human, out);
    std::cout << dg_human;
      
    // bot
    // ship insert is random

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
    

    int turni_max = 30;
    // choose who start
    int choice = rand() % 20;

    bool can_bot_make_move = true;
    while(turni_max > 0) {
        if(choice % 2 == 0) {
            // player starts
            std::cout << "Coordinate per l'azione che vuoi eseguire \n";
            std::getline(std::cin, s);

            // player move and save moves on out
            if(s == "AA AA") {
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
            // check if humans wins
            if(dg_bot.is_empty()) break;

            // bot make moves and save on out
            out.push_back(bot_.rnd_move());
            std::cout << "Il bot ha eseguito la sua mossa \n";

            // check if bot wins
            if(dg_human.is_empty()) break;

        } else {
            // robot starts
            // bot make moves and save on out
            if(can_bot_make_move) {
                out.push_back(bot_.rnd_move());
                std::cout << "Il bot ha eseguito la sua mossa \n";
            }
            
            // check if bot wins
            if(dg_human.is_empty()) break;

            std::cout << "Coordinate per l'azione che vuoi eseguire \n";
            std::getline(std::cin, s);

            // player move and save moves on out
            if(s == "AA AA") {
                ag_human.reset_enemy_pos();
                can_bot_make_move = false;
                continue;
            } else if(s == "XX XX") {
                std::cout << human;
                can_bot_make_move = false;
                continue;
            } else {
                try {
                    human.make_move(s);    
                    out.push_back(s += "\n");
                    can_bot_make_move = true;
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                    continue;
                }
            }
            // check if human wins
            if(dg_bot.is_empty()) break;
            
        }  
        turni_max--;
    }
    
    // print to output file
    std::ofstream outfile ("file_log_pc.txt");

    for(std::string row : out) {
        outfile << row;
    }

    outfile.close();
}