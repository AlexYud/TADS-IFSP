/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Variáveis */
int numb, i, result = 1;

/* Corpo do programa */
int fat(numb) {
	
	for ( i = numb ; i > 0 ; i--) {
		result = result * i;
	}
	
	return result;
}

int main() {
	printf("\n Digite um numero: ");
	scanf("%i", &numb);
	
	printf("\n\n O fatorial do numero %i eh %i\n", numb, fat(numb));	
	
	return (0);
}

