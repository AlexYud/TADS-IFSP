/* bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* variáveis */
int add=0, i=0,rep, c, numb, mean, high, low=1000, pos, arr[5];

/* corpo do programa */
int main() {
	
	for( i ; i < 5 ; i++ ) {
		system("cls");
		printf("\n\n Digite um numero: ");
		scanf("%i", &numb);
		arr[i] = numb;
	}
	
	printf("\n\n Vetor: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		printf("[%i]", arr[i]);
	}
	
	printf("\n\n Vetor invertido: ");
	for ( i = 4 ; i >= 0 ; i-- ) {
		printf("[%i]", arr[i]);
	}
	
	printf("\n\n Somente numeros pares: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		if ( arr[i] % 2 == 0 ) {
			printf("[%i]", arr[i]);	
		}
	}
	
	printf("\n\n Somente numeros impares: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		if ( arr[i] % 2 != 0 ) {
			printf("[%i]", arr[i]);	
		}
	}
	
	printf("\n\n Media aritmetica de todos os numeros: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		add = add + arr[i];
	}
	mean = add / i;
	printf("%i", mean);
	
	printf("\n\n Maior valor e sua posicao no vetor: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		if ( arr[i] > high ) {
			high = arr[i];
			pos = i;
		}
	}
	printf("%i e %i, respectivamente.", high, pos);
	
	printf("\n\n Menor valor e sua posicao no vetor: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		if ( arr[i] < low ) {
			low = arr[i];
			pos = i;
		}
	}
	printf("%i e %i, respectivamente.", low, pos);
	
	printf("\n\n Exiba os elementos repetidos: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		for ( c = i + 1 ; c < 5 ; c++ ) {
			if (arr[i] == arr[c] ) {
				printf("[%i]", arr[c]);
			}
		}
	}
	
	printf("\n\n Exiba os elementos nao repetidos: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		for ( c = i + 1 ; c < 5 ; c++ ) {
			if (arr[i] == arr[c] ) {
				rep = arr[c]; /* numero repetido */
				for ( i = 0 ; i < 5 ; i++ ) {
					if ( arr[i] != arr[c] ) { /* Só mostrar os nao repetidos */
						printf("[%i]", arr[i]);
					}
				}
			}
		}
	}
	
	printf("\n\n Exiba a frequencia de cada elemento: ");
	for ( i = 0 ; i < 5 ; i++ ) {
		for ( c = i + 1 ; c < 5 ; c++ ) {
			if (arr[i] == arr[c] ) {
				rep = arr[c]; /* numero repetido */
				printf("[%i] aparece 2 vezes ", arr[c]);
				for ( i = 0 ; i < 5 ; i++ ) {
					if ( arr[i] != arr[c] ) { /* Só mostrar os nao repetidos */
						printf("[%i]", arr[i]);
					}
				}
				printf(" aparece 1 vez");
			}
		}
	}
	
	
	return (0);
}
