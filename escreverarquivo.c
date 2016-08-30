#include <stdio.h>
int main(int argc, char const *argv[]){
	FILE *arq;
	*arq = fopen("numeros.txt","a");
	int i;
	for (i = 0; i < 50; i++){
		fprintf(arq, "%d\n", i);
	}
	fclose(arq);
	return 0;
}
