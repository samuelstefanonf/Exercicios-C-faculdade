#include <stdio.h>
#include <stdlib.h>

float* alocaçãoMemoria(int larg) {
    float **p;
    int n = 1;
    int i;

    if (larg < 1) {
        printf ("** Erro: Parametro não aceito **\n");
        return NULL;
    }

    p = (float **) calloc (larg, sizeof(float *));
    
    if (p == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return NULL;
    }
    for ( i = 0; i < larg; i++ ) {
        p[i] = (float*) calloc(n, sizeof(float));
        if (p == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return NULL;
        }
    }

    return p;
}

int* matrizInteiros (int m, int n, int *v)
{
  if (v == NULL) return (NULL);
  free(v);      
  return (NULL); 
}

int main(void) {
    int qtdAlunosPrimeiraTurma;
    int qtdAlunosSegundaTurma;
    int segundaTurmaLargura;
    float primeiraMedia = 0;
    float segundaMedia = 0;
    float *notas1;
    float *notas2;

    printf("Digite a quantidade de alunos da primeira turma: ");
    scanf("%d", &qtdAlunosPrimeiraTurma);

    notas1 = alocaçãoMemoria(qtdAlunosPrimeiraTurma);

    for(int j = 0; j < qtdAlunosPrimeiraTurma; j++) {
        printf("Digite a nota que o %dº aluno da chamada tirou na prova: ", j + 1);
        scanf("%f", &notas1[j]);
    }

    for(int k = 0; k < qtdAlunosPrimeiraTurma; k++) {
        primeiraMedia = primeiraMedia + notas1[k];
    }

    primeiraMedia = primeiraMedia/qtdAlunosPrimeiraTurma;

    printf("A media da primeira turma foi %f \n", primeiraMedia);

    printf("Digite a quantidade de alunos da segunda turma: ");
    scanf("%d", &qtdAlunosSegundaTurma);

    notas2 = alocaçãoMemoria(qtdAlunosSegundaTurma);

    for(int j = 0; j < qtdAlunosSegundaTurma; j++) {
        printf("Digite a nota que o %dº aluno da chamada tirou na prova: ", j + 1);
        scanf("%f", &notas2[j]);
    }

    for(int k = 0; k < qtdAlunosSegundaTurma; k++) {
        segundaMedia = segundaMedia + notas2[k];
    }

    segundaMedia = segundaMedia/qtdAlunosSegundaTurma;

    printf("A media da segunda turma foi %f \n", segundaMedia);
