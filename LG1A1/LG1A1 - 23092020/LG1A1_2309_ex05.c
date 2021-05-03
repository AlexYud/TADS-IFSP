/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Variáveis */
int numb, arrsize, i, add, result;

/* Corpo do programa */
int mart( array ) {
	
	printf("\n Diga o tamanho do vetor: ");
	scanf("%i", &arrsize);
	int arr[arrsize];
	
	for ( i ; i < arrsize ; i++ ) {
		printf("\n Digite um numero: ");
		scanf("%i", &arr[i]);
	}
	
	for ( i = 0 ; i < arrsize ; i++ ) {
		add = add + arr[i];
	}
	result = add / arrsize;
	
	return result;
}

int main() {
	
	printf("\n\n A media aritmetica do vetor eh %i\n", mart());	
	
	return (0);
}

