#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int nivel;
    float num;
    struct node *left;
    struct node *right;
} node_t;

typedef struct tree{
    node_t *root;
} tree_t;

// Declaração de funções
void inserir(tree_t **root, int *altura);
void buscar(tree_t *root, int num);
void imprimir(tree_t *root, int opcao);
void esvaziar(tree_t **root, int opcao, int num);

int main(){
    int op = 0, altura = 0;
    tree_t *tree = NULL;

    while(op != 8){
        printf("====== MENU ======\n");
        printf("1. Criar uma árvore;\n");
        printf("2. Verificar se a árvore está vazia;\n");
        printf("3. Inserir um elemento na árvore;\n");
        printf("4. Buscar um elemento na árvore;\n");
        printf("5. Mostrar todos os elementos da árvore;\n");
        printf("6. Esvaziar a árvore ou alguam subárvore;\n");
        printf("7. Verificar a altura da árvore;\n");
        printf("8. Encerrar o programa;\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                if(tree == NULL){
                    tree = (tree_t *)malloc(sizeof(tree_t));
                    if(tree == NULL) printf("Ocorreu um erro! Tente novamente!");
                    else{
                        printf("Árvore criada com sucesso!");
                        tree->root = NULL;
                    }
                } else printf("Árvore já criada!");
                break;
            case 2:
                if(tree == NULL){
                    printf("Árvore ainda não criada!");
                }else{
                    if(tree->root == NULL) printf("A árvore está vazia!");
                    else printf("A árvore já possui elemento(s)");
                }
                break;
            case 3:
                if(tree == NULL){
                    printf("Árvore ainda não criada!");
                }else{
                    inserir(&tree, &altura);
                }
                break;
            case 4:
                int op2=0;
                system("clear");
                printf("=== SUB MENU ===\n");
                printf("1. Buscar o nível de um nó;\n");
                printf("2. Buscar o pai de um nó;\n");
                printf("3. Buscar o(s) filho(s) de um nó;\n");
                printf("4. Buscar os nós de um nível;\n");
                printf("5. Voltar ao menu principal;\n");
                while(op2 != 5){
                    switch(op2){
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("");
                break;
        }
    }
    
    return 0;
}