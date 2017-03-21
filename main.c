#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {

    char disciplina[100];
    float nota[10]; //guarda todas notas durando o periodo ou ano letivo


}t_disciplina;


typedef struct matricula {
    char nome[100];
    char numero_matricula[100];


}t_matricula;


typedef struct nota{

    float media;
    t_matricula matricula;
    t_disciplina disciplina;
    struct nota *prox;

}t_nota;

t_nota * criaNo() {
    t_nota * no = (t_nota*) malloc(sizeof(t_nota));

    if (no)
        no->prox = NULL;

    return no;
}



int getTamanho(t_nota *a) {
    int n = 0;
    while (a != NULL) {
        a = a->prox;
        n++;
    }
    return n;
}


int percorrer(t_nota *lista){
    int cont;
    while(lista != NULL){
        lista = lista->prox;
        cont++;
    }
    return cont;

}
int main()
{

t_nota *l;
int a;

l = criaNo();
printf("%d", percorrer(&l->prox));
l->disciplina.disciplina[0] = 's';


return 0;
}

