#include <stdio.h>

int calculaDiaria(int d,int a,int n){
    long long int diaria;
    int periodo;
    if(a == 1){
        diaria = 31 * d;
    }
    else{
        periodo = (31 - (n-1));       
        diaria = periodo*(d + (n-1) * a);

    }
    return diaria;
}


int main(){
    int d;
    int a;
    int n;
    long long int diaria;
    scanf("%d",&d);
    scanf("%d",&a);
    scanf("%d",&n);
    diaria = calculaDiaria(d,a,n);
    printf("%lld\n",diaria);


}