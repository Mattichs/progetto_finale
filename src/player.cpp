/*  
    BASTIANELLO MATTIA
*/
#include "../include/player.h"

// player makes random move
std::string player::rnd_move() {
    //std::cout << "Random move \n"; 
    std::vector<coords> all_center = dg.get_ships();
    int choice = rand() % all_center.size();
    bool status = false;
    coords second_coord;
    while(!status) {
        try {
            second_coord = generate_rnd_coords();
            if(dg.get_ship(all_center[choice])->get_alias() == 'C') {
                // corazzata
                //std::cout << "sparo \n"; 
                ag.fire(second_coord);
            } else if (dg.get_ship(all_center[choice])->get_alias() == 'E') {
                // esploratore
                //std::cout << "spotto \n";
                dg.move(all_center[choice], second_coord);
                ag.enemy_ships(second_coord);
            } else {
                // supporto
                //std::cout << "curo \n";
                dg.heal_ships(all_center[choice], second_coord);
            }
            status = true;
        }
        catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return two_coords_to_string(all_center[choice], second_coord);
}

void player::make_move(std::string s) {
    std::vector<coords> coords_vec;
    coords_vec = coords_translation(s); 
    if(!dg.is_center(coords_vec[0])) throw std::invalid_argument("inserisci il centro di una nave perfavore");
    // switch per capire che barca ha selezionato il player
    switch(dg.get_ship(coords_vec[0])->get_alias()) {
        case 'C':
            if(ag.fire(coords_vec[1])) {
                std::cout << "COLPITO! \n";
            } else {
                std::cout << "ACQUA! \n";
            }
        break;
        case 'S':
            dg.heal_ships(coords_vec[0], coords_vec[1]);
        break;
        case 'E':
            dg.move(coords_vec[0], coords_vec[1]);
            ag.enemy_ships(coords_vec[1]);
        break;
    }
    
}

std::ostream& operator << (std::ostream& os,  player& p) {
    os << "Griglia di difesa";
    for(int i = 0 ; i <25; i++) {
        os << " ";
    }
    os<< "Griglia di attacco \n"; 
    for(int i = 0; i < 12; i++){
        if(i < 9) {
            os << (char)(i + 'A') << " ";
        } else {
            os << (char)(i + 2 + 'A') << " ";
        }     
        for(int j = 0 ; j < 12; j++){
            os << p.dg.get_pos(i,j) << "  ";
        }
        os << "    ";
        if(i < 9) {
            os << (char)(i + 'A') << " ";
        } else {
            os << (char)(i + 2 + 'A') << " ";
        } 
        for(int j = 0 ; j < 12; j++){
            os << p.ag.get_pos(i,j) << "  ";
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
    os << "       ";
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