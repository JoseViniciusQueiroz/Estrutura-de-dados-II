#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula* prox;
}celula;


int remove_depois(celula *le){
    if(le == NULL || le->prox == NULL){
        return -1;
    }
    celula *temp = le->prox;
    le->prox = temp->prox;
    free(temp);
    return 0;
}


void remove_elemento(celula *le,int x){
    if(le == NULL || le->prox == NULL)
       return;

    celula *pAnterior = le;
    celula *pAtual = le->prox;

    if(pAtual->dado == x){
        le->prox = pAtual->prox;
        free(pAtual);
        return;
    }
    while(pAtual != NULL && pAtual->dado != x){
        pAnterior = pAtual;
        pAtual = pAtual->prox;  
    }
      if (pAtual != NULL) {
        pAnterior->prox = pAtual->prox;
        free(pAtual);
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *atual = le;
    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            remove_depois(atual); 
        } else {
            atual = atual->prox; 
        }
    }
}





