/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: ordenaRegistros											|
|	Descrição: módulo responsável por ordenar os registros DAT pelo CRM		|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 04/03/2021 														|
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

int esquerdo(int i) 
{
	return (2*i+1);
}

int direito(int i) 
{
  	return (2*i+2);
}

int pai(int i) 
{
  	return (i/2);
}

void troca (registro *A, registro *B) 
{
  	registro aux = *A; 
  	*A = *B; 
  	*B = aux;
}

void BuildHeap (registro	* vet_reg)
{
   	long int i, atual;
   	for(i=1; i<qtd_registros; i++) 
   	{
      	atual = i;
      	
      	while(atual > 0 && vet_reg[atual].crm > vet_reg[pai(atual)].crm) 
      	{
      		troca(  &vet_reg[atual], &vet_reg[pai(atual)] ); 
        	atual = pai(atual); 
      	}
   	}
}

void heap_sort (registro	* vetor) {   
	
	long int i, atual;

    for(i=qtd_registros-1; i>0; i--) 
    { 
        troca(  &vetor[0], &vetor[i]  ); 
        
        atual = 0;
        while ( direito(atual) <= (i-1) && ( vetor[atual].crm < vetor[esquerdo(atual)].crm || vetor[atual].crm < vetor[direito(atual)].crm  ) ) {
            if ( vetor[esquerdo(atual)].crm > vetor[direito(atual)].crm ) 
            {
            	troca(  &vetor[atual], &vetor[esquerdo(atual)]  ); 
                atual = esquerdo(atual);
            } 
			else 
			{
				troca(  &vetor[atual], &vetor[direito(atual)]  ); 
                atual = direito(atual);
            }
        }
        
        if ( esquerdo(atual) <= i-1 && vetor[atual].crm < vetor[esquerdo(atual)].crm ) {
            troca(  &vetor[atual], &vetor[esquerdo(atual)]  ); 
            atual = esquerdo(atual);
        }
    }
}

