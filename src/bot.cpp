/*  
    Bastianello Mattia
*/
#include "../include/bot.h"
#include <cstdlib>


// bot makes random move
std::string bot::rnd_move() {
    std::cout << "Random move \n"; 
    std::vector<coords> all_center = dg.get_ships();
    int choice = rand() % all_center.size();
    bool status = false;
    coords second_coord;
    while(!status) {
        try {
            second_coord = generate_rnd_coords();
            //print_coords(second_coord);
            if(dg.get_ship(all_center[choice])->get_alias() == 'C') {
                // corazzata
                std::cout << "sparo \n"; // ???
                ag.fire(second_coord);
            } else if (dg.get_ship(all_center[choice])->get_alias() == 'E') {
                // esploratore
                std::cout << "spotto \n";
                dg.move(all_center[choice], second_coord);
                ag.enemy_ships(second_coord);
            } else {
                // supporto
                std::cout << "curo \n";
                dg.heal_ships(all_center[choice], second_coord);
            }
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return to_string_helper(all_center[choice], second_coord);
}

void bot::print_grid() {
    std::cout << dg;
    //std::cout << ag;
}