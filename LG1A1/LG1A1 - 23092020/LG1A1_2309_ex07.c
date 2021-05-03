/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Variáveis */
int alt, larg, resultado;

/* Corpo do programa */
int area(alt, larg) {
	
	resultado = alt * larg;
	
	return resultado;
}

int main() {
	printf("\n Digite a altura: ");
	scanf("%i", &alt);
	
	printf("\n Digite a largura: ");
	scanf("%i", &larg);
	
	printf("\n\n A area da parede eh de %i m^2\n", area(alt, larg));	
	
	return (0);
}

