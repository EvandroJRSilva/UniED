#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int valor;
    struct elemento *next;
    struct elemento *prev;
};

typedef struct{
    struct elemento *front;
    struct elemento *rear;
} fila;


void enqueue(fila **f, int valor);
struct elemento* dequeue(fila **f);
struct elemento* front(fila *f);
struct elemento* rear(fila *f);
void isEmpty(fila *f);
void size(fila *f);
void print(fila *f);

int main(){
    int op=0;

    while(op != 9){
        printf("=== MENU ===\n");
        printf("1. Iniciar uma fila;\n");
        printf("2. Inserir um elemento na fila;\n");
        printf("3. Verificar se a fila está vazia;\n");
        printf("4. Verificar o primeiro elemento da fila;\n");
        printf("5. Verificar o último elemento da fila\n");
        printf("6. Verificar o tamanho da fila;\n");
        printf("7. Imprimir todo o conteúdo da fila;\n");
        printf("8. Remover um elemento da lista;\n");
        printf("9. Para sair.\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            fila *f = (fila *)malloc(sizeof(fila));
            f->front = NULL;
            f->rear = NULL;
            printf("Fila iniciada com sucesso!");
            printf("\n\n");
            break;
        case 2:
            int valor;
            printf("Insira um valor: ");
            scanf("%d", &valor);
            enqueue(&f, valor);
            printf("\n\n");
            break;
        case 3:
            isEmpty(f);
            printf("\n\n");
            break;
        case 4:
            struct elemento *primeiro = front(f);
            if (primeiro != NULL)
                printf("O primeiro elemento é: %d\n", primeiro->valor);
            printf("\n\n");
            break;
        case 5:
            struct elemento *ultimo = rear(f);
            if (ultimo != NULL)
                printf("O último elemento é: %d\n", ultimo->valor);
            printf("\n\n");
            break;
        case 6:
            size(f);
            printf("\n\n");
            break;
        case 7:
            print(f);
            printf("\n\n");
            break;
        case 8:
            struct elemento *removido = dequeue(&f);
            if (removido != NULL){
                printf("O elemento removido foi: %d", removido->valor);
                free(removido);
            }
            printf("\n\n");
            break;
        case 9:
            system("clear");
            printf("ATÉ LOGO!\n");
            break;
        default:
            printf("Opção inválida!\n");
            printf("\n\n");
            break;
        }
    }
    
    return 0;
}

void enqueue(fila **f, int valor){
    struct elemento *novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->valor = valor;
    novo->next = NULL;
    novo->prev = NULL;
    fila *fi = *f;

    // Se a fila estiver vazia
    if (fi->front == NULL){
        fi->front = novo;
        fi->rear = novo;
    }else{
        fi->rear->next = novo;
        novo->prev = fi->rear;
        fi->rear = novo;
    }
}

struct elemento* dequeue(fila **f){
    fila *fi = *f;

    if (fi->front == NULL){
        printf("A fila está vazia!\n");
        return NULL;
    }

    struct elemento *removido = fi->front;
    fi->front = fi->front->next;
    
    if (fi->front != NULL){
        fi->front->prev = NULL;
    }else{ 
        fi->rear = NULL; // a fila ficou vazia
    }

    return removido;
}

struct elemento* front(fila *f){
    if (f->front == NULL){
        printf("A fila está vazia!\n");
        return NULL;
    }
    return f->front;
}

struct elemento* rear(fila *f){
    if (f->rear == NULL){
        printf("A fila está vazia!\n");
        return NULL;
    }
    return f->rear;
}

void isEmpty(fila *f){
    if (f->front == NULL){
        printf("A fila está vazia.\n");
    }else{
        printf("A fila não está vazia.\n");
    }
}

void size(fila *f){
    int count = 0;
    struct elemento *aux = f->front;

    while(aux != NULL){
        count++;
        aux = aux->next;
    }
    printf("A fila possui %d elemento(s).\n", count);
}

void print(fila *f){
   struct elemento *aux = f->front;

    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->next;
    }
}