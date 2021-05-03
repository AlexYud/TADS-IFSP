/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do m�dulo: admMunicipes											|
|	Descri��o: m�dulo respons�vel pelo menu de op��es de ADM MUNICIPES		|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontu�rio: SP3046923													|
|	Data: 17/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Biblioteca */
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <locale.h>

/* Fun��es */
char menu (void)
{   char op;
	do
	{	system ("cls"); system ("mode 48, 22"); system ("color f0");
		printf ("\n		  					 					   ");
		printf ("\n        	  ADM MUNICIPES         ");
		printf ("\n		  					 					   ");
		printf ("\n________________________________________________");
		printf ("\n		  					 					   ");
		printf ("\n    	  1. Pr�-cadastro default	               ");
		printf ("\n    	  2. Pr�-cadastro individual               ");
		printf ("\n    	  3. Consulta mun�cipes					 ");
		printf ("\n    	  0. ENCERRAR						 ");
		printf ("\n		  					 					   ");
		printf ("\n   	 Op��o desejada: "); fflush(stdin); op = getche(); 
		if (  (op <'0' || op >'3')  ) {  	
			system ("cls");
			printf ("\n OP��O INV�LIDA!");
			getch();
		}
	} while (  (op <'0' || op >'3')  );
	return (op);
}

void analisa (char op)
{
	switch (op) { 
	   	case '1': system("converteMunicipes");	break;
	   	case '2': system("cadastroMunicipes");	break;
	   	case '3': system("consultaMunicipes");	break;
	   	case '0': exit(0);						
	}
}

/* Corpo do programa */
int main(void) {
	
	char opc;
    system("cls"); setlocale (LC_ALL, "");  
    do
    {
    	opc = menu();
    	analisa (opc);
	}
	while (opc!='S');
	
	
	return 0;
}
