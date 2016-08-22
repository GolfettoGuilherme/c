#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char curso[60];
    int semestre;
};
typedef struct aluno reg;

int main(){
    reg *a;
    a = (reg*) malloc(sizeof(reg));
    printf("Curso:");
    gets(a->curso);
    printf("Semestre:");
    scanf("%d",&a->semestre);
    printf("Curso %s, semestre %d",a->curso,a->semestre);
    return 0;
}
