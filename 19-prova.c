#include<stdio.h>
#include<stdlib.h>
struct arvore
{
 int a;
 struct arvore *e,*d;
};
typedef struct arvore no;
void pesquisa(int pesq);
void inserir(int n);
void pCentral(no *p);
void pPos(no *p);
void pPre(no *p);
void contaVogais(no *p);
int grau(no *r, char busca);
no *atual,*raiz,*b;
main()
{
 char resp, letra, letraBusca;
 int x;
 raiz=NULL;
 while(1)
 {
  system("cls");
  _flushall();
  printf("\tMenu\n\n");
  printf("[1] - Inserir um elemento\n[2] - Percursos\n[3] - Pesquisa\n[4] - Contagem de Vogais\n");
  printf("[5] - Sair do programa\n");
  printf("[6] - Contar Grau\n");
  printf("Digite a opcao desejada\n");
  scanf("%d",&x);
  switch(x)
  {
   case 1:resp=10;
   		  while(resp==10)
          {
           system("cls");
           printf("\tInsere celulas na arvore\n");
           printf("Digite o valor\n");
           scanf("%c",&letra);
           inserir(letra);
           _flushall();
           printf("Continuar (Continuar - enter/Sair - s)?");
           scanf("%c",&resp);
          }
          break;

   case 2:resp=10;
  	   	  while(resp==10)
          {
           system("cls");
           printf("\tPercurso na arvore binaria\n");
           printf("[1] - Central\n[2] - Pre fixado\n[3] - Pos fixado\n");
		   printf("Digite a opcao correspondente ao percurso\n");
           scanf("%d",&x);
           switch(x)
           {
  		    case 1:system("cls");
  		           printf("Percurso Central\n");
  		           pCentral(raiz);
  		           printf("\n");
  		           break;

			case 2:system("cls");
  		           printf("Percurso Pre fixado\n");
  		           pPre(raiz);
  		           printf("\n");
		           break;

            case 3:system("cls");
  		           printf("Percurso Pos fixado\n");
  		           pPos(raiz);
  		           printf("\n");
		           break;

		    default: printf("Opcao invalida\n");
		   }
		   _flushall();
           printf("\nContinuar ([enter] - Continuar/[s] - Voltar ao Menu)?");
           scanf("%c",&resp);
          }
          break;

   case 3:resp=10;
   		  while(resp==10)
          {
           system("cls");
           printf("\tPesquisa dados na arvore\n");
           printf("Digite o valor\n");
           scanf("%c",&letra);
           pesquisa(letra);
           _flushall();
           printf("\nContinuar ([enter] - Continuar/[s] - Voltar ao Menu)?");
           scanf("%c",&resp);
          }
          break;
	case 4:
		system("cls");
		contaVogais(raiz);
		break;

   case 5:
       exit(0);
       break;
   case 6:
        system("cls");
        _flushall();
        printf("Digite o valor:\n");
        scanf("%c",&letraBusca);
        grau(raiz, letraBusca);
        break;


   default: printf("Opcao invalida\n");
  }
 }
}


void inserir(int n){
	b=(no*)malloc(sizeof(no));
	b->d=NULL;
	b->e=NULL;
	b->a=n;
	if(raiz==NULL)
		raiz=b;
	else{
		atual=raiz;
		while(1){
			if(b->a>=atual->a){
				if(atual->d==NULL){
					atual->d=b;
					break;
				} else

					atual=atual->d;
			}
			if(b->a<atual->a){
				if(atual->e==NULL){
					atual->e=b;
					break;
				} else
					atual=atual->e;
			}
			if(b->a == atual->a){
				printf("letra ja existe\n");
				break;
			}
		}
	}
}


void pCentral(no *p){
	if(p!=NULL){
		pCentral(p->e);
		printf("%c ",p->a);
		pCentral(p->d);
	}
}


void pPos(no *p)
{
   if(p!=NULL)
 {
  pPos(p->e);
  pPos(p->d);
  printf("%c ",p->a);
 }

}


void pPre(no *p)
{
	 if(p!=NULL)

 {
  printf("%c ",p->a);
  pPre(p->e);
  pPre(p->d);
 }

}
void pesquisa(int pesq){
    atual=raiz;
    printf("Caminho: ");
    while(atual!=NULL){
        if(pesq==atual->a){
            printf("%c ",atual->a);
            break;
        } else {
            if(pesq>atual->a){
                printf("%c ",atual->a);
                atual=atual->d;
            } else {
                printf("%c ",atual->a);
                atual=atual->e;
            }
        }
    }
    if(atual==NULL)
        printf("Dado %c nao encontrado!\n",pesq);
}

void contaVogais(no *p){
	int numVogais = 0;
	atual=raiz;
	while(atual!=NULL){
        if(atual->a == 'a' || atual->a == 'e' || atual->a == 'i' || atual->a == 'o' || atual->a == 'u'){
            numVogais++;
        }
        if(atual->a){
            atual=atual->d;
        } else {
            atual=atual->e;
        }
    }
	printf("Quantidade de vogais: %d\n", numVogais);
	system("PAUSE");
}
int grau(no *r, char busca){
    atual=raiz;
    int valorSaltos = 0;
    while(atual!=NULL){
        if(busca == atual->a){
            break;
        } else {
            if(busca > atual->a){
                atual=atual->d;
            } else {
                atual=atual->e;
            }
        }
        valorSaltos++;
    }
    printf("Grau calculado: %d\n", valorSaltos - 1 );
    system("PAUSE");
    if(atual==NULL)
        printf("Dado nao encontrado!\n");
}
