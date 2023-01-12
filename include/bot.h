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
    defense_grid& dg;
    attack_grid& ag;
    public:
        bot(defense_grid& dg_, attack_grid& ag_) : dg{dg_}, ag{ag_} {}
        void rnd_move();
        void print_grid();
};

#endif