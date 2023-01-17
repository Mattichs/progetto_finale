# progetto_finale

COMANDI CMAKE
cmake . 
make 

COMANDI PER ESEGUIRE I FILE

PARTITA
- Partita player vs computer: ./battaglia_navale -pc 
- Partita computer vs computer: ./battaglia_navale -cc

REPLAY
- Replay su terminale (con delay tra un turno e l'altro di 10 sec): ./replay -v nome_file_log
- Replay su file: ./replay -f nome_file_log nome_file_output


SPECIFICHE DI GIOCO
- L'utente inserisce le coordinate esclusivamente come lettera maiuscola/numero, in caso contrario il programma chiederà di reinserire le coordinate in modo corretto




 IMPLEMENTAZIONE DELLE GRIGLIE
 - Le griglie sono state gestiste con delle matrici e dei vettori di supporto. 

 - La griglia di difesa è composta da una matrice di puntatori di oggetti ship, da un vettore di coordinate che rappresenta i centri delle navi e un'apposita barca per identificare una posizione vuota. 

 - La griglia d'attacco è composta da una griglia di caratteri, un vettore di coordinate che rappresenta le posizioni delle navi nemiche e una reference ad una griglia di difesa per gestire l'aggiornamento delle navi. Abbiamo deciso di non gestire il reset delle 'X'. 
 


 //TODO 
 - aggiungere commenti
 - spostare funzioni dai due main
 - cmake ottimizzato come vuole il prof
 - sistemare out su file (cambiare tab con spazi o con for di spazi)
