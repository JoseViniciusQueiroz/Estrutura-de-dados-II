#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
      int dado;
      struct celula *prox;
}celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *lista1 = l1->prox;
    celula *lista2 = l2->prox;
    celula *lista3 = l3;       

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->dado <= lista2->dado) {
            lista3->prox = lista1; 
            lista1 = lista1->prox;
        } else {
            lista3->prox = lista2; 
            lista2 = lista2->prox; 
        }
        lista3 = lista3->prox; 
    }

    
    if (lista1 != NULL) lista3->prox = lista1;
    if (lista2 != NULL) lista3->prox = lista2;
}

