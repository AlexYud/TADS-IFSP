/* bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* variaveis */
int num1, num2, n, i, valorTermo;

/* corpo do programa */
int main(){
	
	printf("Digite o primeiro n�mero:");
	scanf("%d", &num1);
	printf("Digite o segundo n�mero:");
	scanf("%d", &num2);
	printf("Digite a quantidade de termos: ");
	scanf("%d", &n);
	if(n < 3) {
		printf("A quantidade m�nima de termos � 3.\n");
	}
	printf("[%d]\n", num1);
	printf("[%d]\n", num2);
	for(i = 3; i < n; i++) //Como a quantidade de termos m�nima � 3 o i come�a com o valor 3 (m�nimo)
	{
	if(i % 2 == 0) {
		valorTermo = num2 - num1; //para i par.
	} else {
		valorTermo = num2 + num1; //para i impar
	}
	printf("[%d]",valorTermo);
	num1 = num2;
	num2 = valorTermo;
	}
	return 0;
}	
