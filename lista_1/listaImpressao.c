#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox; 
}celula;





void imprime(struct celula *le){
    struct celula *pAuxiliar = le->prox;
    if(pAuxiliar == NULL){
       printf("NULL\n");
       return;
    }
    while(pAuxiliar != NULL){
        printf("%d -> ",pAuxiliar->dado);
        pAuxiliar = pAuxiliar->prox;
    }
    printf("NULL\n");

}



void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado); 
    imprime_rec(le->prox);
}

