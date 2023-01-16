/*  
    Bastianello Mattia 
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "grid/defense_grid.hpp"
#include "grid/attack_grid.hpp"
#include "utility.h"

/*  
    la classe player ha come membri due reference alle griglie di attacco del giocatore che può essere umano, ma anche un bot
    come funzioni invece abbiamo la possibilità di effettuare una mossa casuale oppure una mossa scelta dall'utente
*/
class player {
    defense_grid& dg;
    attack_grid& ag;
    public:
        player(defense_grid& dg_, attack_grid& ag_) : dg{dg_}, ag{ag_} {}
        /* 
            il player sceglie delle coordinate a caso e prova a fare una mossa finchè non ci riesce
            quando la mossa viene eseguita ritorno la mossa scelta
        */
        std::string rnd_move();
        /*  
            il player fa una mossa specifica date due coordinate
            passo come parametro una stringa con le due coordinate
        */
        void make_move(std::string s);  

        friend std::ostream& operator << (std::ostream& os,  player& p);
};


#endif