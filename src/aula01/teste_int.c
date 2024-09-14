#include <stdio.h>

int main(){
    int a = 2147483646;
    
    printf("\nO valor de a é: %d\n", a);

    a += 2;
    printf("\nO novo valor de a é: %d\n", a);

    return 0;
}