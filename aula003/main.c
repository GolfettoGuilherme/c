#include<stdio.h>
#include<stdlib.h>
struct aluno{
   char curso[60];
   int semestre;
   struct aluno *prox;
};
void criaCelula();
void exibe();
typedef struct aluno reg;
reg *inicio=NULL,*atual,*aux;

void criaCelula(){
   _flushall();
   if(inicio==NULL){//verifca se lista está vazia
      inicio=(reg *)malloc(sizeof(reg));
      inicio->prox=NULL;
      aux=inicio;
      printf("Curso:");
      gets(inicio->curso);
      printf("Semestre:");
      scanf("%d",&inicio->semestre);
   } else{
     atual=( reg*)malloc(sizeof(reg));
     atual->prox=NULL;
     aux->prox=atual;
     aux=atual;
     printf("Curso:");
     gets(atual->curso);
     printf("Semestre:");
    scanf("%d",&atual->semestre);
  }
}

main(){
  char resp='s';
  while(resp=='s'){
     criaCelula();
     _flushall();
     printf("Deseja continuar (s/n)\n");
     scanf("%c",&resp);
  }
 exibe();
 printf("-----------------------");
 printf("Total de registros = %d",contarCadastro());
 return 0;
}

void exibe(){
  reg *e =inicio;
  while(e!=NULL){
    printf("curso: %s \t semestre: %d \n",e->curso, e->semestre);
    e=e->prox;
  }
}

int contarCadastro(){
  reg *e = inicio;
  int num = 0;
  while(e!=NULL){
    num++;
    e=e->prox;
  }
  return num;
}
