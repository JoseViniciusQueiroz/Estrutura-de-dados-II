#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *tb; 
    int M;   
    int N;   
} TH;

int aumentaTamanho(int M);

int hash(int chave, int M) {
    return chave % M;
}

int THbusca(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    int inicio = posicao;

    while (h->tb[posicao] != -1) {
        if (h->tb[posicao] == ch) return 1;
        posicao = (posicao + 1) % h->M;
        if (posicao == inicio) break; 
    }
    return 0; 
}

void THinsere(TH *h, int ch) {
    if (THbusca(h, ch)){
      return;
    } 

    if (h->N > h->M / 2) {
        int aum = aumentaTamanho(h->M);
        int *newTable = (int *)malloc(aum * sizeof(int));
        for (int i = 0; i < aum; i++){ 
            newTable[i] = -1;
        }

        for (int i = 0; i < h->M; i++) {
            if (h->tb[i] != -1) {
                int posicao = hash(h->tb[i], aum);
                while (newTable[posicao] != -1) {
                    posicao = (posicao + 1) % aum;
                }
                newTable[posicao] = h->tb[i];
            }
        }
        free(h->tb);
        h->tb = newTable;
        h->M = aum;
    }

    int posicao = hash(ch, h->M);
    while (h->tb[posicao] != -1) {
        posicao = (posicao + 1) % h->M;
    }
    h->tb[posicao] = ch;
    h->N++;
}

int THremove(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    int inicio = posicao;

    while (h->tb[posicao] != -1) {
        if (h->tb[posicao] == ch) {
            h->tb[posicao] = -1; 
            h->N--;

            posicao = (posicao + 1) % h->M;
            while (h->tb[posicao] != -1) {
                int chR = h->tb[posicao];
                h->tb[posicao] = -1;
                h->N--;
                THinsere(h, chR);
                posicao = (posicao + 1) % h->M;
            }
            return 0;
        }
        posicao = (posicao + 1) % h->M;
        if (posicao == inicio) break;
    }
    return -1; 
}



