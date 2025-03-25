#include <stdio.h>
#include <stdlib.h>

//arvore 
typedef struct no{
    int chave;
    struct no *esq,*dir;
}no;


int altura(no *r){
    if(r == NULL){
        return 0;
    }
    
    int hE;
    hE = altura(r->esq);
    int hD;
    hD = altura(r->dir);
    
    
    if(hE > hD){ 
        return hE + 1;
    }
    else {
        return hD + 1;
    }  
}




