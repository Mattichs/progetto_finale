#include "../include/grid.hpp"
grid::grid(){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=' ';
    }

}
grid::~grid(){

}

bool grid::fire(coords c){
    return false;
}
