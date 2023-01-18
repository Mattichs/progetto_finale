//@FedericoCognolatto
#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/attack_grid.hpp"
#include <stdexcept>
attack_grid::attack_grid( defense_grid& dg): dgrid(dg){
    //initializes the grid
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++)
                matrix[i][j]=' ';
    }
}//end attack_grid's constructor

bool attack_grid::fire(coords& c){
    //calls defense_grid's fire
    if(dgrid.fire(c)){
        //hit
        matrix[c.first][c.second]='X';
        return true;
    }
    //water
    matrix[c.first][c.second]='O';
    return false;
}//end fire

void attack_grid::enemy_ships(coords& c){
    if(!valid_box(c)) 
        throw std::invalid_argument("Posizione non valida!");
    for(int i = 0; i < 5; i++){ //rows
        for(int j = 0; j < 5; j++){ //columns
            short x = c.first - 2 + i;
            short y = c.second - 2 + j;
            coords box = {x,y};
            //checks if the position is valid
            if(valid_box(box)){
                if(dgrid.is_ship(box)){
                    bool res=false;
                    for(coords el:enemy_positions)
                            res=((matrix[box.first][box.second])=='X');
                    //res is true if the spotted ship has been already hit
                    if(!res)
                        enemy_positions.push_back(box);
                }
            }
        }
    }
    //change the values at the enemy's positons into Y
    for(coords el : enemy_positions){
        matrix[el.first][el.second]='Y';
    } 
}//end enemy_ships

 void attack_grid::reset_enemy_pos(){
    for(coords el:enemy_positions){
        //replaces all the Y with ~
        if(matrix[el.first][el.second]!='X')
            matrix[el.first][el.second]=' ';
    }
    enemy_positions.clear();
 }//end reset_enemy_pos


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
}//end <<
