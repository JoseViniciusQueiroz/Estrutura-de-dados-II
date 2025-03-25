#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef long long int inteiro_longo;
#define MAXIMO 0x1007D0
#include <limits.h>

typedef struct listaLigada {
    inteiro_longo no;
    char *palavra;
    struct listaLigada *proximo;
} ListaLigada;

typedef struct tabelaHash {
    ListaLigada *dados;
    int chave;
} TabelaHash;

uint64_t hashSimplificado(const char *str) {
    union { uint64_t h; uint8_t u[8]; } resultado;
    int i = 0;
    resultado.h = strlen(str);
    while (*str) {
        resultado.u[i % 8] += *str + i + (*str >> ((resultado.h / (i + 1)) % 5));
        str++;
        i++;
    }
    return resultado.h; // 64 bits
}

uint64_t combinarHash(uint64_t a, uint64_t b) {
    uint64_t resultado = a + b;
    resultado ^= b + 0x9e3779b9 + (resultado << 6) + (resultado >> 2);
    return resultado;
}

uint64_t calcularHash(inteiro_longo no, char *palavra) {
    uint64_t valorHash = hashSimplificado(palavra);
    valorHash = combinarHash(valorHash, no);
    return valorHash % MAXIMO;
}

TabelaHash *inicializarTabelaHash(int tamanho) {
    TabelaHash *novaTabela = (TabelaHash *)malloc(tamanho * sizeof(TabelaHash));
    for (int i = 0; i < tamanho; i++) {
        novaTabela[i].chave = 0;
        novaTabela[i].dados = NULL;
    }
    return novaTabela;
}

void inserirNaTabela(TabelaHash *tabela, inteiro_longo no, char *palavra) {
    ListaLigada *novoNo = (ListaLigada *)malloc(sizeof(ListaLigada));
    novoNo->no = no;
    novoNo->palavra = strdup(palavra);
    novoNo->proximo = NULL;

    int indice = calcularHash(no, palavra);
    novoNo->proximo = tabela[indice].dados;
    tabela[indice].dados = novoNo;
}

ListaLigada *buscarNaTabela(TabelaHash *tabela, char *palavra, inteiro_longo no) {
    int indiceAtual = calcularHash(no, palavra);
    ListaLigada *noAtual = tabela[indiceAtual].dados;
    while (noAtual != NULL) {
        if (noAtual->no == no && strcmp(noAtual->palavra, palavra) == 0) {
            return noAtual;
        }
        noAtual = noAtual->proximo;
    }
    return NULL;
}

void resolver() {
    TabelaHash *tabela = inicializarTabelaHash(MAXIMO);
    inteiro_longo numero;
    char palavra[200];
    while (scanf("%lld %s", &numero, palavra) != EOF) {
        ListaLigada *resultado = buscarNaTabela(tabela, palavra, numero);
        if (resultado != NULL) {
            printf("%lld\n", numero);
        } else {
            inserirNaTabela(tabela, numero, palavra);
        }
    }
}

int main() {
    resolver();
    return 0;
}







