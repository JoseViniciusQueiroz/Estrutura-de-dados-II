#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula*prox;
}celula;



celula *busca(celula *le,int x){
    celula *lAux = le->prox;
    while(lAux != NULL){
        if(lAux->dado  == x){
            return lAux;
        }
        lAux = lAux->prox;
    }
    return NULL;
}

celula *busca_rec(celula *le,int x){
    if(le == NULL){
        return NULL;
    }
    if(le->dado == x ){
        return le;
    }
    return busca_rec(le->prox,x);
}

