//@FedericoCognolatto
#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/attack_grid.hpp"
#include <stdexcept>
attack_grid::attack_grid( defense_grid& dg): dgrid(dg){
        for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]='#';
    }
}//fine costruttore attack_grid

bool attack_grid::fire(coords c){
    if(dgrid.fire(c)){
        matrix[c.first][c.second]='X';
        return true;
    }
    matrix[c.first][c.second]='O';
    return false;
}

void attack_grid::enemy_ships(coords& c){
    if(!valid_box(c)) throw std::invalid_argument("");

    for(int i = 0; i < 5; i++){ //righe
        for(int j = 0; j < 5; j++){ //colonne
            short x = c.first - 2 + i;
            short y = c.second - 2 + j;
            coords box = {x,y};
            if(valid_box(box)){
                if(dgrid.is_ship(box)){
                    bool res=false;
                    for(coords el:enemy_positions)
                            res=((box.first==el.first&&box.second==el.second)||matrix[box.first][box.second]=='X');
                    if(!res)
                        enemy_positions.push_back(box);
                }
            }
        }
    }
    for(coords el : enemy_positions){
        std::cout << "Y \n"; 
        matrix[el.first][el.second]='Y';
    } 
}

 void attack_grid::reset_enemy_pos(){
    for(coords el:enemy_positions){
        if(matrix[el.first][el.second]!='X')
            matrix[el.first][el.second]='~';
    }
    enemy_positions.clear();
 }


std::ostream& operator <<(std::ostream& os,const  attack_grid& ag){
    for(int i=0;i<12;i++){
        if(i < 9) {
            os << (char)(i + 'A') << " ";
        } else {
            os << (char)(i + 2 + 'A') << " ";
        }     
        for(int j=0;j<12;j++){
                os << ag.matrix[i][j] << "  ";
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
    os << "\n";
    return os; 
}
