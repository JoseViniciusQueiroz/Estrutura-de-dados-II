#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCIPLINAS 1000

typedef struct {
    int codigo;
    int matriculados;
    int aprovados;
} Disciplina;

typedef struct {
    int ano;
    int semestre;
    int qtd_disciplinas;
    Disciplina disciplinas[MAX_DISCIPLINAS];
} Semestre;

void processar_semestre(Semestre *sem) {
    int max_reprovados = -1;
    int reprovados[MAX_DISCIPLINAS] = {0};
    int i, j;

    
    for (i = 0; i < sem->qtd_disciplinas; i++) {
        int reprovados_atual = sem->disciplinas[i].matriculados - sem->disciplinas[i].aprovados;
        reprovados[sem->disciplinas[i].codigo] = reprovados_atual;
        if (reprovados_atual > max_reprovados) {
            max_reprovados = reprovados_atual;
        }
    }

    
    printf("%d/%d\n", sem->ano, sem->semestre);
    for (i = 0; i < sem->qtd_disciplinas; i++) {
        if (reprovados[sem->disciplinas[i].codigo] == max_reprovados) {
            printf("%d ", sem->disciplinas[i].codigo);
        }
    }
    printf("\n\n");
}

int main() {
    int D;
    Semestre semestre;

   
    scanf("%d", &D);

    
    while (scanf("%d %d %d", &semestre.ano, &semestre.semestre, &semestre.qtd_disciplinas) != EOF) {
        for (int i = 0; i < semestre.qtd_disciplinas; i++) {
            scanf("%d %d %d", &semestre.disciplinas[i].codigo, &semestre.disciplinas[i].matriculados, &semestre.disciplinas[i].aprovados);
        }
        processar_semestre(&semestre);
    }

    return 0;
}
