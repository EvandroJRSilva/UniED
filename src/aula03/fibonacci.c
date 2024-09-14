#include <stdio.h>

int fibonacci(int n);

int main(){
    int n = 10, resultado;

    resultado = fibonacci(n);
    printf("\nResultado: %d\n", resultado);

    return 0;
}

// Sequência/Números de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
int fibonacci(int n){
    if(n < 2){
        return n;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}