/*-------------------------------------------------------------------------------------------*/
long int findSize(char file_name[]) 
{ 
    FILE* fp = fopen(file_name, "r");   
    if (fp == NULL) { 
        printf(" Arquivo não encontrado!\n"); 
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
	system ("cls"); system ("mode 130, 100"); system ("color 87");
	
	ArqCsv = fopen (arquivo_csv, "w+");
	if ( ArqCsv==NULL )
	{
		system ("cls");
		printf ("Erro ao abrir arquivo %s", arquivo_csv);
		getch();
		exit(0);
	}
	ArqDat = fopen (arquivo_dat, "wb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao criar arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}		
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
	    
	    // Lê nome da escola
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	reg.nome[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        reg.nome[--i] = '\0';
	    
		// Lê município
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
		
		//para debug: mostra registro do Dat
	    printf ("\n%i->[%6i][%s][%s][%s][%s][%s][%s][%s]", cont, reg.crm, reg.nome, reg.campC, reg.campD, reg.campE, reg.campF, reg.campG, reg.campH);

        // Grava registro em REGISTROS.DAT     
        if ( fwrite (&reg, sizeof(reg), 1, ArqDat) != 1 ) {
	   	   	printf ("\nErro ao gravar em %s!\a\a\a", arquivo_dat);
	   	   	getch();
	    }
       
	    if ( cont == 216682 ) {
	    	break; 
		}
	       
	}
	fclose (ArqCsv);
	fclose (ArqDat);
	printf ("\nArquivo %s gerado com sucesso!", arquivo_dat);
    getch();
}

void consulta_dat_em_relatorio(void)
{
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
	fprintf (Relat, "#         CRM	        	      NOME                           ATIVIDADE      DATA1          DATA2                         CIDADE			       ESTADO			ESPECIALIDADE\n");
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

void abastece_vetor (registro	* vet_reg)
{   
	int i=0;
   	FILE * ArqDat;
	ArqDat = fopen ("REGISTROS.DAT", "rb+");
	if ( ArqDat==NULL )
	{	
		system ("cls");
		printf ("Erro ao abrir arquivo REGISTROS.DAT para leitura");
		getch();
		exit(0);
	}
	//printf ("\nSucesso ao abrir arquivo REGISTROS.DAT para leitura");
	
	while ( !feof(ArqDat) )
	{	
		// Lê um registro do arquivo REGISTROS.DAT para o vetor (um de cada vez)
	    fread (&vet_reg[i], sizeof(vet_reg[i]), 1, ArqDat);
	    // Testa se deu erro de leitura
   	    if ( ferror(ArqDat) )
   	    {  
		   	system ("cls");
		   	printf ("Erro ao ler arquivo REGISTROS.DAT no registro [%i]",i);
		   	getch();
		   	exit(0);	
		}
		i++;
		if (feof(ArqDat)){
			break;	
		}
	}
    fclose(ArqDat); 
}

void mostra_codigos_arq  (registro	* vet_reg)
{
    long int i;
    FILE *AUX = fopen ("crm.CSV", "w");
    for (i=0; i<qtd_registros; i++)
    {
       fprintf (AUX, "%s;%s;%s;%s;%s;%s;%s;%s", 
	   vet_reg[i].crm, vet_reg[i].nome, vet_reg[i].campC, vet_reg[i].campD, vet_reg[i].campE, vet_reg[i].campF, vet_reg[i].campG, vet_reg[i].campH);
	   if (i<qtd_registros-1) fprintf (AUX, "\n");
    }
    fclose (AUX);
    //system ("excel crm.CSV");
    system ("notepad crm.CSV");
}

void mostra_codigos  (registro	* vet_reg)
{
    long int i;
    printf ("\n_______________________________________________________________________\n");
	for (i=0; i<qtd_registros; i++)
    {
       printf ("%s;%s;%s;%s;%s;%s;%s;%s", 
	   vet_reg[i].crm, vet_reg[i].nome, vet_reg[i].campC, vet_reg[i].campD, vet_reg[i].campE, vet_reg[i].campF, vet_reg[i].campG, vet_reg[i].campH);
	   if (i<qtd_registros-1) printf ("\n");
    }
    printf ("\n_______________________________________________________________________\n");
}

void envia_vet_ordenado_dat (registro	* vet_reg)
{
    long int i;
   	FILE * ArqDat;
	ArqDat = fopen ("REGISTROS.DAT", "wb+");
	if ( ArqDat==NULL )
	{	system ("cls");
		printf ("Erro ao gerar arquivo REGISTROS.DAT ordenado!");
		getch();
		exit(0);
	}
    for (i=0; i<qtd_registros; i++)
    {
    	fwrite (&vet_reg[i], sizeof(vet_reg[i]), 1, ArqDat);
    	if ( ferror(ArqDat) )
   	    {  system ("cls");
		   printf ("Erro ao gravar no arquivo REGISTROS.DAT no registro %li!", i);
		   getch();
		   exit(0);	
		}
	}
	fclose(ArqDat);
	printf ("\n REGISTROS.DAT ordenado com sucesso!");
	getch();
}

void teste_heapsort(void)
{
	FILE * ArqDat;
	registro		* vet_reg;

 	TAMANHO_VETOR = findSize("REGISTROS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);
    system ("cls"); system ("mode 40, 10"); system ("color f7");
    // para debug
	if (TAMANHO_VETOR != -1) 
	{
	    //printf("Tamanho do arquivo REGISTROS.DAT em bytes = %ld e tem %ld registros\n", TAMANHO_VETOR, qtd_registros );
        //Sleep(2000);
    }
	/* Tenta alocar um vetor com o tamanho do arquivo */   
    vet_reg = (registro *) malloc (qtd_registros * sizeof (registro)); 
    if (vet_reg == NULL)
    {
        printf ("malloc devolveu NULL!\nNão foi possível alocar %ld bytes.", 
		(qtd_registros * sizeof (registro)) );
        getch();
        exit (EXIT_FAILURE);
    }
    else
    {
    	//printf ("\nAlocação de memória bem-sucedida!");
    	//printf ("\nmalloc alocou %ld bytes", (qtd_registros * sizeof (registro)) );
    	//printf ("\nO arquivo REGISTROS.DAT possui %ld bytes", TAMANHO_VETOR);
    	//printf ("\nO arquivo REGISTROS.DAT possui %ld registros", qtd_registros);
    	//Sleep(1000);
	}
    
    //printf ("\n\nAbastecendo o conteúdo do vetor...");
    abastece_vetor(vet_reg);  		/* abastece o vetor com os registros de REGISTROS.DAT */
    //printf ("\nExibindo o conteúdo do vetor...");
    //mostra_codigos(vet_reg);  		/* exibe os valores de CRM              */ 
	//Sleep(2000); 
    
	BuildHeap (vet_reg);      		/* transforma o vetor num heap                      */
	//printf ("\nExibindo o heap de máximo construído...");
    //mostra_codigos(vet_reg);  		/* exibe os valores de CRM              */   
    //Sleep(2000); 
    
    //printf ("\n\nOrdenando vetor...");
	heap_sort(vet_reg);       		/* faz a ordenação por heap_sort                    */
    //printf ("\nExibindo o vetor ordenado...");
	//mostra_codigos(vet_reg);  		/* exibe os valores de CRM JÁ ORDENADOS */   
    //Sleep(2000);
    
	/* transfere o vetor ordenado para REGISTROS.DAT      */
	//printf ("\nTransferindo o vetor ordenado para REGISTROS.DAT...");
	envia_vet_ordenado_dat (vet_reg);
    //gera_dat ("crm.CSV", "REGISTROS.DAT"); 
    consulta_dat_em_relatorio();
}

/* corpo do programa */
int main()
{  
	setlocale (LC_ALL, "");  
	teste_heapsort();	
		
    return (0);
}
