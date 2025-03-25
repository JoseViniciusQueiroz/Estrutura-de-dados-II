#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tamanho maximo 
#define MAX_STR 100

//struct da pilha 
typedef struct pilha {
    char data[MAX_STR];
    struct pilha *prox;
} pilha;


void empilhar(pilha **topo, const char *mensagem) {
    pilha *pilhaAux = (pilha *)malloc(sizeof(pilha));
    if (!pilhaAux) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strncpy(pilhaAux->data, mensagem, MAX_STR);
    pilhaAux->prox = *topo;
    *topo = pilhaAux;
}


char *desempilhar(pilha **topo) {
    if (*topo == NULL) {
        return "NULL";
    }
    pilha *temp = *topo;
    *topo = (*topo)->prox;
    char *result = (char *)malloc(MAX_STR * sizeof(char));
    if (!result) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strncpy(result, temp->data, MAX_STR);
    free(temp);
    return result;
}


int main() {
    pilha *stack = NULL;
    char command[MAX_STR + 8];
    char mensagem[MAX_STR];

    while (fgets(command, sizeof(command), stdin) != NULL) {
       
        if (strncmp(command, "inserir ", 8) == 0) {
           
            strncpy(mensagem, command + 8, MAX_STR);
            mensagem[strcspn(mensagem, "\n")] = '\0'; 
            empilhar(&stack, mensagem);
        } else if (strncmp(command, "desfazer", 7) == 0) {
            char *lastChange = desempilhar(&stack);
            printf("%s\n", lastChange);
            if (strcmp(lastChange, "NULL") != 0) {
                free(lastChange);
            }
        }
    }

   
    while (stack != NULL) {
        pilha *temp = stack;
        stack = stack->prox;
        free(temp);
    }

    return 0;
}
