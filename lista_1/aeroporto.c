#include <stdio.h>
#include <ctype.h>

int validaSigla(const char* nome,const char* sigla){
    int tamanhoSigla = 3;

    int j = 0;
    if(sigla[2]=='X'){
        tamanhoSigla = 2;
    }

    for(int i=0;i<100000 && j<tamanhoSigla;i++){
        if(nome[i]==tolower(sigla[j])){
            j++;
        }   
    }
    
    return j == tamanhoSigla;
}

int main(){
    char nome[100001];
    char sigla[4];
    scanf("%s",nome);
    scanf("%s",sigla);
    if (validaSigla(nome,sigla)){
        printf("sim\n");
    }
    else{
        printf("nao\n");
    }
    
}