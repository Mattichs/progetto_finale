/* 
    Bastianello Mattia
*/
#include <iostream>
#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"
#include <ctime>
#include <cstdlib>
#include <memory>

/* 
    argc è un intero con il numero di argomenti passati a riga di comdando
    argv è un array di puntatori agli argomenti passati
    argv[0] è il nome del programma
*/

void giocatore_vs_computer();
void computer_vs_computer();

int main(int argc, char *argv[]) {

    srand ( time(NULL) );

    if(argc == 1) std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    else if(argc == 2) {
        if(strcmp(argv[1], "pc") == 0) {
            std::cout << "Hai scelto la partita giocatore vs computer \n";
            /* 
                gioco player vs bot
            */
            giocatore_vs_computer();
        } else if(strcmp(argv[1], "cc") == 0) {
            std::cout << "Hai scelto la partita computer vs computer \n";
            /* 
                gioco bot vs bot
            */
            computer_vs_computer();
        } else {
            std::cout << "Perfavore inserisci un argomento valido" << std::endl;
        }
    } else {
        std::cout << "Perfavore inserisci un argomento valido" << std::endl;
    }
    
   return 0; 
}

// cambio coordinate char,int ---> int,int 
std::vector<coords> coords_translation(std::string s) {
    coords c1;
    coords c2;
    // prendo la stringa la divido in due e procedo
    std::string s1 = s.substr(0, s.find(" "));
    std::string s2 = s.substr(s.find(" ") + 1);
    if(!(isalpha(s1[0]) && isalpha(s2[0]))) throw std::invalid_argument("Inserisci le coordinate in modo corretto! (il primo carattere deve essere una lettera)\n");
    if(s1.length() == 3) {
        // prima coordinata
        c1.first = s1[0] - 96;
        if(c1.first > 9) c1.first -= 2;
        c1.second = stoi(s1.substr(1,2));
    } else {
        c1.first = s1[0] - 96;
        if(c1.first > 9) c1.first -= 2;
        c1.second = s[1] - '0';
    }
    if(s2.length() == 3) {
        // seconda coordinata
        c2.first = s2[0] - 96;
        if(c2.first > 9) c2.first -= 2;
        c2.second = stoi(s2.substr(1,2));
    } else {
        c2.first = s2[0] - 96;
        if(c2.first > 9) c2.first -= 2;
        c2.second = s2[1] - '0'; // es. conversione '0' -> 0
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
    if(v[0].first == v[1].first) return coords(v[0].first -1, (v[0].second + v[1].second)/2 -1);
    else return coords((v[0].first + v[1].first)/2 -1, v[0].second -1);
}

// non gestisco la barca in diagonale per il momento, sarebbe errore
asset get_asset(std::vector<coords> v) {
    if(v[0].first == v[1].first) return asset::Horizontal;
    else return asset::Vertical;
}

void print_coords(coords c) {
    std::cout << "(" << c.first << "," << c.second << ")" << std::endl;
}

// generate random coords
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
void computer_vs_computer() {
    defense_grid dg_bot1;
    //defense_grid dg_bot2;
    coords test {0,2};
    corazzata testc(asset::Horizontal, test);
    dg_bot1.insert_ship(testc);
    bool status = false;

    coords rnd;
    asset rnd_asset;
    std::cout << "Inserisco la prima nave: ";
    corazzata c1;
    while(!status) {
        try {
            rnd = generate_rnd_coords();
            std::cout << "Ho generato questo centro: " ;
            print_coords(rnd);  
            rnd_asset = generate_rnd_asset();
            c1 = corazzata(asset::Horizontal,rnd); 
            dg_bot1.insert_ship(c1);
            status = true;
        } catch(...) {}
    }   
    status = false;
    std::cout << dg_bot1;
     /* 
    while(!status) {
        try {
            rnd = generate_rnd_coords();
            rnd_asset = generate_rnd_asset();
            corazzata c2(rnd_asset,rnd); 
            dg_bot1.insert_ship(c2);
            status = true;
        } catch(...) {}
    }   
    status = false;

    std::cout << dg_bot1;  */
    /*while(!status) {
        try {
            rnd = generate_rnd_coords();
            corazzata c3(generate_rnd_asset(),rnd); 
            dg_bot1.insert_ship(c3);
            status = true;
        } catch(...) {}
    }   
    status = false; */ 
}

// per il momento l'utente deve essere sicuro che l'inserimento sia corretto
void giocatore_vs_computer() {
    // variabili utili
    defense_grid dg_player;
    attack_grid ag_player(dg_player);
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    /* 
        inserimento corazzate     
    *//*
    std::cout << "Inserisci posizione prima corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    center = get_center(coords_vec);
    corazzata c1(get_asset(coords_vec), center); 

    dg_player.insert_ship(c1);*/
/* 
    std::cout << "Inserisci posizione seconda corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    corazzata c2(get_asset(coords_vec), center);
    dg_player.insert_ship(c2);
 */
    
    /*
    std::cout << "Inserisci posizione terza corazzata: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    corazzata c3(get_asset(coords_vec), center);
    dg_player.insert_ship(c3);
    
    /*
        inserimento supporti     
    */
    std::cout << "Inserisci posizione primo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    
    center = get_center(coords_vec);
    supporto s1(get_asset(coords_vec), center); 
    dg_player.insert_ship(s1);
    
    ag_player.fire(center);

    std::cout << "Inserisci posizione secondo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    supporto s2(get_asset(coords_vec), center);
    dg_player.insert_ship(s2);

    std::cout << "Inserisci posizione terzo supporto: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    supporto s3(get_asset(coords_vec), center);
    dg_player.insert_ship(s3);
    
    /* 
        inserimento esploratori     
    */
    std::cout << "Inserisci posizione primo esploratore: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s);
    
    center = get_center(coords_vec);
    esploratore e1(get_asset(coords_vec), center); 
    dg_player.insert_ship(e1);

    std::cout << "Inserisci posizione secondo esploratore: \n";
    std::getline(std::cin, s);
    coords_vec = coords_translation(s); 
    center = get_center(coords_vec);
    esploratore e2(get_asset(coords_vec), center);
    dg_player.insert_ship(e2);
    
}