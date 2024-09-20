#include <stdio.h>

// DECLARAÇÃO DE FUNÇÕES
void bubble_sort(int *vetor, int tamanho);
void merge_sort(int *vetor, int esquerdo, int direito);
void merge(int *vetor, int esquerdo, int meio, int direito);
void quick_sort(int *vetor, int menor, int maior);
int particiona(int *vetor, int menor, int maior);
void imprime_vetor(int *vetor, int tamanho);


int main(){
    int vetor[10] = {10, 9, 8, 6, 7, 3, 4, 2, 5, 1};
    imprime_vetor(vetor, 10);
    
    //bubble_sort(vetor, 10);
    //merge_sort(vetor, 0, 9);
    quick_sort(vetor, 0, 9);
    
    return 0;
}

void bubble_sort(int *vetor, int tamanho){
    int i, j, aux;

    for(i=1; i < tamanho; i++){
        printf("\n[%d]\n", i);

        for(j = 0; j < tamanho - i; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                printf("%d: ", j+1);
                imprime_vetor(vetor, tamanho);
            }
        }
    }
}

void merge_sort(int *vetor, int esquerdo, int direito){
    if(esquerdo < direito){
        // Calculando o índice do meio
        int meio = esquerdo + (direito - esquerdo)/2;

        // Ordenando as metades
        merge_sort(vetor, esquerdo, meio);
        merge_sort(vetor, meio+1, direito);

        // Juntando as partes
        merge(vetor, esquerdo, meio, direito);
    }
}

void merge(int *vetor, int esquerdo, int meio, int direito){
    int i, j, k;
    int n1 = meio - esquerdo + 1;
    int n2 = direito - meio;

    // Arrays temporários
    int array_esquerdo[n1], array_direito[n2];

    // Copiando os dados para os arrays temporários
    for(i = 0; i < n1; i++)
        array_esquerdo[i] = vetor[esquerdo + i];
    for(j=0; j < n2; j++)
        array_direito[j] = vetor[meio + 1 + j];

    imprime_vetor(array_esquerdo, n1);
    imprime_vetor(array_direito, n2);

    // Juntando os arrays temporários no vetor[esquerdo ... direito]
    i = 0; j = 0; k = esquerdo;
    while(i < n1 && j < n2){
        if(array_esquerdo[i] <= array_direito[j]){
            vetor[k] = array_esquerdo[i];
            i++;
        }
        else{
            vetor[k] = array_direito[j];
            j++;
        }
        k++;
    }

    // Se ainda tiver elementos no array_esquerdo
    while(i < n1){
        vetor[k] = array_esquerdo[i];
        i++; k++;
    }
    
    // Se ainda tiver elementos no array_direito
    while(j < n2){
        vetor[k] = array_direito[j];
        j++; k++;
    }

    imprime_vetor(vetor, 10);
    printf("\n");
}

void quick_sort(int *vetor, int menor, int maior){
    if(menor < maior){
        int pivo = particiona(vetor, menor, maior);

        // Chamadas recursivas
        quick_sort(vetor, menor, pivo - 1);
        quick_sort(vetor, pivo+1, maior);
        imprime_vetor(vetor, 10);
    }
}

int particiona(int *vetor, int menor, int maior){
    int pivo = vetor[maior];
    int aux;

    // Índice do menor elemento, o qual indica também a posição correta do pivô encontrado até en-
    // tão
    int i = menor - 1;

    // Percorrendo o velor e movendo valores menores para o lado esquerdo
    for(int j = menor; j <= maior - 1; j++){
        if(vetor[j] < pivo){
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    // Movendo o pivô para depois dos elementos menores e retornando a sua posição
    aux = vetor[i+1];
    vetor[i + 1] = vetor[maior];
    vetor[maior] = aux;
    return i+1;
}

void imprime_vetor(int *vetor, int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}