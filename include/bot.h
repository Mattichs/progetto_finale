/*  
    Bastianello Mattia 
*/
#ifndef BOT_H
#define BOT_H

#include "grid/defense_grid.hpp"
#include "grid/attack_grid.hpp"
#include "utility.h"

/* 
    bot avrà un vector di string per memorizzare tutte le mosse
    vector.push <- ships[choice] second_coord
    alla fine nel main richiamo questo metodo e lo butto nel file di log

    però anche il secondo bot, quindi i metodi rnd move adesso mi restituiscono 
    una stringa con le mosse da mettere nel file di log
*/

class bot {
    defense_grid dg;
    attack_grid ag;
    public:
        bot(defense_grid& dg_, attack_grid& ag_) : dg{dg_}, ag{ag_} {}
        std::string rnd_move();
        void print_grid();
        std::vector<std::string> get_text();

        void get_pos() {
            std::cout << dg.get_pos(2,2) << std::endl;
        }

        friend std::ostream& operator << (std::ostream& os,  bot& bot_) {
            os << "Griglia di difesa" << "\t \t \t" << "Griglia di attacco \n"; 
            for(int i = 0; i < 12; i++){
                if(i < 9) {
                    os << (char)(i + 'A') << " ";
                } else {
                    os << (char)(i + 2 + 'A') << " ";
                }     
                for(int j = 0 ; j < 12; j++){
                    os << bot_.dg.get_pos(i,j) << "  ";
                }
                os << "\t";
                if(i < 9) {
                    os << (char)(i + 'A') << " ";
                } else {
                    os << (char)(i + 2 + 'A') << " ";
                } 
                for(int j = 0 ; j < 12; j++){
                    os << bot_.ag.get_pos(i,j) << "  ";
                }
                os << '\n';
            }
            os << "  ";
            for(int i = 0; i < 12; i++) {
                if( i < 8) {
                    os << i + 1 << "  ";
                } else {
                    os << i + 1 << " ";
                }
            }
            os << "\t  ";
            for(int i = 0; i < 12; i++) {
                if( i < 8) {
                    os << i + 1 << "  ";
                } else {
                    os << i + 1 << " ";
                }
            } 
            os << "\n";
            return os; 
        }
};


#endif