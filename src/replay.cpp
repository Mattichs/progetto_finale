/* 
    BASTIANELLO MATTIA
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unistd.h>

#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/player.h"
#include "../include/ship/insert_util.h"


/**
 * @brief print replay on terminal with a 5 sec delay
 * 
 * @param file_logas as 'char*'
 */
void replay_terminale(char* file_log);

/**
 * @brief print replay in a file
 * 
 * @param file_log as 'char*'
 * @param file_output as 'char*'
 */
void replay_file(char* file_log, char* file_output);

/**
 * @brief get argument from cmd line
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
    if(argc == 1) std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    else if(argc == 3 && strcmp(argv[1], "-v") == 0) {
            std::cout << "Hai scelto il replay su terminale \n";
            /* 
                replay on terminal
            */
            replay_terminale(argv[2]);
    } else if(argc == 4 && strcmp(argv[1], "-f") == 0) {
            std::cout << "Hai scelto il replay su file \n";
            /* 
                replay on file
            */
            replay_file(argv[2], argv[3]);
    } else {
        std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    }

    return 0;
}

void replay_file(char* file_log, char* file_output) {

    std::ifstream log_file;
    // try to open input file
    try {
        log_file.open(file_log);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    std::string s;
    // if file is open print on file
    if(log_file.is_open()) {
        // read all file lines

        defense_grid dg_player1;
        defense_grid dg_player2;
        attack_grid ag_player1(dg_player2);
        attack_grid ag_player2(dg_player1);
        
        // first player
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
        
        // second player
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

        std::ofstream out(file_output);
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        // change output to the file_output
        std::cout.rdbuf(out.rdbuf()); 
        
        while(std::getline(log_file, s)) {
           std::cout << "Griglia giocatore 1:"<< std::endl << player1;
           std::cout << "Griglia giocatore 2:"<< std::endl << player2;
           player1.make_move(s);
           // if player 1 wins break break;
           if(dg_player2.is_empty()) break;
           std::getline(log_file, s);
           player2.make_move(s);
        }
        std::cout << "Griglia giocatore 1:"<< std::endl << player1;
        std::cout << "Griglia giocatore 2:"<< std::endl << player2;
               
        // reset to standard output
        std::cout.rdbuf(coutbuf); 
        out.close();
    } else { 
        std::cout << "Impossibile aprire il file";
    }
    log_file.close();
}


void replay_terminale(char* file_log) {
    std::ifstream log_file;
    try {
        log_file.open(file_log);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::string s;
    // if file is open correctly do replay else thow std::invalid_argument
    if(log_file.is_open()) {
        // read all file lines

        defense_grid dg_player1;
        defense_grid dg_player2;
        attack_grid ag_player1(dg_player2);
        attack_grid ag_player2(dg_player1);
        
        // first player
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
        
        // second player
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
        while(std::getline(log_file, s)) {
            player1.make_move(s);
            if(dg_player2.is_empty()) {
                // if player 1 wins break
                std::cout << "Griglia giocatore 1:"<< std::endl << player1;
                std::cout << "Griglia giocatore 2:"<< std::endl << player2;
                break;
            }
            std::getline(log_file, s);
            player2.make_move(s);
            std::cout << "Griglia giocatore 1:"<< std::endl << player1;
            std::cout << "Griglia giocatore 2:"<< std::endl << player2;
            sleep(5);
        }
        
    } else { 
        std::cout << "Impossibile aprire il file";
    }
    log_file.close();
}