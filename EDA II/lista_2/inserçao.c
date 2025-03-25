#include <stdio.h>
#include <stdlib.h>


//arvore 
typedef struct no {
    int chave;
    struct no *esq,*dir; 
}no;

//funçao de inserir 
no * inserir(no *r,int x){
    if(r==NULL){
        struct no *novoNo = (struct no*) malloc(sizeof(struct no));
        novoNo->chave = x;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        return novoNo;
    }
    else if(x == r->chave){
        return r;
    }
    else if(x > r->chave){
        r->dir = inserir(r->dir,x);
    }
    else{
        r->esq = inserir(r->esq,x);
    }
    return r;
}


/*void printarOrdem(no* A) {
    if (A == NULL) {
        return;
    }
    printarOrdem(A->esq);
    printf("%d ", A->chave);
    printarOrdem(A->dir);
}
int main(){

struct no *tree = (struct no*) malloc(sizeof(struct no));
tree = inserir(tree,10);
tree = inserir(tree,8);
tree = inserir(tree,11);
tree = inserir(tree,11);
printarOrdem(tree);
}*/