#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct arvore{
	int ra;
	char nome[81];
	double nota;
	struct arvore *e,*d;
};
typedef struct arvore no;
void pesquisa(int pesq);
void inserir(no n);
void pCentral(no *p);
void pPos(no *p);
void pPre(no *p);
no *atual,*raiz,*b;
int quant = 0;
double total = 0;
main(){
	char resp;
	int x, num;
	raiz=NULL;
	struct arvore each;
	while(1){
		system("cls");
		_flushall();
		printf("\tMenu\n\n");
		printf("[1] - Inserir um Aluno\n[2] - Percursos\n[3] - Pesquisar\n[4] - Media\n[5] - Quantidade\n");
		printf("[6] - Sair do programa\n");
		printf("Digite a opcao desejada\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				resp=10;
				while(resp==10){
					system("cls");
					printf("\tInsere alunos na arvore\n");
					printf("Digite o ra\n");
					scanf("%d",&each.ra);
					_flushall();
					printf("Digite o nome\n");
					gets(each.nome);
					printf("Digite a nota\n");
					scanf("%lf", &each.nota);
					inserir(each);
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
					printf("Digite pPos(p->d);a opcao correspondente ao percurso\n");
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
            case 4:
                printf("Media: %.2lf\n", total/quant);
                system("pause");
                break;
            case 5:
                printf("Quantidade: %d\n", quant);
                system ("pause");
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Opcao invalida\n");
		}
	}
}


void inserir(no n){
	b=(no*)malloc(sizeof(no));
	b->d=NULL;
	b->e=NULL;
	b->ra = n.ra;
	b->nota = n.nota;
	strcpy(b->nome, n.nome);
	if(raiz==NULL){
		raiz=b;
		quant++;
		total+=n.nota;
	}else{
		atual=raiz;
		while(1){
			if(b->ra>atual->ra){
				if(atual->d==NULL){
					atual->d=b;
					total+=b->nota;
					quant++;
					break;
				} else
					atual=atual->d;
			}
			if(b->ra<atual->ra){
				if(atual->e==NULL){
					atual->e=b;
					total+=b->nota;
					quant++;
					break;
				} else
					atual=atual->e;
			}
			if(b->ra==atual->ra){
                printf("RA ja existe\n");
                break;
			}
		}
	}
}


void pCentral(no *p){
	if(p!=NULL){
		pCentral(p->e);
		printf("%d\n",p->ra);
		puts(p->nome);
		printf("%.2lf\n", p->nota);
		pCentral(p->d);
	}
}


void pPos(no *p){
    if(p!=NULL){
        pPos(p->e);
        pPos(p->d);
        printf("%d\n",p->ra);
		puts(p->nome);
		printf("%.2lf\n", p->nota);
    }
}


void pPre(no *p){
    if(p!=NULL){
        printf("%d\n",p->ra);
		puts(p->nome);
		printf("%.2lf\n", p->nota);
		pPre(p->e);
		pPre(p->d);
    }
}


void pesquisa(int pesq){
	atual=raiz;
	printf("Resultado: \n");
	while(atual!=NULL){
		if(pesq==atual->ra){
			printf("RA: %d\n",atual->ra);
			printf("Nome: ");puts(atual->nome);
			printf("Nota: %.2lf", atual->nota);
			break;
		} else {
			if(pesq>atual->ra){
				atual=atual->d;
			} else {
				atual=atual->e;
			}
		}
	}
	if(atual==NULL)
		printf("Dado %d nao encontrado!\n",pesq);
}
