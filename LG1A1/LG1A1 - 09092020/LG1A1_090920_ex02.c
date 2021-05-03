/* bibliotecas */
#include <stdio.h>
#include <math.h>

/* variaveis */
int i = 15, result;

/* corpo do programa */
int main(){
	printf("\n\n Quadrado de todos os numeros inteiros de 15 a 200: ");
	for ( i ; i <= 100 ; i++ ){
		result = pow(i, 2);
		printf(" -> %i", result);
	}
	
	return (0);
}

