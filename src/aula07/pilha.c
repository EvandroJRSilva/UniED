#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int valor;
    struct elemento *next; // elemento abaixo
    struct elemento *prev; // elemento acima
};

typedef struct{
    struct elemento *top;
} pilha;

void push(pilha **p, int valor);
struct elemento* pop(pilha **p);
struct elemento* peek(pilha *p);
void isEmpty(pilha *p);
void size(pilha *p);
void print(pilha *p);

int main(){
    int op=0;

    while (op != 8){
        printf("=== MENU ===\n");
        printf("1. Iniciar uma pilha;\n");
        printf("2. Inserir um elemento na pilha;\n");
        printf("3. Verificar se a pilha está vazia;\n");
        printf("4. Verificar o topo da pilha;\n");
        printf("5. Verificar o tamanho da pilha;\n");
        printf("6. Imprimir todo o conteúdo da pilha;\n");
        printf("7. Remover um elemento da pilha;\n");
        printf("8. Para sair.\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                pilha *p = (pilha *)malloc(sizeof(pilha));
                if (p != NULL){
                    p->top = NULL;
                    printf("Pilha iniciada com sucesso!");
                }else{
                    printf("Não foi possível iniciar a pilha. Tente novamente");
                }
                printf("\n\n");
                break;
            case 2:
                int valor;
                printf("Insira um valor: ");
                scanf("%d", &valor);
                push(&p, valor);
                printf("\n\n");
                break;
            case 3:
                isEmpty(p);
                printf("\n\n");
                break;
            case 4:
                struct elemento *topo = peek(p);
                if (topo != NULL)
                    printf("O elemento no topo da pilha é: %d", topo->valor);
                printf("\n\n");
                break;
            case 5:
                size(p);
                printf("\n\n");
                break;
            case 6:
                print(p);
                printf("\n\n");
                break;
            case 7:
                struct elemento *removido = pop(&p);
                printf("O elemento removido da pilha foi: %d", removido->valor);
                free(removido);
                printf("\n\n");
                break;
            case 8:
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

void push(pilha **p, int valor){
    struct elemento *novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->valor = valor;
    novo->next = NULL;
    novo->prev = NULL;

    pilha *pi = *p;
    // Se a pilha estiver vazia
    if(pi->top == NULL){
        pi->top = novo;
    }else{
        novo->next = pi->top;
        pi->top->prev = novo;
        pi->top = novo;
    }
}

struct elemento* pop(pilha **p){
    pilha *pi = *p;

    if (pi->top == NULL){
        printf("A pilha está vazia!");
        return NULL;
    }

    struct elemento *removido = pi->top;
    pi->top = pi->top->next;

    if (pi->top != NULL){
        pi->top->prev = NULL;
    }

    return removido;
}

struct elemento* peek(pilha *p){
    if (p->top == NULL){
        printf("A pilha está vazia!");
        return NULL;
    }

    return p->top;
}

void isEmpty(pilha *p){
    if (p->top == NULL){
        printf("A pilha está vazia!");
    }else{
        printf("A pilha não está vazia!");
    }
}

void size(pilha *p){
    int count = 0;
    struct elemento *aux = p->top;

    while (aux != NULL){
        count++;
        aux = aux->next;
    }

    printf("A pilha contém %d valor(es)", count);
}

void print(pilha *p){
    struct elemento *aux = p->top;

    printf("\n");
    while (aux != NULL){
        printf("| %2d |\n", aux->valor);
        printf("|----|\n");
        aux = aux->next;
    }
}