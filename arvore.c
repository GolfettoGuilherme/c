/*
tinyurl.com/mbkpwpl
Este algoritmo simula as operações em uma ÁRVORE BINÁRIA. 
As operações são: 
inserção
percurso
busca 
Programa elaborado pelo professor Gerson Risso em 24/05/2009
*/ 
#include<stdio.h>
#include<stdlib.h>
struct arvore{
	int a;
	struct arvore *e,*d;
};
typedef struct arvore no;
void pesquisa(int pesq);
void inserir(int n);
void pCentral(no *p);
void pPos(no *p);
void pPre(no *p);
no *atual,*raiz,*b;
main(){
	char resp;
	int x,num;
	raiz=NULL;
	while(1){
		system("cls");
		_flushall();
		printf("\tMenu\n\n");
		printf("[1] - Inserir um elemento\n[2] - Percursos\n[3] - Pesquisa\n");
		printf("[5] - Sair do programa\n");
		printf("Digite a opcao desejada\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				resp=10;
				while(resp==10){
					system("cls");
					printf("\tInsere celulas na arvore\n");
					printf("Digite o valor\n");
					scanf("%d",&num);
					inserir(num);
					_flushall();
					printf("Continuar (Continuar - enter/Sair - s)?");
					scanf("%c",&resp);
				}
				break;
			case 2:
				resp=10;
				while(resp==10){
					system("cls");
					printf("\tPercurso na arvore binaria\n");
					printf("[1] - Central\n[2] - Pre fixado\n[3] - Pos fixado\n");
					printf("Digite a opcao correspondente ao percurso\n");
					scanf("%d",&x);
					switch(x){
						case 1:system("cls");
							printf("Percurso Central\n");
							pCentral(raiz);
							printf("\n");
							break;
						case 2:
							system("cls");
							printf("Percurso Pre fixado\n");
							pPre(raiz);
							printf("\n");
							break;
						case 3:
							system("cls");
							printf("Percurso Pos fixado\n");
							pPos(raiz);
							printf("\n");
							break;
						default: 
							printf("Opcao invalida\n");
					}
					_flushall();
					printf("\nContinuar ([enter] - Continuar/[s] - Voltar ao Menu)?");
					scanf("%c",&resp);
				}
				break;
			case 3:
				resp=10;
				while(resp==10){
					system("cls");
					printf("\tPesquisa dados na arvore\n");
					printf("Digite o valor\n");
					scanf("%d",&num);
					pesquisa(num);
					_flushall();
					printf("\nContinuar ([enter] - Continuar/[s] - Voltar ao Menu)?");
					scanf("%c",&resp);
				}
				break;
			case 5:
				exit(0);
				break;
			default: 
				printf("Opcao invalida\n");
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
		}
	}
}


void pCentral(no *p){
	if(p!=NULL){
		pCentral(p->e);
		printf("%d ",p->a);
		pCentral(p->d);	
	}
}


void pPos(no *p){
}


void pPre(no *p){
}


void pesquisa(int pesq){
	atual=raiz;
	printf("Caminho: ");
	while(atual!=NULL){
		if(pesq==atual->a){
			printf("%d ",atual->a);
			break;
		} else {
			if(pesq>atual->a){
				printf("%d ",atual->a);
				atual=atual->d;
			} else {
				printf("%d ",atual->a);
				atual=atual->e;
			}
		}
	}
	if(atual==NULL)
		printf("Dado %d nao encontrado!\n",pesq);
}
