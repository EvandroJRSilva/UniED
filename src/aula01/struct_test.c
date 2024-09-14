#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
    float peso;
    float altura;
};

int main(){
    struct Pessoa p1;
    
    strncpy(p1.nome, "Johannes", 50);
    p1.idade = 20;
    p1.altura = 1.7;
    p1.peso = 62;

    printf("\nO nome é: %s\n", p1.nome);
    printf("A idade é: %d\n", p1.idade);
    printf("A altura é: %.1f\n", p1.altura);
    printf("O peso é %.1f\n", p1.peso);

    float imc = p1.peso/(p1.altura*p1.altura);    

    printf("O IMC do %s é %.1f\n", p1.nome, imc);

    return 0;
}