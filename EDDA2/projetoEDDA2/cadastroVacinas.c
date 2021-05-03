/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: cadastroVacinas												|
|	Descrição: módulo responsável pelo cadastro de novas vacinas				|
|	Autor: Alexandre Yudi Inokawa de Oliveira									|
|	Prontuário: SP3046923														|
|	Data: 10/03/2021 															|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <locale.h>

/* Tipos pré-definidos */
typedef struct
{
   	int		id;
   	char	nome[15+1];
   	char	fab[28+1];
   	char	tipo[43+1];
   	int		doses;
   	char	eficacia[9+1];
   	char	armazenamento[50+1];
}
registro;

/* variáveis globais */
long int     TAMANHO_VETOR;
long int     qtd_registros;

/* Funções */
long int findSize(char file_name[]) 
{ 
    FILE* fp = fopen(file_name, "r");   
    if (fp == NULL) { 
    	printf("\n Arquivo não encontrado!\n"); 
        return -1; 
    } 
    fseek(fp, 0L, SEEK_END); 
    long int res = ftell(fp); 
    fclose(fp); 
    return res; 
}

void cadastrar(char arquivo_dat[])
{
	FILE 				* ArqDat;
	registro			reg;
	char op;
	
	TAMANHO_VETOR = findSize("VACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);
	
	ArqDat = fopen (arquivo_dat, "ab");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao abrir arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
	
	// Limpa o registro 
	memset(reg.armazenamento,     '\0', sizeof(reg.armazenamento));
	memset(reg.eficacia,     '\0', sizeof(reg.eficacia));
	reg.doses = 0;
	memset(reg.tipo,     '\0', sizeof(reg.tipo));
	memset(reg.fab,     '\0', sizeof(reg.fab));
	memset(reg.nome,     '\0', sizeof(reg.nome));
	
	// Lê registro
	printf("\n CADASTRO DE VACINA: \n");
	printf("\n ID		: %i\n", qtd_registros+1);
	reg.id = qtd_registros+1;
	printf("\n NOME VACINA	: ");
	fflush(stdin); scanf("%[^\n]", &reg.nome);
	printf("\n FABRICANTE	: ");
	fflush(stdin); scanf("%[^\n]", &reg.fab);
	printf("\n TIPO		: ");
	fflush(stdin); scanf("%[^\n]", &reg.tipo);
	printf("\n DOSES		: ");
	fflush(stdin); scanf("%i", &reg.doses);
	printf("\n EFICÁCIA	: ");
	fflush(stdin); scanf("%[^\n]", &reg.eficacia);
	printf("\n ARMAZENAMENTO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.armazenamento);
	
	op: ;
	system("cls");  system ("mode 80, 10");
	printf("\n Deseja cadastrar [S/N]: ");
	printf ("\n\n [%i] [%s] [%s] [%s] [%i] [%s] [%s]", reg.id, reg.nome, reg.fab, reg.tipo, reg.doses, reg.eficacia, reg.armazenamento);
	printf("\n\n ");
	fflush(stdin); op = getche();
	if (  (op == 's' || op == 'S') || ( op == 'n' || op == 'N') ) {   
		if (op == 's' || op == 'S') {
			// Grava registro em VACINAS.DAT     
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
	system ("cls"); system ("mode 30, 10");
	printf("\n\n Vacina cadastrada com sucesso!");
	getch();
}

/* Corpo Programa */
int main(void) {
	
	system ("cls"); system ("mode 60, 20"); system ("color 03"); setlocale (LC_ALL, ""); 
	cadastrar("VACINAS.DAT");
	system("cadastroLotesVacinas");

	return 0;
}
