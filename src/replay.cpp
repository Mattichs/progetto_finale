/* 
    Bastianello Mattia
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream log_file;
    log_file.open("log_prova.txt");
    string s;
    // verifico che il file sia stato aperto correttamente
    if(log_file.is_open()) {
        // leggo tutte le linee del file 
        while(getline(log_file, s)) {
            cout << s << endl;
            /* 
                aspetto i comandi per fare giocare la parita

                aspetto i print delle vare griglie
            */
        }
    } else { 
        cout << "Impossibile aprire il file";
    }
    log_file.close();

    return 0;
}