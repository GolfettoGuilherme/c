#include <stdio.h>
#include <stdlib.h>

struct aluno{
   char curso[60];
   int semestre;
   struct aluno *prox;
};
typedef struct aluno reg;

void criaCelula();

reg *inicio=NULL,*atual,*aux;

void criaCelula(){
    _flushall();
   if(inicio==NULL){
      inicio=(reg *)malloc(sizeof(reg));
      inicio->prox=NULL;
      aux=inicio;
      printf("Curso:");
      gets(inicio->curso);
      printf("Semestre:");
      scanf("%d",&inicio->semestre);
   } else{
       atual=(reg*)malloc(sizeof(reg));
       atual->prox=NULL;
       aux->prox=atual;
       aux=atual;
       printf("Curso:");
       gets(atual->curso);
       printf("Semestre:");
       scanf("%d",&atual->semestre);
   }
}


int main(){
    char resp = 's';
    while(resp == 's'){
        criaCelula();
        _flushall();
        printf("Deseja continuar (s/n)");
        scanf("%c", &resp);
    }
    return 0;
}
