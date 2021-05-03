/* bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* variáveis */
int i=0, numb, arr[10];

/* corpo do programa */
int main() {
	
	for( i ; i < 10 ; i++ ) {
		system("cls");
		printf("\n\n Digite um numero: ");
		scanf("%i", &numb);
		arr[i] = numb;
	}
	
	for ( i = 0 ; i < 10 ; i++ ) {
		printf("[%i]", arr[i]);
	}
	
	return (0);
}
