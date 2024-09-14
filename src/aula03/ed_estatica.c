#include <stdio.h>
#include <string.h>

struct pessoa1
{
    int idade;
    char nome[20];
    float peso;
};

typedef struct {
    int idade;
    char nome[20];
    float peso;
} Pessoa2;

int main(){
    int vetor[10];
    struct pessoa1 pessoas[10];
    Pessoa2 pessoas2[10];
    
    for(int i=0;i<10;i++){
        vetor[i] = i;
        pessoas[i].idade = i;
        pessoas2[i].idade = i;

        printf("Vetor[%d] : %d\n", i, vetor[i]);
        printf("Idade -> pessoas[%d]: %d\n", i, pessoas[i].idade);
        printf("Idade -> pessoas2[%d]: %d\n\n", i, pessoas2[i].idade);
    }

    return 0;
}