#ifndef BOT_H
#define BOT_H

#include "grid/defense_grid.hpp"
#include "grid/attack_grid.hpp"
#include "utility.h"

class bot {
    defense_grid& dg;
    attack_grid& ag;
    public:
        bot(defense_grid& dg_, attack_grid& ag_) : dg{dg_}, ag{ag_} {}
        void rnd_move();
        void print_grid();
};

#endif