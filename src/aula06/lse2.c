#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct elemento{
    int valor;
    struct elemento *proximo;
} elemento_t;

/*
    TODO
        - Finalizar o inserir (inserir inicio, meio);
        - Criar excluir (fim, inicio, meio)
        - Links:
            + https://en.cppreference.com/w/c/variadic
            + https://en.cppreference.com/w/c/variadic/va_arg
            + https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm
            + https://www.geeksforgeeks.org/variadic-functions-in-c/
            + https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Variable-Number-of-Arguments.html
    */
void inserir(int num, ...);
void imprimirLista(elemento_t *inicio);

int main(){
/*
    O objetivo desse código e deixá-lo mais enxuto, ou seja, sem aquela enorme quantidade de funções vistos no lse.c
*/
    elemento_t *lista = NULL;
    inserir(2, &lista, 10);
    inserir(2, &lista, 20);
    inserir(2, &lista, 30);

    imprimirLista(lista);
    
    return 0;
}

void inserir(int num, ...){
    va_list ptr;
    va_start(ptr, num);

    switch (num)
    {
    case 2: // [ponteiro para a lista, valor a inserir]
        // Criar lista, ou inserir ao fim
        elemento_t **lista = va_arg(ptr, elemento_t**);
        elemento_t* novo = (elemento_t *)malloc(sizeof(elemento_t));
            if (novo == NULL){
            return;
        }
        if(*lista == NULL){
            *lista = novo;
            return;
        }
        novo->valor = va_arg(ptr, int);
        novo->proximo = NULL;
        
        elemento_t *aux = *lista;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        break;
    
    default:
        break;
    }
    
    

    va_end(ptr);
}

void imprimirLista(elemento_t* lista){
    elemento_t *aux = lista;

    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
}