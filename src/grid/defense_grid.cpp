#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/defense_grid.hpp"
#include <stdexcept>
#include <set>

defense_grid::defense_grid(){
    water = empty();
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=&water;
    }
}//end constructor defense_grid

std::set<ship*> defense_grid::ship_in_range(coords& c){
    std::set<ship*> ships;
    
    if(!valid_box(c)) throw std::invalid_argument("");

    else{
    for(int i = 0; i < 3; i++){ //righe
        for(int j = 0; j < 3; j++){ //colonne
            coords box = {i,j};
            if(valid_box(box)){
                if(is_ship(box)){
                    ships.insert(get_ship(box));
                }
            }
        }
    }
    }
    return ships;
}

std::vector<coords> defense_grid::enemy_ships(coords& c){
    std::vector<coords> positions;

    if(!valid_box(c)) throw std::invalid_argument("");

    else{
        for(int i = 0; i < 3; i++){ //righe
            for(int j = 0; j < 3; j++){ //colonne
                coords box = {i,j};
                if(valid_box(box)){
                    if(is_ship(box)){
                        positions.push_back(box);
                    }
                }
            }
        }
    }
    return positions;
}

bool defense_grid::is_ship(coords& c){
    bool res=false;
    try{
        res=(get_ship(c)->get_alias()=='C'||get_ship(c)->get_alias()=='E'||get_ship(c)->get_alias()=='S');
    }catch(const char& e){
         throw std::invalid_argument("coordinata non valida");
    }
    return res;
}//end is_ship

void defense_grid::insert_ship(ship& s){
    coords center = s.get_center();
    std::cout << "insert_ship " << center.first << "," << center.second << std::endl;
    asset asset = s.get_way();
    //if(asset == asset::Horizontal) std::cout << "hor" << std::endl;
    //else std::cout << "ver" << std::endl;
    short length = s.get_length();
    //std::cout << length << std::endl;
    std::vector<coords> pos = get_position(center, length, asset);
    for(coords el : pos){
        std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el))
            throw std::invalid_argument("nave presente nel punto scelto");
        
        matrix[el.first][el.second]=&s;
    }
}

ship* defense_grid::get_ship(coords& c){
    return matrix[c.first][c.second];
}

char defense_grid::ship_at(coords& c){
    ship* s = get_ship(c);
    coords x = s->get_center();
    return s->print(c,x);
}

//this function returns true if a ship is hitted(you can hit the same part of a ship more then one time), false if the player misses
bool defense_grid::fire(coords& c){
    /* if(is_ship(c)){
        get_ship(c)->get_hit(c);
        return true;
    }
    return false; */
    if(is_ship(c)){
        ship* s=get_ship(c);
        s->get_hit(c);
        if( s->is_dead())
            clear_position(*s);
        return true;
    }
    return false;
}//end fire 

//returns the new center of the ship , or the old one if the position is already occupied
void defense_grid::move(coords& start, coords& end){
    ship* s = get_ship(start); 
    if(s->get_alias()!='S'&& s->get_alias()!='E')
        throw std::invalid_argument("tipo di nave non valida");
    coords center = s->get_center();
    asset asset = s->get_way();
    short length = s->get_length();
    std::vector<coords> pos = get_position(center, length, asset);
    std::vector<coords> new_pos = get_position(end, length, asset);
    for(coords el : new_pos){
        std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el))
            throw std::invalid_argument("");
        matrix[el.first][el.second] = s;
    }
    clear_position(*s);
    s->set_center(end);
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
        if( i < 9) {
            os << " " << i + 1 << "  ";
        } else {
            os << i + 1 << "  ";
        }
        for(int j=0;j<12;j++){
            coords c = coords(i,j);
            if(dg.is_ship(c))
                os<<dg.ship_at(c)<<" ";
            else
                os<<dg.matrix[i][j]->get_alias()<<" ";
        }
        
        os<<'\n';
    }
    os << "    ";
    for(unsigned int i = 0; i < 12; i++) {
            os << (char)(i + 'A') << " ";
    }
    os << "\n";
    return os;
}