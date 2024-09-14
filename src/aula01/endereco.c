#include <stdio.h>

int main(){
    int meu_array[10];
    int minha_matriz[5][5];

    printf("Endereço da primeira célula do array: %p\n", &meu_array[0]);
    printf("Tamanho em bytes do tipo int: %lu\n", sizeof(int));
    
    printf("\n\n");
    
    for(int i=0;i<10;i++){
        printf("Endereço da célula %d: %p\n", i, &meu_array[i]);
    }

    printf("\n\n");

    printf("Endereço da primeira célula da matriz: %p\n", &minha_matriz[0][0]);
    for(int l=0;l<5;l++){
        for(int c=0;c<5;c++){
            printf("Endereço da célula [%d][%d]: %p\n", l, c, &minha_matriz[l][c]);
        }
    }
    
    return 0;
}