#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/defense_grid.hpp"
#include "../include/utility.h"
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
			short x = c.first - 1 + i;
            short y = c.second - 1 + j;            
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
    if(is_ship(c)){
        ship* s=get_ship(c);
        print_coords(s->get_center());
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

void defense_grid::heal_ships(coords& c, coords& final_c){
    // provo a muovere la barca 
    move(c, final_c);
    // creo il quadrato di griglia in cui curare
    std::set<ship*> ships = ship_in_range(c);
    if(ships.size() != 0){
        for(auto &p : ships){
            p->heal();
        }
    }
}

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
        //std::cout << el.first << "," << el.second << std::endl;
        if(is_ship(el)&&get_ship(el)!=s)
            throw std::invalid_argument("Posizione occupata da un'altra nave");
    }
    clear_position(*s);
    for(coords el : new_pos){
        //std::cout << el.first << "," << el.second << std::endl;
        matrix[el.first][el.second] = s;
    }
    ships.push_back(end);
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
    for(int i=0;i<ships.size();i++){
        if(center.first==ships[i].first&&center.second==ships[i].second)
            ships.erase(ships.begin()+i);
    }
}

std::ostream& operator <<(std::ostream& os,  defense_grid& dg){
    os << std::endl << "     --- --- --- --- --- --- --- --- --- --- --- --- ";

    for (int i = 0; i < 12; i++) {
        if(i<9){
		//std::cout << std::endl << i; //Stampa 0 e da errore
        os <<  std::endl << " " << (char) (i + 'A') << "  ";
		}

        else
        os <<  std::endl << " " << (char) (i + 2 + 'A') << "  ";

        os << "|";
        for (int j = 0; j < 12; j++) {
            i - 2;
            coords c = {i,j};
            if(dg.is_ship(c))               
				os << " " << dg.ship_at(c) << " ";
            else
                os << " " << dg.matrix[i][j]->get_alias() << " ";

            if (j!=11)
                os << "|";
        }
        os << "|" << std::endl << "    ";
        
        if (i!=11)
            os << " --- --- --- --- --- --- --- --- --- --- --- --- ";

    }
    
    os << " --- --- --- --- --- --- --- --- --- --- --- --- " << std::endl << std::endl << "     ";
    
    for (int i = 0; i <= 11; i++){
        if(i<9) os << " " << i + 1 << "  ";

        else os << i + 1 << "  ";
    }
    os << std::endl << std::endl;

    return os;
}
