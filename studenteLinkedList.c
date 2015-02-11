#include <stdlib.h>
#include <string.h>

#include "studenteLinkedList.h"

/*
 * Restituisce la lunghezza della lista.
 */
int size(studenteLinkedList list) {
    int r=0;
    while(list != NULL) {
        r++;
        list = list->next;
    }
    return r;
}


/*
 * Restituisce l'elemento alla posizione specificata.
 * La prima posizione è la 0.
 * Se non esiste alcun elemento alla posizione specificata, le stringhe nome e cognome
 * dell'elemento restituito hanno lunghezza zero.
 */
studente getElementAtPosition(studenteLinkedList list, int position) {
    studente r;
    
    int i;
    r.cognome[0]=0; // Imposto cognome a stringa vuota
    r.nome[0]=0;    // Imposto nome a stringa vuota
    for(i=0; i<position && list != NULL; i++) {
        list = list->next;
    }
    
    if(list != NULL) {
        r = list->s;
        // Valido anche nella forma seguente, sebbene non necessaria.
//        strcpy(r.cognome, list->s.cognome);
//        strcpy(r.nome, list->s.nome);        
    }
    
    return r;
}


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
    int i;
    LLElement *newElement;
    LLElement **scan;
    scan = &list;
    newElement = (LLElement *)malloc(sizeof(LLElement));
    if(newElement != NULL) {
        for(i=0; i<position && (*scan) != NULL; i++) {
            scan = &((*scan)->next);
        }
        if(i == position) {
            newElement->s = e;
            // Valido anche nella forma seguente, sebbene non necessaria.
//            strcpy(newElement->s.cognome, e.cognome);
//            strcpy(newElement->s.nome, e.nome);
            newElement->next = *scan;
            *scan = newElement;
            r = list;
        }
    }
    return r;
}


/*
 * Svuota la lista.
 * Restituisce sempre NULL.
 */
studenteLinkedList empty(studenteLinkedList list) {
    LLElement * temp;
    while(list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    return NULL;
}
