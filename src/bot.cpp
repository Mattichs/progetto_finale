/*  
    Bastianello Mattia
*/
#include "../include/bot.h"
#include <cstdlib>

std::vector<std::string> bot::get_text() {
    return text;
}

// bot make random move
void bot::rnd_move() {
    //srand ( time(NULL) );
    std::cout << "Random move \n"; 
    std::vector<coords> all_center = dg.get_ships();
    int choice = rand() % all_center.size();
    //print_coords(all_center[choice]);
    bool status = false;
    coords second_coord;
    while(!status) {
        try {
            second_coord = generate_rnd_coords();
            //print_coords(second_coord);
            if(dg.get_ship(all_center[choice])->get_alias() == 'C') {
                // corazzata
                std::cout << "sparo \n"; // ???
                print_coords(all_center[choice]);
                print_coords(second_coord);
                ag.fire(second_coord);
                text.push_back(to_string_helper(all_center[choice], second_coord));
            } else if (dg.get_ship(all_center[choice])->get_alias() == 'E') {
                // esploratore
                std::cout << "spotto \n";
                dg.move(all_center[choice], second_coord);
                //std::cout << "sto muovendo il sottomarino che aveva centro: ";
                //print_coords(all_center[choice]);
                ag.enemy_ships(second_coord);
                text.push_back(to_string_helper(all_center[choice], second_coord));
                print_coords(all_center[choice]);
                print_coords(second_coord);
            } else {
                // supporto
                std::cout << "curo \n";
                dg.heal_ships(all_center[choice], second_coord);
                text.push_back(to_string_helper(all_center[choice], second_coord));
                print_coords(all_center[choice]);
                print_coords(second_coord);
            }
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void bot::print_grid() {
    std::cout << dg;
    //std::cout << ag;
}