/* 
    Bastianello Mattia
*/

#include <iostream>
#include <fstream>
#include <string>

#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include "../include/utility.h"

using namespace std;

int main() {
    ifstream log_file;
    log_file.open("test.txt");
    string s;
    // verifico che il file sia stato aperto correttamente
    if(log_file.is_open()) {
        // leggo tutte le linee del file

        defense_grid dg;
        attack_grid ag(dg);
        std::vector<coords> coords_vec;
        coords center;
        asset ass;
        getline(log_file, s);
        corazzata c;
        for(int i = 0; i < 3; i++) {
            coords_vec = coords_translation(s); 
            center = get_center(coords_vec);
            print_coords(center);
            ass = get_asset(coords_vec);
            if(ass ==asset::Horizontal) std::cout << "Hor \n";
            else std::cout << "Ver \n";
            c = corazzata(get_asset(coords_vec), center);
            dg.insert_ship(c);
            getline(log_file, s);
        }
        supporto supp;
        for(int i = 0; i < 3; i++) {
            coords_vec = coords_translation(s); 
            center = get_center(coords_vec);
            supp = supporto(get_asset(coords_vec), center);
            dg.insert_ship(supp);
            getline(log_file, s);
        }
        esploratore e;
        for(int i = 0; i < 2; i++) {
            std::cout << "sott \n";
            coords_vec = coords_translation(s); 
            center = get_center(coords_vec);
            e = esploratore(center);
            dg.insert_ship(e);
            getline(log_file, s);
        }
        // redirect to out.txt file
        std::ofstream out("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); 
        
        std::cout << dg;
        std::cout << ag;
        // reset to standard output
        std::cout.rdbuf(coutbuf); 
        while(getline(log_file, s)) {
            
            /* 
                aspetto i comandi per fare giocare la parita

                aspetto i print delle vare griglie
            */
           std::cout << s << std::endl;
        }
    } else { 
        cout << "Impossibile aprire il file";
    }
    log_file.close();

    return 0;
}