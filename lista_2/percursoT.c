#include <stdio.h>
#include <string.h>

void pos(char* pre, char* ordem, int x, char* posF, int* indP) {
    if (x <= 0){
        return;
    } 
    char raiz = pre[0];

    
    int indR;
    for (indR = 0; indR < x; ++indR) {
        if (ordem[indR] == raiz) {
            break;
        }
    }

    
    pos(pre + 1, ordem, indR, posF, indP); 
    pos(pre + 1 + indR, ordem + indR + 1, x - indR - 1, posF, indP);
    posF[(*indP)++] = raiz;
}

int main() {
    int x;
    scanf("%d", &x);

    while (x--) {
        int N;
        char pre[53], ordem[53], posF[53];
        int indP = 0;
        scanf("%d %s %s", &N, pre, ordem);
        pos(pre, ordem, N, posF, &indP);
        posF[indP] = '\0';
        printf("%s\n", posF);
    }

    return 0;
}
