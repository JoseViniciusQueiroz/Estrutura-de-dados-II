#include <stdio.h>

int main() {
    // Ingredientes
    int qtd_amendoim = 0, qtd_chocolate_branco = 0, qtd_chocolate_leite = 0;
    // Tipos de caixas
    int caixas_crocante = 0, caixas_misto = 0, caixas_tradicional = 0;
    int caixas_especial = 0, caixas_predileta = 0, caixas_sortida = 0;

    // Leitura das quantidades iniciais de ingredientes
    scanf("%d %d %d", &qtd_amendoim, &qtd_chocolate_branco, &qtd_chocolate_leite);

    // Calcula a quantidade de caixas crocantes possíveis
    if (qtd_amendoim != 0) {
        caixas_crocante = qtd_amendoim / 5;
        qtd_chocolate_branco -= caixas_crocante * 25;  // Deduz chocolate branco
        qtd_chocolate_leite -= caixas_crocante * 20;   // Deduz chocolate ao leite
    }

    // Calcula a quantidade de caixas mistas possíveis
    if (qtd_chocolate_branco != 0) {
        caixas_misto = qtd_chocolate_branco / 25;
        qtd_chocolate_leite -= caixas_misto * 25;  // Deduz chocolate ao leite
    }

    // Calcula a quantidade de caixas tradicionais possíveis
    if (qtd_chocolate_leite != 0) {
        caixas_tradicional = qtd_chocolate_leite / 50;
    }

    // Calcula a quantidade de caixas sortidas possíveis e ajusta as caixas anteriores
    if (caixas_tradicional != 0) {
        caixas_sortida = caixas_tradicional / 10;
        caixas_misto -= caixas_sortida * 10;      // Deduz das caixas mistas
        caixas_crocante -= caixas_sortida * 10;   // Deduz das caixas crocantes
    }

    // Calcula a quantidade de caixas predileta possíveis e ajusta as caixas crocantes
    if (caixas_misto != 0) {
        caixas_predileta = caixas_misto / 20;
        caixas_crocante -= caixas_predileta * 10;  // Deduz das caixas crocantes
    }

    // Calcula a quantidade de caixas especiais possíveis
    if (caixas_crocante != 0) {
        caixas_especial = caixas_crocante / 30;
    }

    // Exibe as quantidades de cada tipo de caixa montada
    printf("%d %d %d", caixas_especial, caixas_predileta, caixas_sortida);

    return 0;
}