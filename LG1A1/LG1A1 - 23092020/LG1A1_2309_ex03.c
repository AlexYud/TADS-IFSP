/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Variáveis */
int r;
float result;

/* Corpo do programa */
float volume(r) {
	result = 1.4*pow(r, 3);
	return result;
}

int main() {
	printf("\n Digite o raio da esfera: ");
	scanf("%i", &r);
	
	printf("\n O volume da esfera de raio %i, eh igual a %.2f m^3", r, volume(r));
	
	return (0);
}

