#include <stdio.h>
#include <stdlib.h>




int comparando(const void *a, const void *b) {
  
    if (((int*)a)[1] != ((int*)b)[1]) {
        return ((int*)a)[1] - ((int*)b)[1];
    }

    return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
    char frase[1001];
    int frequencia[256] = {0};  


    while (fgets(frase, sizeof(frase), stdin) != NULL) {

        for (int i = 0; i < 256; i++) {
            frequencia[i] = 0;
        }

        for (int i = 0; frase[i] != '\0'; i++) {
            if (frase[i] != '\n') { 
                frequencia[(unsigned char)frase[i]]++;
            }
        }

        
        int text[256][2];
        int indice = 0;

        for (int i = 0; i < 256; i++) {
            if (frequencia[i] > 0) {
                text[indice][0] = i;     
                text[indice][1] = frequencia[i]; 
                indice++;
            }
        }

        qsort(text, indice, sizeof(text[0]), comparando);

        
        for (int i = 0; i < indice; i++) {
            printf("%d %d\n", text[i][0], text[i][1]);
        }

        printf("\n");  
    }

    return 0;
}
