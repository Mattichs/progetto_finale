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

// insert ship, need to handle invalid_argument
void defense_grid::insert_ship(ship& s){
    coords center = s.get_center();
    std::cout << "Centro nave insert_ship(): " << center.first << "," << center.second << std::endl;
    asset asset = s.get_way();
    //if(asset == asset::Horizontal) std::cout << "hor" << std::endl;
    //else std::cout << "ver" << std::endl;
    short length = s.get_length();
    //std::cout << length << std::endl;
    std::vector<coords> pos = get_position(center, length, asset);
    for(coords el : pos){
        //std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el))
            throw std::invalid_argument("Nella posizione scelta è già presente una nave!");
        matrix[el.first][el.second]=&s;
        std::cout << "Centro nave insert_ship() for: " << matrix[el.first][el.second]->get_center().first << "," << matrix[el.first][el.second]->get_center().second << std::endl;
    }
}

// give position to get ship&
ship& defense_grid::get_ship(coords c){
    return *matrix[c.first][c.second];
}



//this function returns true if a ship is hitted(you can hit the same part of a ship more then one time), false if the player misses
bool defense_grid::fire(coords c){
    if(is_ship(c)){
        ship s = get_ship(c);
        s.get_hit(c);
        if( s.is_dead())
            clear_position(s);
        return true;
    }
    return false;
}//end fire 

//returns the new center of the ship , or the old one if the position is already occupied
void defense_grid::move(coords p, coords c){
    ship s=get_ship(c);
    if(s.get_alias()!='S'&&s.get_alias()!='E')
        throw std::invalid_argument("tipo di nave non valida");
    coords center = s.get_center();
    asset asset = s.get_way();
    short length = s.get_length();
   
    std::vector<coords> new_pos = get_position(p, length, asset);
    for(coords el : new_pos){
        std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el))
            throw std::invalid_argument("dioporco");
        matrix[el.first][el.second]=&s;
    }
    clear_position(s);
    s.set_center(p);
            
}

void defense_grid::clear_position(ship& s){
    coords center = s.get_center();
    asset asset = s.get_way();
    short length = s.get_length();
    std::vector<coords> pos = get_position(center, length, asset);
    for(coords el : pos){
        matrix[el.first][el.second]=&water;
    }
}

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
