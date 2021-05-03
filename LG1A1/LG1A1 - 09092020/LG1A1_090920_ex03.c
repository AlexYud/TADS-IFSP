/* bibliotecas */
#include <stdio.h>

/* variaveis */
int i = 0, numb, result = 0;

/* corpo do programa */
int main(){
	printf("\n\n Digite um numero inteiro positivo: ");
	scanf("%i", &numb);
	for ( i ; i <= numb ; i++ ){
		result = result + i;
	}
	printf("\n A soma dos %i primeiros numeros inteiros eh: %i", numb, result);
	getch();
	return (0);
}

