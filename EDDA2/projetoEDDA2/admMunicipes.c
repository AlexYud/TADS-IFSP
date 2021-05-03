/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: admMunicipes											|
|	Descrição: módulo responsável pelo menu de opções de ADM MUNICIPES		|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 17/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Biblioteca */
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <locale.h>

/* Funções */
char menu (void)
{   char op;
	do
	{	system ("cls"); system ("mode 48, 22"); system ("color f0");
		printf ("\n		  					 					   ");
		printf ("\n        	  ADM MUNICIPES         ");
		printf ("\n		  					 					   ");
		printf ("\n________________________________________________");
		printf ("\n		  					 					   ");
		printf ("\n    	  1. Pré-cadastro default	               ");
		printf ("\n    	  2. Pré-cadastro individual               ");
		printf ("\n    	  3. Consulta munícipes					 ");
		printf ("\n    	  0. ENCERRAR						 ");
		printf ("\n		  					 					   ");
		printf ("\n   	 Opção desejada: "); fflush(stdin); op = getche(); 
		if (  (op <'0' || op >'3')  ) {  	
			system ("cls");
			printf ("\n OPÇÃO INVÁLIDA!");
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
