#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *noPilha;
    struct pilha *prox;
} pilha;


pilha* criar_pilha(no* raiz) {
    pilha* novaPilha = (pilha*)malloc(sizeof(pilha));
    novaPilha->noPilha = raiz;
    novaPilha->prox = NULL;
    return novaPilha;
}

void empilhar(pilha** p, no* raiz) {
    pilha* novoElemt = criar_pilha(raiz);
    novoElemt->prox = *p;
    *p = novoElemt;
}


no* desempilha(pilha** p) {
    if (*p == NULL) {
        return NULL;
    }
    pilha* temp = *p;
    no* tempNo = temp->noPilha;
    *p = temp->prox;
    free(temp);
    return tempNo;
}


bool pilha_vazia(pilha* topo) {
    return topo == NULL;
}

void pos_ordem(no* raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha* p = NULL;
    no* ultimoVisitado = NULL;

    while (!pilha_vazia(p) || raiz != NULL) {
       
        if (raiz != NULL) {
            empilhar(&p, raiz);
            raiz = raiz->esq;
        } else {
            no* topo = p->noPilha;

            
            if (topo->dir != NULL && topo->dir != ultimoVisitado) {
                raiz = topo->dir;
            } else {
                printf("%d ", topo->dado);
                ultimoVisitado = desempilha(&p);
            }
        }
    }
}


