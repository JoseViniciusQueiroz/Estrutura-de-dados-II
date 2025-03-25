#include <stdio.h>

int main(){
    int tam;
    scanf("%d",&tam);
    int v[tam];
    long long int soma=0;
    for(int i=0;i<tam;i++){
        scanf("%d",&v[i]);
        soma+=v[i];
    }
    soma = soma/tam;
    int espaco =0;
    for(int i=0;i<tam;i++){
        if(v[i]>soma){
            if(espaco){
                printf(" ");
            }
            printf("%d",v[i]);
            espaco=1;
        }
    }

    if(!espaco){
        printf("0");
    }

    printf("\n");
    return 0;
    


}