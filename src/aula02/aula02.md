# Aula 02

Sumário

- [Aula 02](#aula-02)
  - [Análise de complexidade de algoritmos](#análise-de-complexidade-de-algoritmos)
    - [Função de custo do algoritmo](#função-de-custo-do-algoritmo)
    - [Análise Assintótica de algoritmos](#análise-assintótica-de-algoritmos)
      - [Notações da análise assintótica](#notações-da-análise-assintótica)
    - [Notação $O$](#notação-o)
    - [Exercícios](#exercícios)
      - [Exercício 1](#exercício-1)
      - [Exercício 2](#exercício-2)
      - [Exercício 3](#exercício-3)
      - [Exercício 4](#exercício-4)
      - [Exercício 5](#exercício-5)
      - [Exercício 6](#exercício-6)

## Análise de complexidade de algoritmos

Um determinado problema pode ser resolvido de variadas formas. No nosso contexto, **vários algoritmos diferentes** podem **resolver um mesmo problema**. Porém, como saber qual deles é o melhor?

Existem duas métricas bastante utilizadas para a comparação entre algoritmos: **tempo de execução** e **uso de memória volátil**.

### Função de custo do algoritmo

O custo em tempo de execução de um algoritmo é o tempo que ele demora para encerrar a sua execução. O tempo exato pode ser bastante difícil de obter e não ser muito confiável, pois existem muitos fatores que alteram a velocidade de execução de algum algoritmo (por exemplo, diferenças básicas entre hardwares distintos, ou seja, existem processadores mais eficientes que outros, além disso o S.O. pode estar lidando com programas diferentes em segundo plano, etc.).

Portanto, precisamos abstrair o conceito de custo de tempo e consideramos que:

    * Todos os códigos estarão executando em um, e somente um, microprocessador por vez;
    * Não existirão operações concorrentes, somente sequenciais;
    * Todas as instruções do programa têm um custo unitário, fixo e constante.

Vejamos um algoritmo simples:

```c
01  int i, n;
02  n = 10;
03  for(i=0;i<n;i++){
04      // Laço vazio
05  }
```

Contagem de instruções unitárias do código acima:

| **Linha** | **Motivo** | **Total de instruções**|
| --- | --- | --- |
| 02 | Atribuição de valor | 1 |
| 03 | Atributição de valor (i=0) e comparação (i<n) | 2
| 03 - loop | Comparação (i < n) e incremento (i++) | 2n

Para esse algoritmo em específico, sua função de custo de tempo pode ser resumida na seguinte equação:

$$T(n) = 2n + 3$$

Ou seja, as linas **02** e **03** executarão 1 vez, independentemente do valor de $n$, enquanto o *loop* do `for` será executado $n$ vezes.

Vejamos agora um segundo algoritmo:

```c
01  int i, maior;
02  int n = 10;
03  int vetor[n];
04
05  maior = 0;
06  for(i=0;i<n;i++){
07      if(vetor[i] >= maior){
08          maior = vetor[i];
09      }
10  }
```

Agora temos a seguinte contagem de instruções:

| **Linha** | **Motivo** | **Total de instruções**|
| --- | --- | --- |
| 02 | Atributição de valor | 1 |
| 05 | Atribuição de valor | 1 |
| 06 | Atributição de valor (i=0) e comparação (i<n) | 2
| 06 - loop | Comparação (i < n) e incremento (i++) | 2n
| 07 | Comparação | 1
| 08 | Atribuição de valor | 1

Perceba que a linha **08** só será executada quando o resultado da linha **07** for verdadeiro. Imagine um vetor com os seguintes valores: [1, 2, 3, 4, 5]. Nessa situação, o resultado da linha **07** sempre será positivo e, portanto, a linha **08** será executada todas vezes. Este caso é chamado de `pior caso`, pois é a situação onde todas as execuções possíveis acontecem. Portanto, neste caso, tanto a linha **07** quanto a **08** executarão $n$ vezes. A partir disso, temos a seguinte equação de custo de tempo:

$$T(n) = 4n + 4$$

Contudo, se nosso vetor tiver os seguintes valores: [5, 4, 3, 2, 1], todas vez que a linha **07** for executada, o resultado será negativo e, portanto, a linha **08** nunca será executada. Esta situação pode ser chamada de o `melhor caso`, pois é quando temos o menor número de instruções sendo executadas. Resumindo, temos a linha **07** sendo executada $n$ vezes enquanto a linha **08** é executada 0 vezes. Nossa equação de custo de tempo agora é:

$$T(n) = 3n + 4$$

A Figura 02 apresenta uma comparação do custo de tempo entre o melhor e o pior caso. Perceba que, enquanto o valor de $n$ é pequeno, a diferença é pouca. Porém, à medida em que temos uma maior quantidade de dados, conseguimos perceber o quão mais custoso é o pior caso.

<div style="text-align: center;">
    <img src="imagens/figura01.png"><br>
    <caption>Figura 02: Comparação da custo de tempo entre melhor e pior caso</caption>
</div>

Para termos uma melhor noção, considere que **cada instrução** leve **1 segundo** para executar. No **melhor caso** a execução levará cerca de **1 hora e 40 minutos**. O **pior caso**, por outro lado, levará **2 horas e 13 minutos**, ou seja, **mais de 30 minutos de diferença**.

### Análise Assintótica de algoritmos

Com a  `Análise Assintótica` é possível encontrar uma curva de tendência aproximada do desempenho de um algoritmo. Isso acontece com a extrapolação do conjunto de dados de entrada, a qual passa a ser considerada como tendente ao infinito, e também com a negligência de alguns termos das equações. Em outras palavras, os termos que crescem lentamente à medida em que o conjunto de dados cresce, são descartados.

Para se obter o `comportamento assintótico` de qualquer função, basta manter o termo de `maior grau` da equação, negligenciando todos os outros, inclusive o coeficiente multiplicador do termo de maior grau. Por exemplo, a curva assintótica da equação $T(n) = 4n + 4$ é $T(n) = n$.

A seguir, exemplos de funções de custo e seus respectivos comportamentos assintóticos (com laços aninhados):

| **Função Custo** | **Comportamento Assintótico** | **Algoritmo**|
| --- | --- | --- |
| $T(n) = 10$ | 1 | Sequencial |
| $T(n) = 10n + 2$ | n | 1 laço |
| $T(n) = 10n^{2} + 5n + 2$ | $n^{2}$ | 2 laços |
| $T(n) = 10n^{3} + 50n^{2} + n + 1$ | $n^{3}$ | 3 laços |

As figuras a seguir mostram a comparação entre os comportamentos assintóticos da tabela acima.

<div style="text-align: center;">
    <img src="imagens/figura02_01.png"><br>
    <caption>Figura 03(a): Comparação do comportamento assintótico de 1 vs. n</caption>
</div>
<br><br>
<div style="text-align: center;">
    <img src="imagens/figura02_02.png"><br>
    <caption>Figura 03(b): Comparação do comportamento assintótico entre 1, n e n^2</caption>
</div>
<br><br>
<div style="text-align: center;">
    <img src="imagens/figura02_03.png"><br>
    <caption>Figura 03(c): Comparação do comportamento assintótico entre 1, n, n^2 e n^3</caption>
</div>

[Neste programa](benchmark.c) conseguimos ver a diferença do tempo de execução.

A partir da análise dos algoritmos, o objetivo é encontrar uma maneira de construí-los de tal forma que o aumento do tempo de execução seja o menor possível.

#### Notações da análise assintótica

Na literatura temos três notações principais:

* O (conhecido como *big O*, ou grande O)
  * O pior caso de um algoritmo
* $\Omega$ (conhecido como *big $\Omega$*, ou grande ômega)
  * O melhor caso de um algoritmo
* $\Theta$ (conhecido como *big $\Theta$*, ou grande teta)
  * O caso médio de um algoritmo

A mais comum é o *big O*, pois atesta que um determinado algoritmo nunca pode ser pior do que a situação mostrada, porém, pode ser melhor, dependendo das entradas.

Vejamos um exemplo:

```c
int i,j,k,n;

n = 10;

for(i=0;i<n;i++){
    if(CONDIÇÃO){
        for(j=0;j<n;j++){
            if(CONDIÇÃO){
                for(k=0;k<n;k++){
                    // Laço vazio
                }
            }
        }
    }
}
```

No pior caso, ou seja, quando as duas condições forem sempre verdadeiras e, portanto, os três laços aninhados serão executados, temos: $O(n^{3})$.

No melhor caso, ou seja, quando as duas condições forem sempre falsas, teremos apenas a execução do primeiro `for`, portanto, temos: $\Omega(n)$

### Notação $O$

Relembrando seu conceito: essa notação nos mostra o custo computacional de um determinado algoritmo no seu `pior caso`.

Vimos o exemplo de um programa com custo constante $O(1)$, onde temos uma determinada execução de comando que terá sempre o mesmo custo, independentemente da quantidade de dados de entrada.

Logo em seguida vimos o $O(n)$, ou seja, de custo `linear`, pois seu gráfico de custo é uma reta.

Por fim, vimos o $O(n^{2})$ e $O(n^{3})$, os quais são chamados de custo de tempo `quadrático` e `cúbico`, respectivamente. De maneira mais genérica, podem ser referidos como `complexidade de tempo polinomial`. Seu gráfico característico é uma curva que passa a ser mais acentuada à medida do crescimento do expoente.

Porém, existem outras complexidades. Vou listar algumas a seguir, em ordem crescente de complexidade. Caso você queira ver uma tabela completa, [clique aqui](https://pt.wikipedia.org/wiki/Complexidade_de_tempo#Tabela_de_complexidade_de_tempo_comum) para ser levado a uma página em Português da Wikipedia. Recomendo que vejam também a versão do artigo em Inglês, porque em variados casos a versão em Inglês costuma ser mais completa. Outro bom artigo para ser lido: [geeksforgeeks](https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/).

| **Notação** | **Nome** | **Exemplo de algoritmo**
|---|---|---|
| $O(1)$ | Constante | Determinar se um número é par ou ímpar |
| $O(log n)$ | Logarítmico | Busca binária |
| $O(n)$ | Linear | Procurando o menor item em um array não ordenado |
| $O(n log n)$ | Linearítmico | Ordeção por comparação mais rápida |
| $O(n^{2})$ | Quadrático | *Bubble sort* ou *Insertion Sort* |
| $O(n^{3})$ | Cúbico | Multiplicação não otimizada de duas matrizes $n \times n$ |
| $O(c^{n}), c > 1$ | Exponencial | Resolução do [problema do caixeiro viajante](https://pt.wikipedia.org/wiki/Problema_do_caixeiro-viajante) usando [programação dinâmica](https://pt.wikipedia.org/wiki/Programa%C3%A7%C3%A3o_din%C3%A2mica)
| $O(n!)$ | Fatorial | Resolução do [problema do caixeiro viajante](https://pt.wikipedia.org/wiki/Problema_do_caixeiro-viajante) através de uma busca por força bruta |

<div style="text-align: center;">
    <img src="imagens/Comparison_computational_complexity.png"><br>
    <caption>Figura 04: Comparação de complexidades de tempo</caption>
</div>

---

### Exercícios

Fonte dos exercícios: [aqui](https://gist.github.com/jhwheeler/995dab35210c550b51b3b4160933a541) e [aqui](http://curric.rithmschool.com/springboard/exercises/big-o-analysis/).

#### Exercício 1

```c
int isPar(int valor){
    if(valor % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}
```

<details>
    <summary>Resposta</summary>
    O(1)<br>
    <b>Motivo</b>: Apenas um valor será processado por vez.
</details>

#### Exercício 2

```c
void voceEstaAqui(int a[], int b[]){
    int x,y;
    for(int i=0;i<sizeof(a);i++){
        x = a[i];
        for(int j=0;j<sizeof(b);b++){
            y = b[j];
        }
    }
}
```

<details>
    <summary>Resposta</summary>
    O(n^2)<br>
    <b>Motivo</b>: Cada for será executado <i>n</i> vezes (<b>considerando os dois arrays de mesmo tamanho</b>), portanto temos n * n = n^2. Caso sejam arrays de tamanhos distintos, com <i>n</i> elementos no primeiro e <i>m</i> elementos no segundo, a resposta será O(nm).
</details>

#### Exercício 3

```c
int* duplicaValores(int a[]){
    for(int i=0;i<sizeof(a);i++){
        a[i] *= 2;
    }

    return a;
}
```

<details>
    <summary>Resposta</summary>
    O(n)<br>
    <b>Motivo</b>: O custo de tempo cresce linearmente em relação ao tamanho da entrada.
</details>

#### Exercício 4

```c
int buscaEficiente(int a[], int elemento){
    int minId = 0;
    int maxId = sizeof(a)-1;
    int idAtual, elementoAtual;

    while(minId <= maxId){
        idAtual = floor((minId + maxId)/2);
        elementoAtual = a[idAtual];

        if(elementoAutal < elemento){
            minId = elementoAtual + 1;
        }
        else if(elementoAtual > elemento){
            maxId = elementoAtual - 1;
        }
        else{
            return idAtual;
        }
    }

    //Valor retornado para o caso de o elemento não ser encontrado
    return -1; 
}
```

<details>
    <summary>Resposta</summary>
    O(log n)<br>
    <b>Motivo</b>: O comprimento do array é dividido ao meio em cada iteração do while, logo a complexidade de tempo cresce um pouco devagar, seguindo um "ritmo" logarítmico.
</details>

#### Exercício 5

```c
int fatorial(int n){
    switch(n){
        case 0:
        case 1:
            return 1;
        default:
            return n*fatorial(n-1);
    }
}
```

<details>
    <summary>Resposta</summary>
    O(n)<br>
    <b>Motivo</b>: A função é chamada recursivamente de acordo com o tamanho de <i>n</i>.
</details>

#### Exercício 6

Forneça a notação $O$ para as expressões a seguir:

1. $O(n+10)$
   1. <details><summary>Resposta</summary>O(n)</details>
2. $O(100*n)$
   1. <details><summary>Resposta</summary>O(n)</details>
3. $O(25)$
   1. <details><summary>Resposta</summary>O(1)</details>
4. $O(n^{2}+n^{3})$
   1. <details><summary>Resposta</summary>O(n^3)</details>
5. $O(n+n+n+n)$
   1. <details><summary>Resposta</summary>O(n)</details>
6. $O(1000*log(n)+n)$
   1. <details><summary>Resposta</summary>O(n)</details>
7. $O(1000*n*log(n)+n)$
   1. <details><summary>Resposta</summary>O(nlogn)</details>
8. $O(2^{n} + n^{2})$
   1. <details><summary>Resposta</summary>O(2^n)</details>
9.  $O(5+3+1)$
    1.  <details><summary>Resposta</summary>O(1)</details>
10. $O(n + n^{1/2} + n^{2} + n*log(n)^{10})$
    1.  <details><summary>Resposta</summary>O(n^2)</details>