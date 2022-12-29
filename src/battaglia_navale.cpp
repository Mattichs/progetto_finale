/* 
    Bastianello Mattia
*/
#include <iostream>

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
            cout << "Hai scelto la partita giocatore vs computer";
            /* 
                gioco player vs bot
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