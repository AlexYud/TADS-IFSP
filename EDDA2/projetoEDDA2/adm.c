/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do m�dulo: adm														|
|	Descri��o: m�dulo respons�vel pelo menu de op��es de ADM 				|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontu�rio: SP3046923													|
|	Data: 08/03/2021 														|
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
	{	system ("cls"); system ("mode 48, 22"); system ("color B0");
		printf ("\n		  					 					   ");
		printf ("\n        	  ADM VACINA         ");
		printf ("\n		  					 					   ");
		printf ("\n________________________________________________");
		printf ("\n		  					 					   ");
		printf ("\n    	  1. Pr�-cadastro de cidad�os	               ");
		printf ("\n    	  2. Cadastro de vacinas                      ");
		printf ("\n    	  3. Atendimento					           ");
		printf ("\n    	  0. ENCERRAR								   ");
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
	   	case '1': system("admMunicipes");		break;
	   	case '2': system("admVacina");			break;
	   	case '3': system("atendimento");		break;
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
