#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo uma estrutura para "funcionar" como tipo de dado
typedef struct 
{
    char num_conta[7];
    char cod_banco[3];
    float saldo;
    char *cpf;
    char *nome_titular;
} conta;

typedef struct
{
  char nome[50];
  int idade;
  float peso;
  float altura;
  char cpf[13];
  // A estrutura conta deve ser declarada primeiro, para que possa ser utilizada dentro de pessoa
  conta conta; 
} pessoa;


/* DECLARAÇÃO DE FUNÇÕES*/
pessoa *criar_pessoa();
void imprimir(pessoa *p);
void editar(pessoa *p);
conta criar_conta();

int main(){
    pessoa *pessoa; // declarando ponteiro para variável do tipo pessoa
    int op = 0; // flag para o menu principal
    int criado = 0; // flag para determinar se a estrutura já foi criada

    // Opção de saída é 4, portanto, o programa estará preso no while enquanto o valor de op != 5
    while(op != 4){
        system("clear"); // limpando a tela
        printf("================================\n");
        printf("|    BEM VINDO(A) AO PROGRAMA   |\n");
        printf("|-------------------------------|\n");
        //printf("Para continuar, digite o número de uma das opções a seguir:\n");
        printf("| 1 - Cadastrar uma pessoa      |\n");
        printf("| 2 - Imprimir todos os valores |\n");
        printf("| 3 - Editar qualquer atributo  |\n");
        printf("| 4 - Para finalizar o programa |\n");
        printf("================================\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar(); //limpando entrada depois do scanf()

        switch (op)
        {
        case 1: //criar
            // Passando o ponteiro para a função registrar o endereço de memória nele.
            pessoa = criar_pessoa();
            criado = 1;
            break;
        case 2: //imprimir
            if(criado == 0) {
                system("clear");
                printf("Pessoa ainda não criada!");
                getchar();
                break;
            }
            imprimir(pessoa);
            break;
        case 3: //editar
            if(criado == 0) {
                system("clear");
                printf("Pessoa ainda não criada!");
                getchar();
                break;
            }
            editar(pessoa);
            break;
        case 4: //sair
            system("clear");
            printf("Agradecemos por sua preferência! Até a próxima!");
            getchar();
            break;
        default:
            system("clear");
            printf("Opção inválida! Tente novamente");
            getchar(); // para o programa permitir ao usuário ler a mensagem
            break;
        }
    }

    free(pessoa);
    return 0;
}

pessoa *criar_pessoa(){
/*
  Entradas
    - Nenhuma
  Saída
    - Endereço de memória alocado dinamicamente
*/
    pessoa *p = (pessoa*)malloc(sizeof(pessoa));
    
    system("clear"); // limpando a tela
    // Se a alocação tiver falhado, por algum motivo qualquer, imprime na tela o aviso
    if(p == NULL) printf("Não foi possível alocar memória para a sua estrutura");
    else{
        printf("Estrutura criada com sucesso!\n\n");
        printf("Digite o nome da pessoa: ");
        /*
        COMENTÁRIO IMPORTANTE:
          fgets é uma função que podemos pegar de stdio.h. Esta função lê uma linha da entrada espe-
          cificada (stream) e a armazena na String apontada. A leitura para quando n-1 caracteres
          são lidos, ou o caractere de nova linha '\n' é lido, ou o fim do arquivo (caso não esteja
          lendo do stdin) é atingido, o que vier primeiro.
        
          Sua sintaxe é como segue:
            char *fgets(char *str, int n, FILE *stream);
            
            Parâmetros:
              - char *str:      Um ponteiro para um array de caracteres, onde o conteúdo lido será
                                armazenado.
              
              - int n:          O número máximo de caracteres a ser lido, incluindo o caractere nu-
                                lo.

              - FILE *stream:   Um ponteiro para um objeto do tipo FILE, o qual é usado para espe-
                                cificar a entrada de dados. Pode ser um arquivo, ou a entrada nor-
                                mal stdin.
        */
        fgets(p->nome, sizeof(p->nome), stdin);
        // Retirando a quebra de linha e substituindo pelo caractere nulo
        p->nome[strcspn(p->nome, "\n")] = '\0';
        // A sintaxe '->' é usada para acessar um campo de uma estrutura a partir de um ponteiro.
        // O acesso ao campo a partir de uma variável normal é da seguinte forma: 'estutura.campo'
        printf("Digite a idade: ");
        scanf("%d", &p->idade);
        // Por mais que p tenha o endereço da variável pessoa, precisamos passar o endereço do cam-
        // co idade.
        printf("Digite o peso: ");
        scanf("%f", &p->peso);
        printf("Digite a altura: ");
        scanf("%f", &p->altura);
        printf("Digite o CPF, com a pontuação: ");
        scanf("%s", p->cpf);
        // Dessa vez utilizei o scanf porque ele é suficiente para ler um conjunto de caracteres
        // sem o [espaço]. O fgets é melhor para ler o nome por causa dos espaços entre as pala-
        // vras. Uma outra dúvida pode ter surgido em sua mente agora: por que não é &p->cpf? A
        // razão para isso é que o array de caracteres é um ponteiro, portanto, já é um endereço.
        
        // Criação de conta
        p->conta = criar_conta();
        p->conta.nome_titular = p->nome;
        p->conta.cpf = p->cpf;

        getchar(); 
        // Função que fica esperando ler um char do console. Neste caso sua utilidade é para fazer
        // com que o programa fique parado na última mensagem, para dar tempo do usuário ler antes
        // de seguir.
    }

    return p;
}

void imprimir(pessoa *p){
    system("clear");
    printf("========= DADOS CADASTRADOS =========\n");
    printf("-------------------------------------\n");
    printf("A seguir, os registrados da pessoa:\n");
    printf("Nome:\t\t %s\n", p->nome);
    printf("Idade:\t\t %d\n", p->idade);
    printf("Peso:\t\t %.1f\n", p->peso);
    printf("Altura:\t\t %.2f\n", p->altura);
    printf("CPF:\t\t %s\n", p->cpf);
    printf("Código do banco:\t\t %s\n", p->conta.cod_banco);
    printf("Número da conta:\t\t %s\n", p->conta.num_conta);
    printf("Saldo:\t %.2f\n", p->conta.saldo);

    getchar(); // para o programa parar e permitir ao usuário ler as informações apresentadas.
}

void editar(pessoa *p){
    int op2 = 0; // flag para a escolha da edição
    
    while(op2 != 7){ // loop para o submenu só sair caso op2 seja 6
        system("clear");
        printf("================================\n");
        printf("|            EDIÇÃO            |\n");
        printf("|------------------------------|\n");
        //printf("Para continuar, digite o número de uma das opções a seguir:\n");
        printf("| 1 - Editar o nome            |\n");
        printf("| 2 - Editar a idade           |\n");
        printf("| 3 - Editar o peso            |\n");
        printf("| 4 - Editar a altura          |\n");
        printf("| 5 - Editar o CPF             |\n");
        printf("| 6 - Editar a Conta bancária  |\n");
        printf("| 7 - Voltar ao menu principal |\n");
        printf("|------------------------------|\n");
        printf("Opção: ");
        scanf("%d", &op2);
        getchar(); //limpando entrada depois do scanf()

        switch (op2)
        {
        case 1: //nome
            system("clear");
            printf("Digite o novo nome: ");
            fgets(p->nome, 50, stdin);
            printf("Nome atualizado com sucesso!");
            // Retirando a quebra de linha e substituindo pelo caractere nulo
            p->nome[strcspn(p->nome, "\n")] = '\0';
            getchar();
            break;
        case 2: //idade
            system("clear");
            printf("Digite a nova idade: ");
            scanf("%d", &p->idade);
            printf("Idade atualizada com sucesso!");
            getchar();
            break;
        case 3: //peso
            system("clear");
            printf("Digite o novo peso: ");
            scanf("%f", &p->peso);
            printf("Peso atualizado com sucesso!");
            getchar();
            break;
        case 4: //altura
            system("clear");
            printf("Digite a nova altura: ");
            scanf("%f", &p->altura);
            printf("Altura atualizada com sucesso!");
            getchar();
            break;
        case 5: //cpf
            system("clear");
            printf("Digite o novo CPF: ");
            scanf("%s", p->cpf);
            printf("CPF atualizado com sucesso!");
            getchar();
            break;
        case 6: // conta
            /*
            TODO
              - Edição de conta
            */
            break;
        case 7: //sair
            printf("\nVoltando ao menu principal. Aperte qualquer tecla.");
            getchar();
            break;
        default:
            system("clear");
            printf("Opção inválida! Tente novamente.");
            getchar(); // para o programa permitir ao usuário ler a mensagem
            break;
        }
    }
}

conta criar_conta(){
    conta c;

    system("clear");
    printf("=========== CRIAÇÃO DA CONTA ============\n");
    printf("-----------------------------------------\n");
    printf("Digite o número da conta (ex.: 1234-56): ");
    scanf("%s", c.num_conta); // como não deve ter espaço, pode ser lido pelo scanf
    printf("Digite o código do banco (ex.: 123): ");
    scanf("%s", c.cod_banco);
    printf("Digite o saldo atual da conta: ");
    scanf("%f", &c.saldo);
    printf("\nConta criada com sucesso!");

    return c;
}