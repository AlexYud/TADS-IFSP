/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: consultaVacinas											|
|	Descrição: módulo responsável por consultar os registros de VACINAS.DAT	|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 10/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

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

/*------------------Funções específicas para a conversão do .CSV em .DAT --------------------*/
long int findSize(char file_name[]) 
{ 
    FILE* fp = fopen(file_name, "r");   
    if (fp == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
    fseek(fp, 0L, SEEK_END); 
    long int res = ftell(fp); 
    fclose(fp); 
    return res; 
}

void consulta_dat(void)
{
	FILE 				* ArqDat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 165, 15"); system ("color 03");

	TAMANHO_VETOR = findSize("VACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	ArqDat = fopen ("VACINAS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo VACINAS.DAT");
		getch();
		exit(0);
	}
	
	printf ("\n 						CONSULTA VACINAS CADASTRADAS EM VACINAS.DAT	\n");
	printf ("_____________________________________________________________________________________________________________________________________________________________________\n");
	printf ("\n Id	Vacina			Fabricante				Tipo		   Doses Eficácia		Armazenamento	\n");
	while ( !feof(ArqDat) )
	{	// Limpa o registro 
		memset(reg.armazenamento,     '\0', sizeof(reg.armazenamento));
		memset(reg.eficacia,     '\0', sizeof(reg.eficacia));
		reg.doses = 0;
		memset(reg.tipo,     '\0', sizeof(reg.tipo));
		memset(reg.fab,     '\0', sizeof(reg.fab));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		reg.id = 0;
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
		if ( !feof(ArqDat) ) {
			printf ("\n%2i %-16s %-29s %-44s %i %-10s %-51s", 
			reg.id, reg.nome, reg.fab, reg.tipo, reg.doses, reg.eficacia, reg.armazenamento);
		} else {
			break;
		}
				
		if (feof(ArqDat)) break;
	}
    fclose(ArqDat);
    getch();
}

int main(void) {
	
	setlocale (LC_ALL, "");  
	consulta_dat();
	
	return 0;
}
