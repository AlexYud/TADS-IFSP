/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: cadastroUsuario												|
|	Descrição: módulo responsável pelo cadastro de novos registros de médicos	|
|	Autor: Alexandre Yudi Inokawa de Oliveira									|
|	Prontuário: SP3046923														|
|	Data: 02/03/2021 															|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Tipos pré-definidos */
typedef struct
{
   	int    crm;
   	char   nome [50+1];
   	char   campC [1+1];
   	char   campD [10+1];
   	char   campE [10+1];
	char   campF [40+1];
	char   campG [2+1];
   	char   campH [150+1];	
}
registro;

/* Funções */
void cadastrar(char arquivo_dat[])
{
	FILE 				* ArqDat;
	registro			reg;
	char op;
	
	ArqDat = fopen (arquivo_dat, "ab");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao abrir arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
	
	// Limpa o registro 
	memset(reg.campH,       '\0', sizeof(reg.campH));
	memset(reg.campG,     '\0', sizeof(reg.campG));
	memset(reg.campF,     '\0', sizeof(reg.campF));
	memset(reg.campE,     '\0', sizeof(reg.campE));
	memset(reg.campD,     '\0', sizeof(reg.campD));
	memset(reg.campC,     '\0', sizeof(reg.campC));
	memset(reg.nome,     '\0', sizeof(reg.nome));
	reg.crm = 0;
	
	// Lê registro
	printf("\n Cadastro de usuário: \n");
	printf("\n CRM		: ");
	scanf("%i", &reg.crm);
	printf("\n NOME		: ");
	fflush(stdin); scanf("%[^\n]", &reg.nome);
	printf("\n ATIVIDADE(A/I) : ");
	fflush(stdin); scanf("%s", &reg.campC);
	printf("\n DATA1		: ");
	fflush(stdin); scanf("%s", &reg.campD);
	printf("\n DATA2		: ");
	fflush(stdin); scanf("%[^\n]", &reg.campE);
	printf("\n CIDADE		: ");
	fflush(stdin); scanf("%[^\n]", &reg.campF);
	printf("\n ESTADO(SIGLA)  : ");
	fflush(stdin); scanf("%s", &reg.campG);
	printf("\n ESPECIALIDADE : ");
	fflush(stdin); scanf("%[^\n]", &reg.campH);
	
	op: ;
	system("cls");
	printf("\n Deseja cadastrar [S/N]: ");
	printf ("\n [%6i] [%s] [%s] [%s] [%s] [%s] [%s] [%s]", reg.crm, reg.nome, reg.campC, reg.campD, reg.campE, reg.campF, reg.campG, reg.campH);
	printf("\n ");
	fflush(stdin); op = getche();
	if (  (op == 's' || op == 'S') || ( op == 'n' || op == 'N') ) {   
		if (op == 's' || op == 'S') {
			// Grava registro em REGISTROS.DAT     
    		if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   		printf ("\nErro ao gravar em %s!\a\a\a", arquivo_dat);
	   		getch();
			}
		}
		if ( op == 'n' ||  op == 'N') {
			exit(0);
		}
	} else {
		printf  ("\n Opção inválida!");
		goto op;
	}
	
	fclose (ArqDat);
	printf("\n\n Usuário cadastrado com sucesso!");
	getch();
}

/* Corpo Programa */
int main(void) {
	
	setlocale(LC_ALL, "");
	cadastrar("REGISTROS.DAT");
	system("ordenaRegistros");

	return 0;
}
