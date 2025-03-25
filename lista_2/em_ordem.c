#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


void em_ordem(no *raiz) {
    no* tree = raiz;
    no* vNo[100]; 
    int topo = 0;  

    while (tree != NULL || topo != 0) {
        
        while (tree != NULL) {
            vNo[++topo] = tree;
            tree = tree->esq;
        }
        
        tree = vNo[topo--];
        printf("%d ",tree->dado);

        tree = tree->dir;

    }
}


