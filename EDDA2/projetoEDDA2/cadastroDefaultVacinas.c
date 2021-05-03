/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: cadastroDefaultVacinas									|
|	Descrição: módulo responsável por converter os registros CSV para DAT	|
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
    	printf("\n Arquivo não encontrado!\n"); 
        return -1; 
    } 
    fseek(fp, 0L, SEEK_END); 
    long int res = ftell(fp); 
    fclose(fp); 
    return res; 
}

void gera_dat (char arquivo_csv[], char arquivo_dat[])
{
	FILE 				* ArqCsv;
	FILE 				* ArqDat;
	registro			reg;
	char				ch;
	char                aux_cod[11];
	long int 			cont=0;
	long int 			auxn; 
	int					i;
	//system ("cls"); system ("mode 80, 20"); system ("color 87");
	//printf ("\n Abrindo %s", arquivo_csv);
	
	ArqCsv = fopen (arquivo_csv, "r");
	if ( ArqCsv==NULL ) {
		system ("cls");
		printf ("\n Erro ao abrir arquivo %s", arquivo_csv);
		getch();
		exit(0);
	}
	//printf ("\n Abrindo %s",arquivo_dat);
	ArqDat = fopen (arquivo_dat, "wb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao criar arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
    //printf ("\n Convertendo %s para %s", arquivo_csv, arquivo_dat);		
	while  ( !feof(ArqCsv) ) 
	{   // Limpa o registro
		memset(reg.armazenamento,     '\0', sizeof(reg.armazenamento));
		memset(reg.eficacia,     '\0', sizeof(reg.eficacia));
		reg.doses = 0;
		memset(reg.tipo,     '\0', sizeof(reg.tipo));
		memset(reg.fab,     '\0', sizeof(reg.fab));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		reg.id = 0;
		
	    /* Lê campos do Csv */	
	    
	   	// Lê id
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.id = atoi(aux_cod);
        
        // Lê nome
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.nome[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.nome[--i] = '\0';
	    
	    // Lê fab
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.fab[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.fab[--i] = '\0';
        
	    
	    // Lê tipo
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.tipo[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.tipo[--i] = '\0';
        
        // Lê doses
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.doses = atoi(aux_cod);
	    
		// Lê município
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.eficacia[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.eficacia[--i] = '\0';
		
		// lê armazenamento
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.armazenamento[i] = ch; 
	   	    i++;
	    }
	    while (ch != '\n' && ch != EOF); 
        reg.armazenamento[--i] = '\0';
        	    
		cont++;

        // Grava registro em VACINAS.DAT     
        if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   	   	printf ("\n Erro ao gravar em %s!\a\a\a", arquivo_dat);
	   	   	getch();
	    }
       	
	    if ( cont == 5 ) {
	       	break; 
		}
	    	
	}
	fclose (ArqCsv);
	fclose (ArqDat);
	printf ("\n Arquivo %s gerado com sucesso!", arquivo_dat);
    getch();
}

void consulta_dat_em_relatorio(void)
{
	FILE 				* ArqDat, *Relat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 30, 4"); system ("color 03");

	TAMANHO_VETOR = findSize("VACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);

	ArqDat = fopen ("VACINAS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao ler arquivo VACINAS.DAT");
		getch();
		exit(0);
	}
	
	Relat = fopen ("RELAT_VACINAS.TXT", "wt");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao gerar arquivo RELAT_VACINAS.TXT");
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {
		// Limpa o registro 
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
			fprintf (Relat,"\n%5i->[%2i]\t[%-16s]\t[%-29s]\t[%-44s]\t[%2i]\t[%-10s]\t[%-51s]", 
			(int)cont, reg.id, reg.nome, reg.fab, reg.tipo, reg.doses, reg.eficacia, reg.armazenamento);	
		} else {
			break;
		}
	}
    fclose(ArqDat);
    fclose(Relat);
    system("notepad RELAT_VACINAS.TXT");
    getch();
}

/*-------------------------------------------------------------------------------------------*/

int main(void) {
	
	gera_dat ("VACINAS.CSV", "VACINAS.DAT");
	
	return 0;
}
