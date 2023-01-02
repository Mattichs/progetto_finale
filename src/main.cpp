#include <iostream>

#include "../include/corazzata.h"
using namespace std;

int main() {

    asset dir = asset::Horizontal;
    short length = 1;
    coords center {5,5};
    
    std::vector<coords> pos = get_position(center, length, dir);
    //cout << pos.size() << endl;
    for(int i = 0;i < pos.size(); i++) {
        cout << "(" << pos[i].first << "," << pos[i].second << ")" << endl;
    }

   /*  for(int i = 0; i < length; i++){
        if(!valid_box(pos[i])) {
            cout << "errore" << endl;
            //std::cout << pos[i].first << "," << pos[i].second << std::endl; 
            throw std::invalid_argument("");
        }
    } */

    corazzata s = corazzata(asset::Horizontal, center);


    return 0;  
}