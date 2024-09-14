#include <stdio.h>

void hanoi(int n, char inicio, char fim, char aux){
    if(n > 0){
        // Movendo n - 1 discos do início para o auxiliar para não "atrapalharem"
        hanoi(n-1, inicio, aux, fim);

        // Movendo o n-ésimo disco do início para o fim
        printf("Mova o disco %d de %c para %c\n", n, inicio, fim);

        // Movendo os n-1 discos que deixamos no auxiliar para o fim
        hanoi(n-1, aux, fim, inicio);
    }
}

int main()
{
    int n = 3;
    char inicio, fim, aux;

    inicio = 'A'; fim = 'C'; aux = 'B';
    
    hanoi(n, inicio, fim, aux);

    return 0;
}