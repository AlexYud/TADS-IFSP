/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: admVacina												|
|	Descrição: módulo responsável pelo menu de opções de ADM VACINA			|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 10/03/2021 														|
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
	{	system ("cls"); system ("mode 48, 30"); system ("color E0");
		printf ("\n		  					 					   ");
		printf ("\n        	     VACINA         ");
		printf ("\n		  					 					   ");
		printf ("\n________________________________________________");
		printf ("\n		  					 					   ");
		printf ("\n    	  1. Cadastra vacinas	                   ");
		printf ("\n    	  2. Consulta vacinas                      ");
		printf ("\n    	  3. Cadastro default					   ");
		printf ("\n    	  4. Suportes							   ");
		printf ("\n    	  0. RETORNAR							   ");
		printf ("\n		  					 					   ");
		printf ("\n   	 Opção desejada: "); fflush(stdin); op = getche(); 
		if (  (op <'0' || op >'4')  ) {  	
			system ("cls");
			printf ("\n OPÇÃO INVÁLIDA!");
			getch();
		}
	} while (  (op <'0' || op >'4')  );
	return (op);
}

void analisa (char op)
{
	switch (op) { 
	   	case '1': system("cadastroVacinas");			break;
	   	case '2': system("consultaVacinas");			break;
	   	case '3': system("cadastroDefaultVacinas");		break;
	   	case '4': system("pilha");						break;
	   	case '0': exit(0);				
	}
}

/* Variaveis globais */



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
