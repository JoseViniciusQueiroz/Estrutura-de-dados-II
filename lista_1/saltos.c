#include <stdio.h>

void bubbleShort(float *v){
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<6-i;j++){
            if(v[j]>v[j+1]){
                float temp = v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }

}

int main(){
    float dificuldade;
    scanf("%f",&dificuldade);
    float v[7];
    int i,j;
    for( i=0;i<7;i++){
        scanf("%f",&v[i]);
    }

    bubbleShort(v);
    float soma = 0.0;
    for(j=1;j<6;j++){
        soma +=v[j];
    }
    soma = (soma/5.0)*dificuldade;
    printf("%.1f\n",soma);



}