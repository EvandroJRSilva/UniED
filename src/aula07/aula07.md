# Aula 07

Sumário

## Fila

Uma `fila` é uma estrutura de dados linear que segue o princípio `FIFO` (*First In, First Out*), ou seja, o primeiro elemento inserido na fila é também o primeiro a ser retirado. Como analogia imagine uma fila de pessoas comprando um ingresso. A primeira pessoa da fila será sempre a primeira a ser atendida e, portanto, a primeira a sair da fila. Ainda, **TODAS** as inserções ocorrem ao fim da fila.

As principais funções de uma fila são:

* Enfileirar (*enqueue*): para adicionar um novo elemento ao fim da fila.
* Sair (*dequeue*): **remove** e **retorna** o primeiro elemento da fila.
* Primeiro (*front*): retorna o primeiro elemento da fila.
* Último (*rear*): retorna o último elemento da fila.
* Está Vazia (*isEmpty*): informa se a fila está vazia.
* Tamanho (*size*): informa a quantidade de elementos da fila.

Casos de uso de uma fila:

* Agendamento de tarefas (*task scheduling*).
* *Buffering*: usado em situações onde dados são transferidos assincronamente, como buffers de Entrada e Saída, ou fila de impressão.
* Busca em largura (*breadth-first search*): buscas de nó em um nível de um grafo, ou árvore, podem ser melhor organizadas com uma fila.

## Pilha

Uma `pilha` é uma estrutura de dados linear que segue o princípio `LIFO` (*Last In, First Out*), ou seja, o último elemento adicionado é o primeiro a ser removido. Como analogia, imagine uma pilha de qualquer objeto, como uma pilha de roupas, ou uma pilha de cartas.

As principais funções de uma pilha são:

* Inserir (*push*): insere um elemento no topo da pilha.
* Remover (*pop*): **remove** e **retorna** um elemento do topo da pilha.
* Topo (*peek* ou *top*): retorna o elemento que está no topo da pilha, mas sem retirá-lo da pilha.
* Está Vazio (*isEmpty*): informa se a pilha está vazia.
* Tamanho (*size*): informa a quantidade de elementos da pilha.