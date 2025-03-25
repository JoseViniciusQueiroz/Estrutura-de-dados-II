#include <stdio.h>


void comverteRomanos (int num){
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i=0;i<13;i++){
        while(num>=valores[i]){
            printf("%s",romanos[i]);
            num -= valores[i];
        }
    }
}

int main(){
    int num;
    int num2;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&num2);
        comverteRomanos(num2);
        printf("\n");
    }
}