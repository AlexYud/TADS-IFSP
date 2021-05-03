/* bibliotecas */
#include <stdio.h>

/* variaveis */
int casas = 2, graos = 1;

/* corpo do programa */
int main(){
	for ( casas ; casas <= 16 ; casas++ ) {
		graos = graos * 2;
	}
	graos = graos + 1; /* Mais o primeiro grao da primeira casa */
	printf("\n\n Serao %i graos", graos);
	
	return (0);
}

