# progetto_finale

GRUPPO: "Non è un bug, è una feature"

COMANDI CMAKE
cmake . 
make 

COMANDI PER ESEGUIRE I FILE, SEMPRE NELLA STESSA DIRECTORY IN CUI C'E' CMAKELISTS.TXT

PARTITA
- Partita player vs computer: ./battaglia_navale -pc 
- Partita computer vs computer: ./battaglia_navale -cc

REPLAY
- Replay su terminale (con delay tra un turno e l'altro di 5 sec): ./replay -v nome_file_log
- Replay su file: ./replay -f nome_file_log nome_file_output


SPECIFICHE DI GIOCO
- L'utente inserisce le coordinate esclusivamente come [lettera maiuscola/numero] [lettera maiuscola/numero] , in caso contrario il programma chiederà di reinserire le coordinate in modo corretto.
- Nel caso di gioco tra due bot non scelgo chi inizia con la casualità siccome è già tutto random, nel caso di bot vs player invece c'è una scelta casuale su chi inizia
- Nel caso del gioco contro bot ogni volta che l'utente finisce di inserire un tipo di barca, la griglia viene stampata per dare un feedback visivo.
- I comandi speciali, siccome non sono utili allo svilppo della partita non sono presenti sul file di log

 IMPLEMENTAZIONE DELLE GRIGLIE
 - Le griglie sono state gestiste con delle matrici e dei vettori di supporto. 

 - La griglia di difesa è composta da una matrice di puntatori di oggetti ship, da un vettore di coordinate che rappresenta i centri delle navi e un'apposita barca per identificare una posizione vuota. 

 - La griglia d'attacco è composta da una griglia di caratteri, un vettore di coordinate che rappresenta le posizioni delle navi nemiche e una reference ad una griglia di difesa per gestire l'aggiornamento delle navi. Abbiamo deciso di non gestire il reset delle 'X'. 
 

