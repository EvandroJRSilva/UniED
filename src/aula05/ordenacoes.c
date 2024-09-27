#include <stdio.h>

// DECLARAÇÃO DE FUNÇÕES
void insertionSort(int *vetor, int tamanho);
void selectionSort(int *vetor, int tamanho);
void imprime_vetor(int *vetor, int tamanho);

int main(){
    int vetor[10] = {10, 9, 8, 6, 7, 3, 4, 2, 5, 1};
    imprime_vetor(vetor, 10); printf("\n");
    //insertionSort(vetor, 10);
    selectionSort(vetor, 10);
    
    return 0;
}

void insertionSort(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        int j = i;
        while(j > 0 && vetor[j] < vetor[j-1]){
            int aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
            j--;
            imprime_vetor(vetor, 10);
        }
    }
}

void selectionSort(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        int menor = i;
        for(int j=i; j < tamanho; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
        imprime_vetor(vetor, tamanho);
    }
}

void imprime_vetor(int *vetor, int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}