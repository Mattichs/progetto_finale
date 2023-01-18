/* 
    BASTIANELLO MATTIA 
*/

#include "../include/utility.h"


std::string get_prow_stern(coords& c, asset a , char alias) {
    std::string s;
    coords prow;
    coords stern;
    if(alias == 'C' && a == asset::Horizontal) {
        // corazzata horizotal
        prow = coords(c.first, c.second -2);
        stern = coords(c.first, c.second +2);
        s = two_coords_to_string(prow, stern);
    } else if(alias == 'C' && a == asset::Vertical) {
        // corazzata vertical
        prow = coords(c.first - 2, c.second);
        stern = coords(c.first + 2, c.second);
        s = two_coords_to_string(prow, stern);
    } else if(alias == 'S' && a == asset::Horizontal) {
        // supporto horizotal
        prow = coords(c.first, c.second -1);
        stern = coords(c.first, c.second +1);
        s = two_coords_to_string(prow, stern);
    } else if(alias == 'S' && a == asset::Vertical) {
        // supporto vertical
        prow = coords(c.first - 1, c.second);
        stern = coords(c.first + 1, c.second);
        s = two_coords_to_string(prow, stern);
    } else {
        // esploratore dimension 1 
        s = two_coords_to_string(c, c);
    }
    return s;
}

std::string two_coords_to_string(coords& c1, coords& c2) {
    // grid position go from 1 to 12: need add 1 to every letter or number so it can be insert iin the grid
    // Example: if input is 0 in the grid this is 1
    // and for letters need to skip J,K
    std::string s;
    char letter;
    letter = (char)('A' + c1.first);
    if(letter > 'I') s+= (letter +=2);
    else s += (char)('A' + c1.first);
    s += std::to_string(c1.second+1) += " ";
    letter = (char)('A' + c2.first);
    if(letter > 'I') s += (letter +=2);
    else s += (char)('A' + c2.first);
    s += std::to_string(c2.second+1) += '\n';
    return s;
}

coords get_center(std::vector<coords> v) {
    // se i primi due sono uguali è orizzontale
    if(v[0].first == v[1].first) return coords(v[0].first, (v[0].second + v[1].second)/2);
    else return coords((v[0].first + v[1].first)/2, v[0].second);
}

asset get_asset(std::vector<coords> v, char letter){
    switch(letter){
        case 'e':
            if(v[0] != v[1]) throw std::invalid_argument("L'esploratore deve avere poppa e prua uguali");
        break;

        case 's':
            //Case same row
            if(v[0].first == v[1].first){
                short result = v[0].second - v[1].second;

                if(std::abs(result) == 2) return asset::Horizontal;

                else throw std::invalid_argument("Il supporto deve avere una differenza di 2 nella seconda coordinata");
            }
            else if(v[0].second == v[1].second){
                short result = v[0].first - v[1].first;

                if(std::abs(result) == 2) return asset::Vertical;
            
                else throw std::invalid_argument("Il supporto deve avere una differenza di 2 nella prima coordinata");
            }
            else throw std::invalid_argument("Per essere posizionato l'esploratore deve avere almeno una coordinata uguale");
        break;
        
        case 'c':
            //Case same row
            if(v[0].first == v[1].first){
                short result = v[0].second - v[1].second;
                if(std::abs(result) == 4) return asset::Horizontal;

                else throw std::invalid_argument("La corazzata deve avere una differenza di 4 nella seconda coordinata");
            }
            //case same coloumn
            else if(v[0].second == v[1].second){
                short result = v[0].first - v[1].first;

                if(std::abs(result) == 4) return asset::Vertical;
            
                else throw std::invalid_argument("La corazzata deve avere una differenza di 4 nella prima coordinata");
            }

            else throw std::invalid_argument("Per essere posizionata la corazzata deve avere almeno una coordinata uguale");

        break;
    }
    return asset::Horizontal;
}

coords generate_rnd_coords() {
    int x = rand() % 12;
    int y = rand() % 12;
    return coords(x,y);
}

asset generate_rnd_asset() {
    int x = rand() % 20;
    if(x%2 == 0) return asset::Horizontal;
    else return asset::Vertical;
}
