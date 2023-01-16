/* 
    BASTIANELLO MATTIA 2032551
*/

#include "../include/utility.h"


std::string to_string(coords& c, asset a , char alias) {
    std::string s;
    coords prua;
    coords poppa;
    if(alias == 'C' && a == asset::Horizontal) {
        // corazzata orizzontale
        prua = coords(c.first, c.second -2);
        poppa = coords(c.first, c.second +2);
        s = to_string_helper(prua, poppa);
    } else if(alias == 'C' && a == asset::Vertical) {
        // corazzata verticale
        prua = coords(c.first - 2, c.second);
        poppa = coords(c.first + 2, c.second);
        s = to_string_helper(prua, poppa);
    } else if(alias == 'S' && a == asset::Horizontal) {
        // supporto orizzontale
        prua = coords(c.first, c.second -1);
        poppa = coords(c.first, c.second +1);
        s = to_string_helper(prua, poppa);
    } else if(alias == 'S' && a == asset::Vertical) {
        // supporto verticale
        prua = coords(c.first - 1, c.second);
        poppa = coords(c.first + 1, c.second);
        s = to_string_helper(prua, poppa);
    } else {
        // esploratore dimensione uno e asset trascurabile
        s = to_string_helper(c, c);
    }
    return s;
}

std::string to_string_helper(coords& c1, coords& c2) {
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
    std::cout << s << std::endl;
    return s;
}

// cambio coordinate char,int ---> int,int 
std::vector<coords> coords_translation(std::string s) {
    coords c1 {0,0};
    coords c2 {0,0};
    // prendo la stringa la divido in due e procedo
    std::string s1 = s.substr(0, s.find(" "));
    std::string s2 = s.substr(s.find(" ") + 1);
    if(!(isalpha(s1[0]) && isalpha(s2[0]))) throw std::invalid_argument("Inserisci le coordinate in modo corretto! (il primo carattere deve essere una lettera)\n");
    if(s1.length() == 3) {
        // prima coordinata
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = stoi(s1.substr(1,2)) -1;
    } else {
        if((short) s1[0] > 73)	c1.first = (short) s1[0] - 67;
	    else c1.first = (short) s1[0] - 65;
        c1.second = s[1] - '0' -1;
    }
    if(s2.length() == 3) {
        // seconda coordinata
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = stoi(s2.substr(1,2)) -1;
    } else {
        if((short) s2[0] > 73)	c2.first = (short) s2[0] - 67;
	    else c2.first = (short) s2[0] - 65;
        c2.second = s2[1] - '0' -1; // es. conversione '0' -> 0
    }
    std::vector<coords> v;
    v.push_back(c1);
    v.push_back(c2);
    return v;
}

// ottengo il centro da due coordinate
// siccome gestiamo la matrice da 0 a 11 qui sottraggo uno a quello che inserisce l'utente ottenendo il risultato corretto per l'inserimento
coords get_center(std::vector<coords> v) {
    // se i primi due sono uguali è orizzontale
    if(v[0].first == v[1].first) return coords(v[0].first, (v[0].second + v[1].second)/2);
    else return coords((v[0].first + v[1].first)/2, v[0].second);
}

// non gestisco la barca in diagonale per il momento, sarebbe errore
/* asset get_asset(std::vector<coords> v, char letter) {
    if(v[0].first == v[1].first) return asset::Horizontal;
    else return asset::Vertical;
} */
asset get_asset(std::vector<coords> v, char letter){
    switch(letter){
        case 'e':
            if(v[0] != v[1]) throw std::invalid_argument("L'esploratore deve avere poppa e prua uguali");

            else return asset::Horizontal; //default choice
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
}

void print_coords(coords c) {
    std::cout << "(" << c.first << "," << c.second << ")" << std::endl;
}

// generate random coords (0 to 11)
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