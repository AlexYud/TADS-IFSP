/* Bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Vari�veis */
int numb, N, diff, i, result;

/* Corpo do programa */
int add(N) {
	printf("\n\n Digite um numero inteiro e positivo: ");
	scanf("%i", &numb);
	
	diff = N - numb - 1; /* O menos 1 � para que apenas os n�meros entre os escolhidos seja usado */
	
	for( i ; i < diff ; i++ ) {
		numb++;
		result = result + numb;
		printf("\n %i", result);
	}

}

int main() {
	printf("\n\n Diga o valor de N: ");
	scanf("%i", &N);
	add(N);
	
	return (0);
}

