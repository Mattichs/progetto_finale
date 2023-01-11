#include "../include/bot.h"
#include <cstdlib>

// bot make random move
void bot::rnd_move() {
    std::cout << "Random move \n"; 
    std::vector<coords> all_center = dg.get_ships();
    int choice = rand() % all_center.size();
    print_coords(all_center[choice]);
    bool status = false;
    coords second_coord;
    while(!status) {
        try {
            second_coord = generate_rnd_coords();
            print_coords(second_coord);
            dg.move(all_center[choice], second_coord);
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void bot::print_grid() {
    std::cout << dg;
}
