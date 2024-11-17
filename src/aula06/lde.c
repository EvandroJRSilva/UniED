#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
    struct  elemento *ant;
} elemento_t;

elemento_t* criarElemento(int valor);
elemento_t* inserirInicio(elemento_t *lista, int valor);
elemento_t* excluirInicio(elemento_t *lista);
void inserirFim(elemento_t *lista, int valor);
void inserirMeioIndice(elemento_t *lista, int valor, int indice);
void inserirMeioAposElemento(elemento_t *lista, int valorProcura, int valorInserir);
void excluirFim(elemento_t *lista);
void excluirMeioIndice(elemento_t *lista, int indice);
void excluirMeioValor(elemento_t *lista, int valor);
void imprimirLista(elemento_t *lista);

int main(){
    // Iniciando a lista ao criar o primeiro elemento
    elemento_t *lista = criarElemento(10);

    // Adicionando dois outros elementos ao fim da lista
    inserirFim(lista, 20);
    inserirFim(lista, 30);

    // Imprimindo os 3 elementos adicionados
    imprimirLista(lista);

    // Adicionando um novo elemento no início da lista
    lista = inserirInicio(lista, 5);

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    // Inserindo no meio da lista, passando um índice
    /*
    Como está: 
        lista[0] = 5
        lista[1] = 10
        lista[2] = 20
        lista[3] = 30
    Como deve ficar:
        lista[0] = 5
        lista[1] = 10
        lista[2] = 15
        lista[3] = 20
        lista[4] = 30
    */ 
    inserirMeioIndice(lista, 15, 2);
    // Você pode adicionar depois uma verificação para não permitir ao usuário tentar inserir em um índice inexistente.

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    // Inserindo no meio após um elemento da lista
    //Como está:       5 10 15 20 30
    //Como deve ficar: 5 10 15 20 25 30
    inserirMeioAposElemento(lista, 20, 25);

    // Imprimindo a lista atualizada
    imprimirLista(lista);
   
    // Excluindo um elemento no fim da lista
    //Como está:       5 10 15 20 25 30
    //Como deve ficar: 5 10 15 20 25
    excluirFim(lista);

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    // Excluindo um elemeno no início da lista
    //Como está:       5 10 15 20 25
    //Como deve ficar: 10 15 20 25
    lista = excluirInicio(lista);

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    // Exclindo no meio da lista, passando um índice
    /*
    Como está: 
        lista[0] = 10
        lista[1] = 15
        lista[2] = 20
        lista[3] = 25
    Como deve ficar:
        lista[0] = 10
        lista[1] = 15
        lista[2] = 25
    */
    excluirMeioIndice(lista, 2);

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    // Excluindo no meio da lista, passando o valor a ser escluído
    // Como está:       10 15 25
    // Como deve ficar: 10 25
    excluirMeioValor(lista, 15);

    // Imprimindo a lista atualizada
    imprimirLista(lista);

    return 0;
}

elemento_t* criarElemento(int valor){
    // Criando novo elemento
    elemento_t *novo = (elemento_t *)malloc(sizeof(elemento_t));
    // Se a memória não tiver sido alocada
    if (novo == NULL){
        return NULL;
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
   
    return novo;
}

void inserirFim(elemento_t *lista, int valor){
    // Criando novo elemento para ser inserido ao fim da lista
    elemento_t *novo = criarElemento(valor);
    // Criando ponteiro para percorrer a lista
    elemento_t *aux = lista;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    // Neste ponto chegamos ao fim da lista
    aux->prox = novo;
    novo->ant = aux;
}

elemento_t* inserirInicio(elemento_t *lista, int valor){
    elemento_t *novo = criarElemento(valor);
    novo->prox = lista;
    lista->ant = novo;
    
    return novo;
}

void inserirMeioIndice(elemento_t *lista, int valor, int indice){
    int i=0;
    elemento_t *aux = lista;
    elemento_t *novo = criarElemento(valor);

    while(i != indice-1){
        aux = aux->prox;
        i++;
    }
    novo->prox = aux->prox;
    novo->ant = aux;
    aux->prox->ant = novo;
    aux->prox = novo;
}

void inserirMeioAposElemento(elemento_t *lista, int valorProcura, int valorInserir){
    elemento_t *aux = lista;
    elemento_t *novo = criarElemento(valorInserir);

    while(aux->valor != valorProcura){ // Supondo que o valor procurado existe
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    novo->ant = aux;
    aux->prox->ant = novo;
    aux->prox = novo;
}

void excluirFim(elemento_t *inicio){
    elemento_t *aux = inicio, *anterior;

    while(aux->prox != NULL){
        anterior = aux;
        aux = aux->prox;
    }

    anterior->prox = NULL;
    aux->ant = NULL;
    free(aux);
}

elemento_t* excluirInicio(elemento_t *lista){
    elemento_t *paraExcluir = lista, *novoInicio = lista->prox;
    paraExcluir->prox = NULL;
    novoInicio->ant = NULL;
    free(paraExcluir);
    
    return novoInicio;
}

void excluirMeioIndice(elemento_t *lista, int indice){
    elemento_t *aux=lista, *ant;
    int i=0;

    while (i != indice){
        ant = aux;
        aux = aux->prox;
        i++;
    }
    ant->prox = aux->prox;
    aux->prox->ant = ant;
    aux->prox = NULL;
    aux->ant = NULL;
    free(aux);
}

void excluirMeioValor(elemento_t *lista, int valor){
    elemento_t *aux = lista, *ant;

    while (aux->valor != valor){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    aux->prox->ant = ant;
    aux->prox = NULL;
    aux->ant = NULL;
    free(aux);
}

void imprimirLista(elemento_t *lista){
    elemento_t *aux = lista;

    while (aux != NULL){ // indo até NULL para poder imprimir o último elemento
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}