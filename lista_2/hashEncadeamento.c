#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int dado;
    struct celula *prox;

}celula;

typedef struct {
    celula *tb;
    int M;
    int N;  

}TH;

int hash(int ch,int M){
    return ch % M;
}

//1 - função
void THinsere(TH *h,int ch){
    int cHash = hash(ch,h->M); 
    
    //verificando se tem duplicada 
    celula *verifica = h->tb[cHash].prox;
    while(verifica != NULL){
        if(verifica->dado == ch){
            return;
        }
        verifica = verifica->prox;
    }

    //inserir 
    celula *novoNO = (celula *)malloc(sizeof(celula));
    novoNO->dado = ch;
    novoNO->prox = h->tb[cHash].prox;
    h->tb[cHash].prox = novoNO;
    h->N ++;
}

// 2-funçao
int THremove(TH *h,int ch){
    int cHash = hash(ch,h->M);

    celula *anterior = &h->tb[cHash];
    celula *proximo = h->tb[cHash].prox;

    while(proximo != NULL){
        if(proximo->dado == ch){
            anterior->prox = proximo->prox;
            free(proximo);
            h->N--;
            return 0;
        }
        anterior = proximo;
        proximo = proximo->prox;
    }

    return -1;
}

// 3-funçao
int THbusca(TH *h,int ch){
    int cHash = hash(ch,h->M);

    celula *temp = h->tb[cHash].prox;
    while(temp != NULL){
        if(temp->dado == ch){
            return 1;
        }
        temp = temp->prox;
    }

    return 0;
}

