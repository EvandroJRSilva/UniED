#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} elemento_t;

int main()
{
    elemento_t a, b, c, *p;

    a.valor = 10;
    a.proximo = &b;

    b.valor = 20;
    b.proximo = &c;

    c.valor = 30;
    c.proximo = NULL;

    p = &a;

    while(p != NULL)
    {
        printf("%d ", p->valor);
        p = p->proximo;
    }

    printf("Fim\n");

    return 0;
}