//@FedericoCognolatto
#include "../include/ship/corazzata.h"
#include "../include/ship/esploratore.h"
#include "../include/ship/supporto.h"
#include "../include/ship/movement.h"
#include "../include/grid/defense_grid.hpp"
#include <stdexcept>

defense_grid::defense_grid( std::vector<corazzata>& c, std::vector<supporto>& s, std::vector<esploratore>& e): battleships(c), healers(s),scouts(e){
    water=empty();
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]=&water;
    }
    //inserting of the ships into the matrix
    try{       
        for(corazzata el:battleships){
           if(!insert_ship(el))
                throw std::invalid_argument("posizione corazzata non valida");
        }
    }catch(std::invalid_argument& e){
       throw std::invalid_argument("posizione corazzata non valida");
    }
    try{        
        for(supporto el:healers){
           if(!insert_ship(el))
                throw std::invalid_argument("posizione nave supporto non valida");
        }
    }catch(std::invalid_argument& e){
        throw std::invalid_argument("posizione nave supporto non valida");
    }
    try{        
        for(esploratore el:scouts){
            if(!insert_ship(el))
                throw std::invalid_argument("posizione esploratore non valida");
        }
    }catch(std::invalid_argument& e){
        throw std::invalid_argument("posizione esploratore non valida");
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

bool defense_grid::insert_ship(ship& s){
    if(this->is_ship(s.get_center()))
        return false;
    //battleship
    if(s.get_alias()=='C'){
         coords center=s.get_center();
            if(asset::Vertical==s.get_way()){
                if(!this->is_ship(coords(center.first+1,center.second))||!this->is_ship(coords(center.first-1,center.second))||!this->is_ship(center)||!this->is_ship(coords(center.first+2,center.second))||!this->is_ship(coords(center.first-2,center.second))){
                    matrix[center.first][center.second]=&s; 
                    matrix[center.first+1][center.second]=&s;
                    matrix[center.first+2][center.second]=&s;
                    matrix[center.first-1][center.second]=&s;
                    matrix[center.first-2][center.second]=&s;
                } else{
                    return false;
                } 
            }   
            if(asset::Horizontal==s.get_way()){
                 if(!this->is_ship(coords(center.first,center.second+1))||!this->is_ship(coords(center.first,center.second-1))||!this->is_ship(center)||!this->is_ship(coords(center.first,center.second+2))||!this->is_ship(coords(center.first,center.second-2))){
                    matrix[center.first][center.second]=&s; 
                    matrix[center.first][center.second+1]=&s;
                    matrix[center.first][center.second+2]=&s;
                    matrix[center.first][center.second-1]=&s;
                    matrix[center.first][center.second-2]=&s;
                }else{
                    return false;
                }
                    
            }
    }
    //support
      if(s.get_alias()=='S'){
         coords center=s.get_center();
            if(asset::Vertical==s.get_way()){
                if(!this->is_ship(coords(center.first+1,center.second))||!this->is_ship(coords(center.first-1,center.second))||!this->is_ship(center)){
                    matrix[center.first][center.second]=&s; 
                    matrix[center.first+1][center.second]=&s;
                    matrix[center.first-1][center.second]=&s;
                    
                } else{
                    return false;
                } 
            }   
            if(asset::Horizontal==s.get_way()){
                 if(!this->is_ship(coords(center.first,center.second+1))||!this->is_ship(coords(center.first,center.second-1))||!this->is_ship(center)){
                    matrix[center.first][center.second]=&s; 
                    matrix[center.first][center.second+1]=&s;
                    matrix[center.first][center.second-1]=&s;
                }else{
                    return false;
                }
                    
            }
      }
      //scout
        if(s.get_alias()=='E'){
         coords center=s.get_center();
            if(asset::Vertical==s.get_way()){
                if(!this->is_ship(center)){
                    matrix[center.first][center.second]=&s; 
                    
                } else{
                    return false;
                } 
            }   
            if(asset::Horizontal==s.get_way()){
                 if(!this->is_ship(center)){
                    matrix[center.first][center.second]=&s; 
                }else{
                    return false;
                }
                    
            }
    }

    
    return true;

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
coords defense_grid::move(coords c, short i){
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
            
}

std::vector<corazzata> defense_grid::get_battleships(){
    return battleships;
}

std::vector<supporto> defense_grid::get_healers(){
    return healers;
}

std::vector<esploratore> defense_grid::get_scouts(){
    return scouts;
}

std::ostream& operator <<(std::ostream& os,const defense_grid& dg){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            coords c=coords(i,j);
            os<<dg.matrix[i][j]->print(c)<<" ";
        }
         os<<'\n';
    }
    return os;
}
