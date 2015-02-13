#include <stdlib.h>
#include <string.h>

#include "studenteLinkedList.h"

/*
 * Restituisce la lunghezza della lista.
 */
int size(studenteLinkedList list) {
    int r=0;
    
    int size = 0;
       
    while(list != NULL){
        size++;
        list = list->next;
    }
    
    return size;

} //-1


/*
 * Restituisce l'elemento alla posizione specificata.
 * La prima posizione è la 0.
 * Se non esiste alcun elemento alla posizione specificata, le stringhe nome e cognome
 * dell'elemento restituito hanno lunghezza zero.
 */
studente getElementAtPosition(studenteLinkedList list, int position) {
    studente r = {0};
    
    int i;

    for(i=0; i<position ; i++){
        list = list->next;
    }
    
    if(list != NULL){
        r = list->s; 
    }
    
    return r;
}  //-1


/*
 * Inserisce un elemento alla posizione specificata.
 * La prima posizione è la 0.
 * Se la lista è lunga n, gli elementi presenti vanno da 0 a n-1. È possibile
 * comunque aggiungere in posizione n (inserimento in coda).
 * 
 * Restituisce il valore aggiornato del puntatore al primo elemento in caso di successo.
 * Restituice NULL in caso di errore nell'aggiunta dell'elemento.
 */
studenteLinkedList insertElementAtPosition(studenteLinkedList list, int position, studente e) {
    studenteLinkedList r=NULL;
    
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    LLElement ** scorri;
    scorri = &list;
    int i;
    
    if(nuovo != NULL){
        for(i=0; i<position ; i++){
            scorri = &((*scorri)->next);
        }
        if(scorri != NULL){
            nuovo->next = *scorri;
            nuovo->s = e;
            *scorri = nuovo;
        }else{
            nuovo->next = NULL;
            nuovo->s = e;
            *scorri = nuovo;
        }
        r = *scorri;
    }
    
    return r;
} //0


/*
 * Svuota la lista.
 * Restituisce sempre NULL.
 */
studenteLinkedList empty(studenteLinkedList list) {
    
    LLElement *elimina;
    while(list != NULL) {
        elimina = list;
        list = list->next;
        free(elimina);
    }
    
    return NULL;
}  //-1
