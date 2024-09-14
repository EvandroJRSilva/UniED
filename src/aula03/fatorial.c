#include <stdio.h>
#include <time.h>

long double fatorial_iterativo(long double n){
    long double fat = 1;
    for(int i=1;i<=n;i++){
        fat *= i;
    }
    return fat;
}

long double fatorial_recursivo(long double n){
    if(n == 1){
        return n;
    }else{
        return n*fatorial_recursivo(n-1);
    }
}


int main(){
    long double resultado, n = 1000;

    clock_t beginf1 = clock();
    resultado = fatorial_iterativo(n);
    clock_t endf1 = clock();
    double tempof1 = (double)(endf1 - beginf1)/CLOCKS_PER_SEC;
    printf("Resultado 1: %Lg\n", resultado);

    clock_t beginf2 = clock();
    resultado = fatorial_recursivo(n);
    clock_t endf2 = clock();
    double tempof2 = (double)(endf2 - beginf2)/CLOCKS_PER_SEC;
    printf("Resultado 2: %Lg\n", resultado);

    printf("Tempo do fatorial iterativo: %f\n", tempof1);
    printf("Tempo do fatorial recursivo: %f\n", tempof2);

    return 0;
}