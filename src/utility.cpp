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
        c1.first = s1[0] - 64 - 1;
        if(c1.first > 9) c1.first -= 2;
        c1.second = stoi(s1.substr(1,2)) -1;
    } else {
        c1.first = s1[0] - 64 - 1;
        if(c1.first > 9) c1.first -= 2;
        c1.second = s[1] - '0' -1;
    }
    if(s2.length() == 3) {
        // seconda coordinata
        c2.first = s2[0] - 64 -1;
        if(c2.first > 9) c2.first -= 2;
        c2.second = stoi(s2.substr(1,2)) -1;
    } else {
        c2.first = s2[0] - 64 -1;
        if(c2.first > 9) c2.first -= 2;
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
asset get_asset(std::vector<coords> v) {
    if(v[0].first == v[1].first) return asset::Horizontal;
    else return asset::Vertical;
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

corazzata insert_corazzata(std::string messaggio){
	coords center;
	coords new_stern;
	coords new_prow;
	user_coords stern;
	user_coords prow;
	asset way;
	
	std::cout << "Guarda la griglia e inserisci poppa e prua " << messaggio << std::endl;
	std::cin >> stern.first >> stern.second >> prow.first >> prow.second;
	
	new_stern = coords_translation(stern);
	new_prow = coords_translation(prow);
	way = check_first_position(new_stern, new_prow, 'c');
    center = prendi_centro(new_stern, new_prow);
	corazzata c = corazzata(way, center);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("clear");

	return c;
}

supporto insert_supporto(std::string messaggio){
	coords center;
	coords new_stern;
	coords new_prow;
	user_coords stern;
	user_coords prow;
	asset way;
	
	std::cout << "Guarda la griglia e inserisci poppa e prua " << messaggio << std::endl;
	std::cin >> stern.first >> stern.second >> prow.first >> prow.second;
	
	new_stern = coords_translation(stern);
	new_prow = coords_translation(prow);
	way = check_first_position(new_stern, new_prow, 's');
    center = prendi_centro(new_stern, new_prow);
	supporto s = supporto(way, center);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("clear");

	return s;
}

esploratore insert_esploratore(std::string messaggio){
	coords center;
	coords new_stern;
	coords new_prow;
	user_coords stern;
	user_coords prow;
	asset way;
	
	std::cout << "Guarda la griglia e inserisci poppa e prua " << messaggio << std::endl;
	std::cin >> stern.first >> stern.second >> prow.first >> prow.second;
	
	new_stern = coords_translation(stern);
	new_prow = coords_translation(prow);

	way = check_first_position(new_stern, new_prow, 'e');
    center = prendi_centro(new_stern, new_prow);
	esploratore e = esploratore(way, center);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("clear");

	return e;
}