#include <stdio.h>

int main(){
    /* 1 */
    // int a = 5, b = 5, *p;
    // p = &a;

    // printf("Bytes do inteiro: %lu\n", sizeof(a));
    // // Apesar de ter sido declarado como "inteiro", um ponteiro é visto pelo compilador como unsigned long int.
    // printf("Bytes do ponteiro: %lu\n", sizeof(p));
    
    // // Porém, como armazenamos o endereço de uma variável, o compilador tem de saber quantas células de memória 
    // //   pertencem àquele endereço
    // printf("Endereço da variável a: \t%p\n", &a);
    // printf("Valor armazenado no ponteiro: \t%p\n", p);
    // // Como o ponteiro é também uma variável, ele tem seu próprio endereço de memória:
    // printf("Endereço do ponteiro: \t\t%p\n", &p);
    // // É possível acessar o valor armazenado na variável a partir do ponteiro:
    // printf("Valor de a, a partir do ponterio p: %d\n", *p);
    // ------------------------------------------------------------------------

    // Mais brincadeiras

    /* 2 */
    //Variáveis
    // char b = 'b';
    // int c = 23;
    // float d = 4.35;
    // double e = 9.436;

    // Ponteiros
    // char *pb = &b;
    // int *pc = &c;
    // float *pd = &d;
    // double *pe = &e;

    // printf("char \tb = %c\n", b);
    // printf("Endereço de b = %p\n", &b);
    // printf("Endereço de b pelo ponteiro: %p\n", pb);
    // printf("Endereço do ponteiro pb: %p\n", &pb);

    // printf("\n\n");

    // printf("int \tc = %d\n", c);
    // printf("Endereço de c = %p\n", &c);
    // printf("Endereço de c pelo ponteiro: %p\n", pc);
    // printf("Endereço do ponteiro pc: %p\n", &pc);

    // printf("\n\n");

    // printf("float \td = %f\n", d);
    // printf("Endereço de d = %p\n", &d);
    // printf("Endereço de d pelo ponteiro: %p\n", pd);
    // printf("Endereço do ponteiro pd: %p\n", &pd);

    // printf("\n\n");

    // printf("double \te = %lf\n", e);
    // printf("Endereço de e = %p\n", &e);
    // printf("Endereço de e pelo ponteiro: %p\n", pe);
    // printf("Endereço do ponteiro pe: %p\n", &pe);

    // printf("\n\n");

    // // ------------------------------------------------------------------------

    // Ponteiro para ponteiro
    // int *pc2 = pc;
    // int **ppc = &pc;

    // printf("Endereço de c: %p\n", &c);
    // printf("Valor dentro de pc: %p\n", pc);
    // printf("Valor dentro de ppc: %p\n", ppc);
    // printf("Valor dentro de pc a partir de ppc: %p\n", *ppc);
    // printf("Endereço de ppc: %p", &ppc);
    
    // printf("Valor de b, pelo ponteiro pb: %c\n", *pb);
    // printf("Valor de c, pelo ponteiro pc: %d\n", *pc);
    // printf("Valor de d, pelo ponteiro pd: %f\n", *pd);
    // printf("Valor de e, pelo ponteiro pe: %lf\n\n", *pe);
    // printf("Valor de c pelo ponteiro do ponteiro pc2: %d\n", *pc2);

    // printf("\n\n");

    // Modificando o valor da variável c através do ponteiro
    // printf("Valor atual de c: %d\n", c);
    // *pc = 98;
    // printf("Novo valor de c: %d\n", c);

    return 0;
}