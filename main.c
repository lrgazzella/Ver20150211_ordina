#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "studenteLinkedList.h"

const char fname[]="studenti.dat";  // Nome del file di input

int main(int argc, char** argv) {
    FILE *inputFile;                // file di input
    studente studenteDaAggiungere, studenteInLista;
    studenteLinkedList list=NULL;   // lista degli studenti
    int n;                          // numero degli elementi nella lista
    int i;
    
    // Apertura del file di lettura
    inputFile = fopen(fname, "rb");
    if(inputFile == NULL) {
        fprintf(stderr, "Impossibile aprire il file %s in lettura\n", fname);
        exit(-1);
    }
    
    // Lettura degli elementi dal file ed inserimento ordinato
    while(fread(&studenteDaAggiungere, sizeof(studente), 1, inputFile) == 1) {
        // studenteDaAggiungere contiene i dati dello studente letto
        n = size(list);
        int max, esci=0;
        
        if(list != NULL){
            esci = 0;
            for(i=0 ; i<n && esci!=1 ; i++){
                studenteInLista = getElementAtPosition(list, i);
                max = strcmp( (studenteDaAggiungere.cognome), (studenteInLista.cognome));
                
                if( (max < 0)  || (max == 0) ){
                    list = insertElementAtPosition(list, i, studenteDaAggiungere);
                    esci = 1;
                }   
            }
        }else{
            list = insertElementAtPosition(list, 0, studenteDaAggiungere);
        }     
    }
    fclose(inputFile);
    
    // Stampa della lista ordinata a schermo
    n = size(list);
    for(i=0; i<n; i++) {
        studenteInLista = getElementAtPosition(list, i);
        printf("%s; %s\n", studenteInLista.cognome, studenteInLista.nome);
    }
    
    // Liberare sempre la memoria, quando non più necessaria.
    list = empty(list);
    
    return (EXIT_SUCCESS);
}

