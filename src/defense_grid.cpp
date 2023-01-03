#include "../include/ships.h"
#include "../include/movement.h"
#include "../include/defense_grid.hpp"
#include <stdexcept>
#include <vector>

defense_grid::defense_grid( std::vector<corazzata>& c, std::vector<supporto>& s, std::vector<esploratore>& e): battleships(c), healers(s),scouts(e){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=' ';
    }
    try{        
        for(corazzata el:battleships){
            coords center=el.get_center();
            switch(short way=el.get_way()){
                case(0):
                    matrix[center.first][center.second]='C'; 
                    matrix[center.first+1][center.second]='C';
                    matrix[center.first+2][center.second]='C';
                    matrix[center.first-1][center.second]='C';
                    matrix[center.first-2][center.second]='C';
                    break;      
                case(1):
                     matrix[center.first][center.second]='C'; 
                    matrix[center.first][center.second+1]='C';
                    matrix[center.first][center.second+2]='C';
                    matrix[center.first][center.second-1]='C';
                    matrix[center.first][center.second-2]='C';
                    break;      
            }
        }
    }catch(const char& e){
        std::cout<<"posizione corazzate non valida";
    }
    try{        
        for(supporto el:healers){
            coords center=el.get_center();
            switch(short way=el.get_way()){
                case(0):
                    matrix[center.first][center.second]='S'; 
                    matrix[center.first+1][center.second]='S';
                    matrix[center.first-1][center.second]='S';
                    break;      
                case(1):
                     matrix[center.first][center.second]='S'; 
                    matrix[center.first][center.second+1]='S';
                    matrix[center.first][center.second-1]='S';
                    break;      
            }
        }
    }catch(const char& e){
        std::cout<<"posizione navi supporto non valida";
    }
    try{        
        for(esploratore el:scouts){
            coords center=el.get_center();
            matrix[center.first][center.second]='E';
        }
    }catch(const char& e){
        std::cout<<"posizione scouts non valida";
    }

}//fine costruttore defense_grid

bool defense_grid::is_ship(coords c){
    bool res=false;
    try{
        res=(matrix[c.first][c.second]=='C'||matrix[c.first][c.second]=='E'||matrix[c.first][c.second]=='S'||matrix[c.first][c.second]=='c'||matrix[c.first][c.second]=='e'||matrix[c.first][c.second]=='s');
    }catch(const char& e){
        std::cout<<"coordinata non valida";
    }
    return res;
}//fine is_ship
