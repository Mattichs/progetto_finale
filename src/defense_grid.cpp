#include "../include/corazzata.h"
#include "../include/esploratore.h"
#include "../include/supporto.h"
#include "../include/movement.h"
#include "../include/defense_grid.hpp"
#include <stdexcept>

defense_grid::defense_grid( std::vector<corazzata>& c, std::vector<supporto>& s, std::vector<esploratore>& e): battleships(c), healers(s),scouts(e){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            matrix[i][j]='#';
    }
    try{       
        //
        for(corazzata el:battleships){
            coords center=el.get_center();
            if(asset::Vertical==el.get_way()){
                if(center.first+1>=12||center.first-1<0||center.first>=12||center.second>=12||center.first<0||center.second<0)
                    throw std::invalid_argument("centro non valido");
                    matrix[center.first][center.second]='C'; 
                    matrix[center.first+1][center.second]='C';
                    matrix[center.first+2][center.second]='C';
                    matrix[center.first-1][center.second]='C';
                    matrix[center.first-2][center.second]='C';
            }     
            if(asset::Horizontal==el.get_way()){
                if(center.second+1>=12||center.second-1<0||center.first>=12||center.second>=12||center.first<0||center.second<0)
                    throw std::invalid_argument("centro non valido");
                matrix[center.first][center.second]='C'; 
                    matrix[center.first][center.second+1]='C';
                    matrix[center.first][center.second+2]='C';
                    matrix[center.first][center.second-1]='C';
                    matrix[center.first][center.second-2]='C';
                    
            }
        }
    }catch(const char& e){
        std::cout<<"posizione corazzate non valida";
    }
    try{        
        for(supporto el:healers){
            coords center=el.get_center();
           if(asset::Vertical==el.get_way()){
                if(center.first+1>=12||center.first-1<0||center.first>=12||center.second>=12||center.first<0||center.second<0)
                    throw std::invalid_argument("centro non valido");
                 matrix[center.first][center.second]='S'; 
                 matrix[center.first+1][center.second]='S';
                 matrix[center.first-1][center.second]='S';
           }     
            if(asset::Horizontal==el.get_way()){
                if(center.second+1>=12||center.second-1<0||center.first>=12||center.second>=12||center.first<0||center.second<0)
                    throw std::invalid_argument("centro non valido");
                matrix[center.first][center.second]='S'; 
                matrix[center.first][center.second+1]='S';
                matrix[center.first][center.second-1]='S';     
            }
        }
    }catch(const char& e){
        std::cout<<"posizione navi supporto non valida";
    }
    try{        
        for(esploratore el:scouts){
            coords center=el.get_center();
            if(center.first>=12||center.second>=12||center.first<0||center.second<0)
                throw std::invalid_argument("centro non valido");
            matrix[center.first][center.second]='E';
        }
    }catch(const char& e){
        std::cout<<"posizione scouts non valida";
    }

}//end constructor defense_grid

bool defense_grid::is_ship(coords c){
    bool res=false;
    try{
        res=(matrix[c.first][c.second]=='C'||matrix[c.first][c.second]=='E'||matrix[c.first][c.second]=='S'||matrix[c.first][c.second]=='c'||matrix[c.first][c.second]=='e'||matrix[c.first][c.second]=='s');
    }catch(const char& e){
        std::cout<<"coordinata non valida";
    }
    return res;
}//end is_ship

//this function returns true if a ship is hitted, false if the player misses
bool defense_grid::fire(coords c){
    if(matrix[c.first][c.second]=='C'||matrix[c.first][c.second]=='S'||matrix[c.first][c.second]=='E'){
        //using some for eachs to find the hitted ship
        if(matrix[c.first][c.second]=='C'){
            matrix[c.first][c.second]='c';
            for(corazzata el:battleships)
                el.get_hit(c);
        }
        if(matrix[c.first][c.second]=='S'){
            matrix[c.first][c.second]='s';
            for(supporto el:healers)
                el.get_hit(c);
        }
        if(matrix[c.first][c.second]=='E'){
            matrix[c.first][c.second]='e';
            for(esploratore el:scouts)
                el.get_hit(c);
        }
        return true;
    }if(matrix[c.first][c.second]=='c'||matrix[c.first][c.second]=='s'||matrix[c.first][c.second]=='e'){
        return true;
    }
    return false;
}//end fire 

//returns the new center of the ship
coords defense_grid::move(coords c, short i){
    if(i>4)
        throw std::invalid_argument("invalid i");
    if(i<3){
        supporto ship= healers[i];
        coords center=ship.get_center();
        if(asset::Vertical==ship.get_way()&&!(is_ship(c)||is_ship(coords(c.first+1,c.second))||is_ship(coords(c.first-1,c.second)))&&!ship.is_dead()){
                    matrix[c.first][c.second]=matrix[center.first][center.second]; 
                    matrix[c.first+1][c.second]=matrix[center.first+1][center.second];
                    matrix[c.first-1][c.second]=matrix[center.first-1][center.second];
                    //clearing old positions
                    matrix[center.first][center.second]='#'; 
                    matrix[center.first+1][center.second]='#';
                    matrix[center.first-1][center.second]='#';
                    return c;
           }     
            if(asset::Horizontal==ship.get_way()&&!(is_ship(c)||is_ship(coords(c.first,c.second+1))||is_ship(coords(c.first,c.second-1)))&&!ship.is_dead()){
                     matrix[c.first][c.second]=matrix[center.first][center.second]; 
                    matrix[c.first][c.second+1]=matrix[center.first][center.second+1];
                    matrix[c.first][c.second-1]=matrix[center.first][center.second-1]; 
                    //clearing old positions
                    matrix[center.first][center.second]='#'; 
                    matrix[center.first][center.second+1]='#';
                    matrix[center.first][center.second-1]='#'; 
                    return c;   
            }
         return ship.get_center(); 
      

    }
   esploratore ship=scouts[i-3];
   if(!is_ship(c)&&!ship.is_dead()){
    matrix[c.first][c.second]=matrix[ship.get_center().first][ship.get_center().second];
    matrix[ship.get_center().first][ship.get_center().second]='#';
   }
    return ship.get_center();
            
}

std::ostream& operator <<(std::ostream& os,const defense_grid& dg){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            os<<dg.matrix[i][j]<<" ";
        }
         os<<'\n';
    }
    return os;
}
