/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: cadastroLotesVacinas									|
|	Descrição: módulo responsável por converter e cadastrar novos lotes		|
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
   	int		idLote;
   	int		qtdFrascos;
   	char	dataFabr[10+1];
   	char	dataVenc[10+1];
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
	char                aux_cod[8];
	long int 			cont=0;
	long int 			auxn; 
	int					i;
	
	TAMANHO_VETOR = findSize("LOTESVACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	system ("cls"); system ("mode 80, 20"); system ("color 87");
	printf ("\n Abrindo %s", arquivo_csv);
	
	ArqCsv = fopen (arquivo_csv, "r");
	if ( ArqCsv==NULL ) {
		system ("cls");
		printf ("\n Erro ao abrir arquivo %s", arquivo_csv);
		getch();
		exit(0);
	}
	printf ("\n Abrindo %s",arquivo_dat);
	ArqDat = fopen (arquivo_dat, "wb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao criar arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
    printf ("\n Convertendo %s para %s", arquivo_csv, arquivo_dat);		
	while  ( !feof(ArqCsv) ) 
	{   // Limpa o registro
		memset(reg.dataVenc,     '\0', sizeof(reg.dataVenc));
		memset(reg.dataFabr,     '\0', sizeof(reg.dataFabr));
		reg.qtdFrascos = 0;
		reg.idLote = 0;
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
        
        // Lê idLote
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.idLote = atoi(aux_cod);
	    
	    // Lê qtdFrascos
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.qtdFrascos = atoi(aux_cod);
	    
	    // Lê dataFabr
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.dataFabr[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.dataFabr[--i] = '\0';
        
        // Lê dataVenc
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.dataVenc[i] = ch;
	   	 	i++;
	    }
	    while (ch != '\n' && ch != EOF); 
        reg.dataVenc[--i] = '\0';
        	    
		cont++;

        // Grava registro em LOTESVACINAS.DAT     
        if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   	   	printf ("\n Erro ao gravar em %s!\a\a\a", arquivo_dat);
	   	   	getch();
	    }
       	
	    if ( cont == qtd_registros ) {
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
	
	system ("cls"); system ("mode 100, 200"); system ("color 03"); setlocale (LC_ALL, "");  

	TAMANHO_VETOR = findSize("LOTESVACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	ArqDat = fopen ("LOTESVACINAS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo LOTESVACINAS.DAT");
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {	
		// Limpa o registro 
		memset(reg.dataVenc,     '\0', sizeof(reg.dataVenc));
		memset(reg.dataFabr,     '\0', sizeof(reg.dataFabr));
		reg.qtdFrascos = 0;
		reg.idLote = 0;
		reg.id = 0;
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
			printf ("\n\n [%2i][%8i][%2i][%-10s][%-10s]", 
			reg.id, reg.idLote, reg.qtdFrascos, reg.dataFabr, reg.dataVenc);	
		} else {
			break;
		}
				
		if (feof(ArqDat)) break;
	}
    fclose(ArqDat);
    getch();
}

void cadastrar(char arquivo_dat[])
{
	FILE 				* ArqDat;
	registro			reg;
	char op;
	
	TAMANHO_VETOR = findSize("LOTESVACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);
	
	system ("color 87");
	
	ArqDat = fopen (arquivo_dat, "ab");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao abrir arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
	
	// Limpa o registro 
	memset(reg.dataVenc,     '\0', sizeof(reg.dataVenc));
	memset(reg.dataFabr,     '\0', sizeof(reg.dataFabr));
	reg.qtdFrascos = 0;
	reg.idLote = 0;
	reg.id = 0;
	
	// Lê registro
	printf("\n CADASTRO DE LOTE: \n");
	printf("\n ID VACINA	: ");
	fflush(stdin); scanf("%i", &reg.id);
	printf("\n ID LOTE	: ");
	fflush(stdin); scanf("%i", &reg.idLote);
	printf("\n QTD FRASCOS	: ");
	fflush(stdin); scanf("%i", &reg.qtdFrascos);
	printf("\n DATA FABR	: ");
	fflush(stdin); scanf("%s", &reg.dataFabr);
	printf("\n DATA VENC	: ");
	fflush(stdin); scanf("%s", &reg.dataVenc);
	
	op: ;
	system("cls");  system ("mode 80, 10");
	printf("\n Deseja cadastrar [S/N]: ");
	printf ("\n\n [%i] [%i] [%i] [%s] [%s] ", reg.id, reg.idLote, reg.qtdFrascos, reg.dataFabr, reg.dataVenc);
	printf("\n\n ");
	fflush(stdin); op = getche();
	if (  (op == 's' || op == 'S') || ( op == 'n' || op == 'N') ) {   
		if (op == 's' || op == 'S') {
			// Grava registro em LOTESVACINAS.DAT     
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
	printf("\n\n Lote cadastrado com sucesso!");
	getch();
}

int main(void) {
	
	//gera_dat ("LOTESVACINAS.CSV", "LOTESVACINAS.DAT");
	//consulta_dat();
	cadastrar("LOTESVACINAS.DAT");
	
	
	return 0;
}
