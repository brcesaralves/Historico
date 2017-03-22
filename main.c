#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3 //numero de alunos na lista sequencial

// Estrutura para armazenar disciplinas e notas
typedef struct disciplina{
    char disciplina[50];
    float nota;
} t_disciplina;

// Lista encadeado com as disciplinas e ponteiro para proximo nó
typedef struct no{
    t_disciplina dado;
    struct no *prox;
} t_no;

typedef t_no *t_listaDisciplina;

typedef struct alunos{
    char matricula[10];
    char
    t_no *disciplinas; // lista das disciplinas e notas
} t_alunos;

// Lista sequencial para armazenar os alunos
typedef struct listaAlunos{
    t_alunos vetor[MAX];//vetor que armazena elementos da lista
    int n; // posicao do ultimo elemento da lista
} t_listaAlunos; // tipo lista


t_no * criaNo();
int inserir(t_listaDisciplina *lista, int pos, t_disciplina dado);
t_disciplina * getElemento(t_listaDisciplina lista, int pos);
t_no * getNo(t_listaDisciplina lista, int pos);
int menu();



int main(){
    int i, j, pegaOpc,opcSair, contador;

    t_listaDisciplina listaDisciplinas;

    t_disciplina disciplina;
    t_listaAlunos alunos;

    listaDisciplinas = criaNo();
    pegaOpc = menu();

    switch(pegaOpc){
        case 1:

            do{
            printf("Informe sua disciplina: ");
            scanf("%s", &disciplina.disciplina);
            printf("informa a nota da disciplina %s: ", disciplina.disciplina);
            scanf("%f", &disciplina.nota);
            printf("Digite -1 para sair: ");
            scanf("%d", &opcSair);
            contador ++ ;

            }while(opcSair != -1);



    }

}


int menu(){
    int opc;
    printf("Aluno: Rafael Matheus\n");
    printf("Matricula : 1610014657\n");
    printf("Disciplina: Estrutura de dados\n");
    printf("Professor: Wallace Bonfim");
    getchar();

    system("cls || clear");

    printf("\t\t\t\tMatricula\n");

    printf("1- Inserir\n");
    printf("2- Exibir historico\n");
    printf("0- Sair\n");
    printf("Digite sua opção: ");
    scanf("%d", &opc);
    system("cls || clear");
    return opc;
}
/**
 * Cria um novo nó, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro o no criado.
 *
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

/**
 * Obtem um elemento da lista especificado por pos. Utiliza a funcao getNo(),
 * para obter o no, e em seguida extrair o elemento do no.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao do elemento desejado
 *
 * @see getNo()
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_disciplina * getElemento(t_listaDisciplina lista, int pos){
    t_no * no = getNo(lista, pos);
    if (no != NULL)
        return &(no->dado);
    else
        return NULL;
}

/**
 * Percorre toda a lista ate chegar na posicao desejada, em seguida retorna
 * o endereco do no atual.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao do no desejado
 * @see getElemento()
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_no * getNo(t_listaDisciplina lista, int pos) {
    // Retorna 0 se posicao invalida. Do contrario, retorna o elemento
    int n = 0;

    if (pos<0)
        return 0; // erro: posicao invalida

    while (lista != NULL) {
        if (n==pos)
            return lista;
        lista = lista->prox;
        n++;
    }
    return 0; // erro: posicao invalida
}

/**
 * Insere um elemento (dado) em determinada posicao da lista.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao que o elemento que sera inserido ficara.
 * @param dado  elemento a ser inserido
 *
 * @return Falso(0) se a posição for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int inserir(t_listaDisciplina *lista, int pos, t_disciplina dado) {
    t_no * p, * novo;

    // inserção na primeira posicao ou em lista vazia
    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)
            return 0; // erro: memoria insuficiente
        novo->dado = dado;
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }
    // insercao apos a primeira posicao em lista nao vazia
    p = getNo(*lista, pos-1);
    if (p == NULL)
         return 0; // erro: posicao invalida
    novo = criaNo();
    if (novo == NULL)
        return 0; // erro: memoria insuficiente
    novo->dado = dado;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}
