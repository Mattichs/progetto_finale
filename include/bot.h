#ifndef BOT_H
#define BOT_H

#include "./grid/defense_grid.hpp"
#include <vector>

class bot {
    defense_grid dg;
    std::vector<ship*> total_ship;

public:
    bot() {}
    bot(defense_grid& def) : dg{def}{
        get_total_ship();
    };    
    void get_total_ship();
};

#endif