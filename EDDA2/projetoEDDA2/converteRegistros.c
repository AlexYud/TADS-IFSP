/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: converteRegistros										|
|	Descrição: módulo responsável por converter os registros CSV para DAT	|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 01/03/2021 														|
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

void gera_dat (char arquivo_csv[], char arquivo_dat[])
{
	FILE 				* ArqCsv;
	FILE 				* ArqDat;
	registro			reg;
	char				ch;
	char                aux_cod[10];
	long int 			cont=0;
	int					i;
	system ("cls"); system ("mode 80, 20"); system ("color 87");
	printf ("\nAbrindo %s", arquivo_csv);
	
	ArqCsv = fopen (arquivo_csv, "r");
	if ( ArqCsv==NULL )
	{
		system ("cls");
		printf ("Erro ao abrir arquivo %s", arquivo_csv);
		getch();
		exit(0);
	}
	printf ("\nAbrindo %s",arquivo_dat);
	ArqDat = fopen (arquivo_dat, "wb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao criar arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
    printf ("\nConvertendo %s para %s", arquivo_csv, arquivo_dat);		
	while  ( !feof(ArqCsv) ) 
	{   // Limpa o registro 
		memset(reg.campH,       '\0', sizeof(reg.campH));
		memset(reg.campG,     '\0', sizeof(reg.campG));
		memset(reg.campF,     '\0', sizeof(reg.campF));
		memset(reg.campE,     '\0', sizeof(reg.campE));
		memset(reg.campD,     '\0', sizeof(reg.campD));
		memset(reg.campC,     '\0', sizeof(reg.campC));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		reg.crm = 0;
		
	    /* Lê campos do Csv */	
	    // Lê código
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.crm = atoi(aux_cod);
	    
	    // lê nome
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.nome[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.nome[--i] = '\0';
	    
		// campC
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campC[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.campC[--i] = '\0';
		
		// campD
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campD[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.campD[--i] = '\0';
		
		// campE
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campE[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.campE[--i] = '\0';
		
		// campF
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campF[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.campF[--i] = '\0';
		
		// campG
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campG[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.campG[--i] = '\0';
		
		// Lê município
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.campH[i] = ch; 
	   	    i++;
	    }
	    while (ch != '\n' && ch != EOF); 
        reg.campH[--i] = '\0';
	    
		cont++;

        // Grava registro em REGISTROS.DAT     
        if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   	   	printf ("\n Erro ao gravar em %s!\a\a\a", arquivo_dat);
	   	   	getch();
	    }
       	
	    if ( cont == 216682 ) {
	       	break; 
		}
	    	
	}
	fclose (ArqCsv);
	fclose (ArqDat);
	printf ("\n Arquivo %s gerado com sucesso!", arquivo_dat);
    getch();
}

void consulta_dat(void)
{
	FILE 				* ArqDat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 80, 50"); system ("color 03");

	TAMANHO_VETOR = findSize("REGISTROS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	ArqDat = fopen ("REGISTROS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo REGISTROS.DAT");
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) )
	{	// Limpa o registro 
		memset(reg.campH,       '\0', sizeof(reg.campH));
		memset(reg.campG,     '\0', sizeof(reg.campG));
		memset(reg.campF,     '\0', sizeof(reg.campF));
		memset(reg.campE,     '\0', sizeof(reg.campE));
		memset(reg.campD,     '\0', sizeof(reg.campD));
		memset(reg.campC,     '\0', sizeof(reg.campC));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		reg.crm = 0;
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
		if ( !feof(ArqDat) ) {
			printf ("\n%5i->[%6i]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]", 
			(int)cont, reg.crm, reg.nome, reg.campC, reg.campD, reg.campE, reg.campF, reg.campG, reg.campH);
		} else {
			break;
		}
				
		//if (feof(ArqDat)) break;
	}
	//printf("\n fora do while arquivo aberto");
    fclose(ArqDat);
    //printf("\n arquivo fechado");
    getch();
}

void consulta_dat_em_relatorio(void)
{
	printf("\n dentro do consulta dat em relatorio");
	FILE 				* ArqDat, *Relat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 30, 4"); system ("color 03");

	TAMANHO_VETOR = findSize("REGISTROS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	ArqDat = fopen ("REGISTROS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo REGISTROS.DAT");
		getch();
		exit(0);
	}
	
	Relat = fopen ("RELAT_REGISTROS.TXT", "wt");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao gerar arquivo RELAT_REGISTROS.TXT");
		getch();
		exit(0);
	}
	
	fprintf (Relat, "______________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
	fprintf (Relat, "#         CRM	         NOME                                                                                                   MUNICÍPIO\n");
	fprintf (Relat, "______________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
	while ( !feof(ArqDat) )
	{
		// Limpa o registro 
		memset(reg.campH,       '\0', sizeof(reg.campH));
		memset(reg.campG,     '\0', sizeof(reg.campG));
		memset(reg.campF,     '\0', sizeof(reg.campF));
		memset(reg.campE,     '\0', sizeof(reg.campE));
		memset(reg.campD,     '\0', sizeof(reg.campD));
		memset(reg.campC,     '\0', sizeof(reg.campC));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		reg.crm = 0;
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
		if ( !feof(ArqDat) )
			fprintf (Relat,"\n%5i->[%6i]\t[%-50s]\t[%-1s]\t[%-10s]\t[%-10s]\t[%-40s]\t[%-2s]\t[%-150s]", 
			(int)cont, reg.crm, reg.nome, reg.campC, reg.campD, reg.campE, reg.campF, reg.campG, reg.campH);
		
		if (feof(ArqDat)) break; 		
	}
    fclose(ArqDat);
    fclose(Relat);
    system ("notepad RELAT_REGISTROS.TXT");
    getch();
}

/*-------------------------------------------------------------------------------------------*/

int main(void) {
	
	gera_dat ("MEDICOSCREMESP.CSV", "REGISTROS.DAT");
	//consulta_dat();
	consulta_dat_em_relatorio();
	//system ("ordenaRegistros");
	
	return 0;
}
