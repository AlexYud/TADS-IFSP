/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: consultaMunicipes										|
|	Descrição: módulo responsável por consultar dados do arq MUNICIPES.DAT	|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 09/03/2021 														|
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
   	char   	nome [50+1];
   	char   	dataNascimento [10+1];
   	char   	CPF [11+1];
   	char   	pais [6+1];
	char   	estado [19+1];
	char   	municipio [40+1];
   	char   	logradouro [60+1];	
   	int		nro;
   	char 	complemento [20+1];
   	char	bairro [40+1];
   	int 	CEP;
   	char	email [40+1];
   	char 	cel [11+1];
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
	system ("cls"); system ("mode 80, 20"); system ("color 87");
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
		memset(reg.cel,     '\0', sizeof(reg.cel));
		memset(reg.email,       '\0', sizeof(reg.email));
		reg.CEP = 0;
		memset(reg.bairro,       '\0', sizeof(reg.bairro));
		memset(reg.complemento,       '\0', sizeof(reg.complemento)); 
		reg.nro = 0;
		memset(reg.logradouro,       '\0', sizeof(reg.logradouro));
		memset(reg.municipio,     '\0', sizeof(reg.municipio));
		memset(reg.estado,     '\0', sizeof(reg.estado));
		memset(reg.pais,     '\0', sizeof(reg.pais));
		memset(reg.CPF,     '\0', sizeof(reg.CPF));
		memset(reg.dataNascimento,     '\0', sizeof(reg.dataNascimento));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		
	    /* Lê campos do Csv */	
	    
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
        
        // Lê dataNascimento
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.dataNascimento[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.dataNascimento[--i] = '\0';
	    
	    // Lê CPF
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.CPF[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.CPF[--i] = '\0';
        
	    
	    // Lê país
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.pais[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.pais[--i] = '\0';
        
        // Lê estado
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.estado[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.estado[--i] = '\0';
	    
		// Lê município
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.municipio[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.municipio[--i] = '\0';
		
		// lê logradouro
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.logradouro[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.logradouro[--i] = '\0';
        
        // Lê nro
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.nro = atoi(aux_cod);
		
		// lê complemento
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.complemento[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.complemento[--i] = '\0';
		
		// lê bairro
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.bairro[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.bairro[--i] = '\0';
        
        // Lê CEP
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.CEP = atoi(aux_cod);
		
		// Lê email
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.email[i] = ch; 
	   	    i++;
	    }
	    while (ch != ';'); 
        reg.email[--i] = '\0';
        
        // Lê cel
	    i=0;
	    do
	    {
	   	    ch = fgetc(ArqCsv);
			reg.cel[i] = ch; 
	   	    i++;
	    }
	    while (ch != '\n' && ch != EOF); 
        reg.cel[--i] = '\0';
        	    
		cont++;

        // Grava registro em MUNICIPES.DAT     
        if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   	   	printf ("\n Erro ao gravar em %s!\a\a\a", arquivo_dat);
	   	   	getch();
	    }
       	
	    if ( cont == 30 ) {
	       	break; 
		}
	    	
	}
	fclose (ArqCsv);
	fclose (ArqDat);
	//printf ("\n Arquivo %s gerado com sucesso!", arquivo_dat);
}

void consulta_dat(void)
{
	FILE 				* ArqDat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 100, 200"); system ("color 03"); setlocale (LC_ALL, "");  

	TAMANHO_VETOR = findSize("MUNICIPES.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);

	ArqDat = fopen ("MUNICIPES.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo MUNICIPES.DAT");
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {	
		// Limpa o registro 
		memset(reg.cel,     '\0', sizeof(reg.cel));
		memset(reg.email,       '\0', sizeof(reg.email));
		reg.CEP = 0;
		memset(reg.bairro,       '\0', sizeof(reg.bairro));
		memset(reg.complemento,       '\0', sizeof(reg.complemento)); 
		reg.nro = 0;
		memset(reg.logradouro,       '\0', sizeof(reg.logradouro));
		memset(reg.municipio,     '\0', sizeof(reg.municipio));
		memset(reg.estado,     '\0', sizeof(reg.estado));
		memset(reg.pais,     '\0', sizeof(reg.pais));
		memset(reg.CPF,     '\0', sizeof(reg.CPF));
		memset(reg.dataNascimento,     '\0', sizeof(reg.dataNascimento));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
			printf ("\n\n %5i->[%-50s][%-10s][%-11s][%-6s][%-19s][%-40s][%-60s][%4i][%-20s][%-40s][%8i][%-40s][%-11s]", 
			(int)cont, reg.nome, reg.dataNascimento, reg.CPF, reg.pais, reg.estado, reg.municipio, reg.logradouro, reg.nro, reg.complemento, reg.bairro, reg.CEP, reg.email, reg.cel);	
		} else {
			break;
		}
				
		if (feof(ArqDat)) break;
	}
    fclose(ArqDat);
    getch();
}

void consulta_dat_em_relatorio(void)
{
	FILE 				* ArqDat, *Relat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 30, 4"); system ("color 03");

	TAMANHO_VETOR = findSize("MUNICIPES.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);

	ArqDat = fopen ("MUNICIPES.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao ler arquivo MUNICIPES.DAT");
		getch();
		exit(0);
	}
	
	Relat = fopen ("RELAT_MUNICIPES.TXT", "wt");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao gerar arquivo RELAT_MUNICIPES.TXT");
		getch();
		exit(0);
	}
	
	fprintf (Relat, "_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
	fprintf (Relat, "    #         	         NomeCompleto                         DataNascimento         CPF	  País       	      Estado                            Município                                            Logradouro                                  Nro         Complemento       			Bairro       			    CEP       		        E-mail       	              TelefoneCelular\n");
	fprintf (Relat, "_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
	while ( !feof(ArqDat) ) {
		// Limpa o registro 
		memset(reg.cel,     '\0', sizeof(reg.cel));
		memset(reg.email,       '\0', sizeof(reg.email));
		reg.CEP = 0;
		memset(reg.bairro,       '\0', sizeof(reg.bairro));
		memset(reg.complemento,       '\0', sizeof(reg.complemento)); 
		reg.nro = 0;
		memset(reg.logradouro,       '\0', sizeof(reg.logradouro));
		memset(reg.municipio,     '\0', sizeof(reg.municipio));
		memset(reg.estado,     '\0', sizeof(reg.estado));
		memset(reg.pais,     '\0', sizeof(reg.pais));
		memset(reg.CPF,     '\0', sizeof(reg.CPF));
		memset(reg.dataNascimento,     '\0', sizeof(reg.dataNascimento));
		memset(reg.nome,     '\0', sizeof(reg.nome));
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
			fprintf (Relat,"\n%5i->[%-50s]\t[%-10s]\t[%-11s]\t[%-6s]\t[%-19s]\t[%-40s]\t[%-60s]\t[%4i]\t[%-20s]\t[%-40s]\t[%8i]\t[%-40s]\t[%-11s]", 
			(int)cont, reg.nome, reg.dataNascimento, reg.CPF, reg.pais, reg.estado, reg.municipio, reg.logradouro, reg.nro, reg.complemento, reg.bairro, reg.CEP, reg.email, reg.cel);	
		} else {
			break;
		}
	}
    fclose(ArqDat);
    fclose(Relat);
    system("notepad RELAT_MUNICIPES.TXT");
    getch();
}

/*-------------------------------------------------------------------------------------------*/

int main(void) {
	
	gera_dat ("MUNICIPES.CSV", "MUNICIPES.DAT");
	//consulta_dat();
	consulta_dat_em_relatorio();
	
	return 0;
}
