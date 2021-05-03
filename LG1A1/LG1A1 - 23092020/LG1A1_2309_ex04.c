/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Variáveis */
int numb;

/* Corpo do programa */
int pon(int numb) {
	if ( numb >= 0 ) {
		return 1;
	} else {
		return 0;
	}
}

int main() {

	printf("\n Digite um numero: ");
	scanf("%i", &numb);
	
	if (pon(numb) == 1) {
		printf("\n O numero digitado eh positivo");
	} else {
		printf("\n O numero digitado eh negativo");
	}	
	
	return (0);
}

