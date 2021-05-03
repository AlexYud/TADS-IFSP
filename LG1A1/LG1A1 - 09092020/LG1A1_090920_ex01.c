/* bibliotecas */
#include <stdio.h>

/* variaveis */
int i = 0;

/* corpo do programa */
int main(){
	printf("\n\n Multiplos de 3 entre 0 e 100: ");
	for ( i ; i <= 100 ; i++ ) {
		if ( i % 3 == 0 ){
			printf(" -> %i", i);
		}
	}
	
	getch();
	return (0);
}

