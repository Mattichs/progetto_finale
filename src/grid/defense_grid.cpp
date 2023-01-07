//@FedericoCognolatto
#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/defense_grid.hpp"
#include <stdexcept>

defense_grid::defense_grid(){
    water=empty();
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=&water;
    }

}//end constructor defense_grid

bool defense_grid::is_ship(coords c){
    bool res=false;
    try{
        res=(matrix[c.first][c.second]->get_alias()=='C'||matrix[c.first][c.second]->get_alias()=='E'||matrix[c.first][c.second]->get_alias()=='S');
    }catch(const char& e){
         throw std::invalid_argument("coordinata non valida");
    }
    return res;
}//end is_ship

void defense_grid::insert_ship(ship& s){
    coords center = s.get_center();
    asset asset = s.get_way();
    if(asset == asset::Horizontal) std::cout << "hor" << std::endl;
    else std::cout << "ver" << std::endl;
    short length = s.get_length();
    std::cout << length << std::endl;
    std::vector<coords> pos = get_position(center, length, asset);
    for(coords el : pos){
        std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el))
            throw std::invalid_argument("dioporco");
        matrix[el.first][el.second]=&s;
    }
}


//this function returns true if a ship is hitted(you can hit the same part of a ship more then one time), false if the player misses
bool defense_grid::fire(coords c){
    if(is_ship(c)){
        matrix[c.first][c.second]->get_hit(c);
        return true;
    }
    return false;
}//end fire 

//returns the new center of the ship , or the old one if the position is already occupied
/*coords defense_grid::move(coords c, ship& s){
    if(i>4)
        throw std::invalid_argument("invalid i");
    //support
    if(i<3){
        supporto ship= healers[i];
        coords center=ship.get_center();
        if(asset::Vertical==ship.get_way()&&!(is_ship(c)||is_ship(coords(c.first+1,c.second))||is_ship(coords(c.first-1,c.second)))&&!ship.is_dead()){
                    matrix[c.first][c.second]=&ship; 
                    matrix[c.first+1][c.second]=&ship;
                    matrix[c.first-1][c.second]=&ship;
                    //clearing old positions
                    matrix[center.first][center.second]=&water; 
                    matrix[center.first+1][center.second]=&water;
                    matrix[center.first-1][center.second]=&water;
                    return c;
           }     
            if(asset::Horizontal==ship.get_way()&&!(is_ship(c)||is_ship(coords(c.first,c.second+1))||is_ship(coords(c.first,c.second-1)))&&!ship.is_dead()){
                     matrix[c.first][c.second]=&ship; 
                    matrix[c.first][c.second+1]=&ship;
                    matrix[c.first][c.second-1]=&ship; 
                    //clearing old positions
                    matrix[center.first][center.second]=&water; 
                    matrix[center.first][center.second+1]=&water;
                    matrix[center.first][center.second-1]=&water; 
                    return c;   
            }
         return ship.get_center(); 
      

    }
    //scout
   esploratore ship=scouts[i-3];
   if(!is_ship(c)&&!ship.is_dead()){
    matrix[c.first][c.second]=&ship;
    matrix[ship.get_center().first][ship.get_center().second]=&water;
   }
    return ship.get_center();
            
}*/

std::ostream& operator <<(std::ostream& os,  defense_grid& dg){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            coords c=coords(i,j);
            if(dg.is_ship(c))
             os<<dg.matrix[i][j]->print(c)<<" ";
            else
                os<<dg.matrix[i][j]->get_alias()<<" ";
        }
         os<<'\n';
    }
    return os;
}
