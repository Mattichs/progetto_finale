//@FedericoCognolatto
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

//returns a vector containing ship pointers
std::vector<ship*> defense_grid::ship_in_range(coords& c){
    std::vector<ship*> ships;
    
    if(!valid_box(c)) throw std::invalid_argument("");

    else{
     for(int i = 0; i < 3; i++){ //righe
        for(int j = 0; j < 3; j++){ //colonne
            short x = c.first - 1 + i;
            short y = c.second - 1 + j;
            coords box = {x,y};
            //checks if the position is valid
            if(valid_box(box)){
                if(is_ship(box)){
                    //checks if the ship has already been found
                    if( get_ship(box)!=get_ship(c)){
                        bool res=false;
                        for(ship* el:ships){
                            std::cout<<(el==get_ship(box))<<'\n';
                            if(el==get_ship(box))
                                res=(el==get_ship(box));
        
                        }
                        if(!res){
                             std::cout<<get_ship(box)<<'\n';
                            ships.push_back(get_ship(box));
                        }
                    }
                }
            }
        }
    }
    }
    std::cout<<ships.size()<<'\n';
    return ships;
}

//checks if the given position contains a ship
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
    asset asset = s.get_way();
    short length = s.get_length();
    // posizioni occupate dalla barca
    std::vector<coords> pos = get_position(center, length, asset);
    
    // prima controllo che non ci siano già presenti navi nelle posizioni della nuova barca
    for(coords el : pos) {
        if(is_ship(el))
            throw std::invalid_argument("nave presente nel punto scelto");
    }
    // inserisco in griglia
    for(coords el : pos) {
        matrix[el.first][el.second]=&s;
    }
    ships.push_back(center);
}

//returns the element of the matrix at a given position
ship* defense_grid::get_ship(coords& c){
    return matrix[c.first][c.second];
}

//retruns a char representing the ship at the given position
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

std::vector<coords> defense_grid::get_ships(){
    return ships;
}

//heal for about 1 hp all the ship in a 3x3 square
void defense_grid::heal_ships(coords& c, coords& final_c){
    // provo a muovere la barca 
    move(c, final_c);
    // creo il quadrato di griglia in cui curare
    std::vector<ship*> ships = ship_in_range(final_c);
    if(ships.size() != 0){
        for(ship* el : ships){
            el->heal();
        }
    }
}


void defense_grid::move(coords& start, coords& end){
    //retrives the ship
    ship* s = get_ship(start); 
    if(s->get_alias()!='S'&& s->get_alias()!='E')
        throw std::invalid_argument("tipo di nave non valida");
    coords center = s->get_center();
    asset asset = s->get_way();
    short length = s->get_length();
    //retrieves old and new positions
    std::vector<coords> pos = get_position(center, length, asset);
    std::vector<coords> new_pos = get_position(end, length, asset);
    //verifies if the new positions aren't occupied
    for(coords el : new_pos){
        //std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el)&&get_ship(el)!=s)
            throw std::invalid_argument("Posizione occupata da un'altra nave");
    }
    clear_position(*s);
    //inserts the ship into the new positions
    for(coords el : new_pos){
        //std::cout << el.first << "," << el.second << std::endl;
        matrix[el.first][el.second] = s;
    }
    ships.push_back(end);
    s->set_center(end);
}

//clears the position of a given ship
void defense_grid::clear_position(ship& s){
    coords center = s.get_center();
    asset asset = s.get_way();
    short length = s.get_length();
    std::vector<coords> pos = get_position(center, length, asset);
    for(coords el : pos){
        matrix[el.first][el.second]=&water;
    }
    //deletes the ship from ships
    for(int i=0;i<ships.size();i++){
        if(center.first==ships[i].first&&center.second==ships[i].second)
            ships.erase(ships.begin()+i);
    }
}

//checks if the given position is the center of a ship
bool defense_grid::is_center(coords& c){
    for(coords el:ships){
        if(el==c)
            return true;
    }
    return false;
}

//checks if the grid contains ships 
bool defense_grid::is_empty(){
    if(ships.size()==0)
        return true;
    return false;
}

std::ostream& operator <<(std::ostream& os,  defense_grid& dg){
    for(int i=0;i<12;i++){
        if(i < 9) {
            os << (char)(i + 'A') << " ";
        } else {
            os << (char)(i + 2 + 'A') << " ";
        }     
        for(int j=0;j<12;j++){
            coords c = coords(i,j);
            if(dg.is_ship(c))
                os << dg.ship_at(c) << "  ";
            else
                os << dg.matrix[i][j]->get_alias() << "  ";
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