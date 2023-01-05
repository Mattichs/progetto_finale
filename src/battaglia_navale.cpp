/* 
    Bastianello Mattia
*/
#include <iostream>

#include "../include/grid/defense_grid.hpp"
#include "../include/grid/attack_grid.hpp"

using namespace std;

/* 
    argc è un intero con il numero di argomenti passati a riga di comdando
    argv è un array di puntatori agli argomenti passati
    argv[0] è il nome del programma
*/
int main(int argc, char *argv[]) {
    if(argc == 1) cout << "Perfavore inserisci un argomento valido" << endl;
    else if(argc == 2) {
        if(strcmp(argv[1], "pc") == 0) {
            cout << "Hai scelto la partita giocatore vs computer" << endl;
            /* 
                gioco player vs bot
            */
            // il player deve inserirele sue navi
            // corazzate
            cout << "Quali sono le coordinate per la corazzata 1: " << endl;
            // converto e inserisco
            cout << "Quali sono le coordinate per la corazzata 2: " << endl;
            cout << "Quali sono le coordinate per la corazzata 3: " << endl;
            
            // sottomarini
            cout << "Quali sono le coordinate per il sottomarino 1: " << endl;
            cout << "Quali sono le coordinate per il sottomarino 2: " << endl;
            
            // navi di supporto
            cout << "Quali sono le coordinate per la nave di supporto 1: " << endl;
            cout << "Quali sono le coordinate per la nave di supporto 2: " << endl;
            cout << "Quali sono le coordinate per la nave di supporto 3: " << endl;
            
            // butto le navi nella griglia

            /* 
                game.exe

                player_move() -----> l'utente resetta la griglia, o mette i comandi
                bot_move()    -----> il bot sceglie random finchè la mossa non è valida
                while(mosse terminate OR partita finita)
                    player_move()
                    salvo la mossa sul file
                    stampa griglie
                    bot_move()
                    salvo la mossa sul file
                    stampa griglie
                
            */

        } else if(strcmp(argv[1], "cc") == 0) {
            cout << "Hai scelto la partita computer vs computer";
            /* 
                gioco bot vs bot
            */
        } else {
            cout << "Perfavore inserisci un argomento valido" << endl;
        }
    } else {
        cout << "Perfavore inserisci un argomento valido" << endl;
    }
    
   return 0; 
}