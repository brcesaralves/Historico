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



int main()
{
l = (t_nota *) malloc (sizeof(t_nota));
l->prox->matricula.numero_matricula[0] = "1";

return 0;
}

