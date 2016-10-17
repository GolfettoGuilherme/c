#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 500000
void exibe(float a[]);
void bolha(float a[]);
void aleatorio(float a[]);
void selection(float v[]);
void insertion(float v[]);
int particao(int e,int d,float b[]);
void gravar(char arguivo[]);
void quicksort(int e,int d,float a[]);
void transfer(float v[],float b[],float s[],float in[],float q[]);
int selec,n;
double inicio,fim,intervalo;
main(){ 
 system("title Métodos de ordenação");
 printf("Escolha a quantidade de valores - Maximo de %d valores\n",MAX);
 scanf("%d",&n);
 float v[n],b[n],s[n],in[n],q[n];
 
 while(1){ 
  system("cls");
  printf("\tMenu de Opcoes\n\n");
  printf("[1] - Gerar valores aleatorios\n[2] - Visualizar valores\n[3] - Bolha\n");
  printf("[4] - Insercao\n[5] - Quick\n[6] -  Selecao\n[7] - Sair\n");
  printf("<< ");
  scanf("%d",&selec);
  switch(selec){
   case 1: aleatorio(v);
           transfer(v,b,s,in,q);
           break;
           
   case 2: exibe(v);
           break;
        
   case 3: inicio = (double) clock()/CLOCKS_PER_SEC;
           bolha(b);
           fim=(double) clock()/CLOCKS_PER_SEC;
           intervalo=fim-inicio;
           printf("Tempo: %lf segundos\n",intervalo);
           gravar("bolha.txt");
           break;
   
   case 4: inicio = (double) clock()/CLOCKS_PER_SEC;
           insertion(in);
           fim=(double) clock()/CLOCKS_PER_SEC;
           intervalo=fim-inicio;
           printf("Tempo: %lf segundos\n",intervalo);
           gravar("inserção.txt");
           break;
           
   case 5: inicio = (double) clock()/CLOCKS_PER_SEC;
           selection(s);
           fim=(double) clock()/CLOCKS_PER_SEC;
           intervalo=fim-inicio;
           printf("Tempo: %lf segundos\n",intervalo);
           gravar("seleção.txt");
           break;
   
   case 6:inicio = (double) clock()/CLOCKS_PER_SEC;
          quicksort(0,n-1,q);
          fim=(double) clock()/CLOCKS_PER_SEC;
          intervalo=fim-inicio;
          printf("Tempo: %lf segundos\n",intervalo);
          gravar("seleção.txt");
          break;
  
        
   case 7: exit(0);
           break;
           
   default: printf("Opcao incorreta!\n");
  }
  system("pause");
 }
}

void aleatorio(float b[]){
 int r,i;
 srand(time(NULL));
 for(i=0;i<n;i++)
  b[i]=rand()%n;
}

void exibe(float a[]){
 int i;
 for(i=0;i<n;i++)
  printf("v[%d]=%.2f\n",i,a[i]);
}

void bolha(float a[]){
 printf("\t=== Metodo Bolha ===\n");
 printf("Ordenando %d valores, aguarde...\n",n);
 int i,j;
 float aux;
 for(i=0;i<n-1;i++)
  for(j=0;j<n-1-i;j++)
   if(a[j]>a[j+1]){
    aux=a[j];
    a[j]=a[j+1];
    a[j+1]=aux;
   }
   system("cls");
   printf("\t O conjunto de dados foi ordenado!\n");
}

void selection(float v[]){
 printf("\t=== Metodo Selecao ===\n");
 printf("Ordenando %d valores, aguarde...\n",n);
 int i,j,min;
 float aux;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++)
       if(v[j]<v[min])
         min=j;
    //Realiza a troca de valores
    aux=v[i];
    v[i]=v[min];
    v[min]=aux;
  }
   system("cls");
   printf("\t O conjunto de dados foi ordenado!\n");
}

void insertion(float v[]){   
 printf("\t=== Metodo Insercao ===\n");
 printf("Ordenando %d valores, aguarde...\n",n);   
 int i,j;
 float temp;
 for(i=1;i<n;i++){
  temp=v[i];
  j=i;
  while(j>0 && v[j-1]>=temp){
   v[j]=v[j-1];
   j--;          
  }
  v[j]=temp;
 }
  system("cls");
  printf("\t O conjunto de dados foi ordenado!\n");
}
void gravar(char arquivo[]){
 FILE *arq;
 arq=fopen(arquivo,"a");
 fprintf(arq,"%d\t%lf\n",n,intervalo);
 fclose(arq);
}

void quicksort(int e,int d,float a[]){  
    int i;
    if(d>e){ 
		i=particao(e,d,a); /* Particionando o vetor */
      	quicksort(e,i-1,a);
     	quicksort(i+1,d,a);
	}  
}

int particao(int e,int d,float b[]){
  int i,j;
  float v,t;
  v=b[d];   
  i=e-1;   
  j=d;
  do{  
	do{ 
          i=i+1; /* Procura o maior*/
	    }while ((b[i]<v) &&  (i<d)); 
	
     do{ 
           j=j-1; /* Procura o menor*/
	    } while ((b[j]>v) && (j>0)); 
	
         t=b[i];  
		 b[i]=b[j]; 
		 b[j]=t; 
  } while (j > i);
// colocando o pivo a[d] em seu lugar
	
	b[j]=b[i];  
	b[i]=b[d];
	b[d]=t;
	return i;
}

void transfer(float v[],float b[],float s[],float in[],float q[]){
 int i;
 for(i=0;i<n;i++){
  b[i]=v[i];
  s[i]=v[i];
  in[i]=v[i];
  q[i]=v[i];
 }
}
