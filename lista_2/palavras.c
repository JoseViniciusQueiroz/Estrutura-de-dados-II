#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 
typedef struct no {
    char palavra[17];
    int n;
    struct no* next;
} no;


unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str++);
    }
    return hash % 65537;
}


void adicionar_voto(no *table[], const char *palavra) {
    unsigned int cHash = hash(palavra);
    no* temp = table[cHash];


    while (temp) {
        if (strcmp(temp->palavra, palavra) == 0) {
            temp->n++;
            return;
        }
        temp = temp->next;
    }

    no* novoNo = (no*)malloc(sizeof(no));
    strcpy(novoNo->palavra, palavra);
    novoNo->n = 1;
    novoNo->next = table[cHash];
    table[cHash] = novoNo;
}


int buscar(no *table[], const char *palavra) {
    unsigned int cHash = hash(palavra);
    no* temp = table[cHash];

    while (temp) {
        if (strcmp(temp->palavra, palavra) == 0) {
            return temp->n;
        }
        temp = temp->next;
    }
    return 0; 
}


void resetar(no *table[], const char *palavra) {
    unsigned int cHash = hash(palavra);
    no* temp = table[cHash];
    no* prev = NULL;

    while (temp) {
        if (strcmp(temp->palavra, palavra) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                table[cHash] = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    no* hashTable[65537] = { NULL };
    char comando;
    char palavra[17];

    while (scanf(" %c %s", &comando, palavra) != EOF) {
        if (comando == '1') {
            adicionar_voto(hashTable, palavra);
        } else if (comando == '2') {
            printf("%d\n", buscar(hashTable, palavra));
        } else if (comando == '3') {
            resetar(hashTable, palavra);
        }
    }

    return 0;
}

