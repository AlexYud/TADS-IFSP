/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: ordenaRegistrosM										|
|	Descrição: módulo responsável por ordenar os registros DAT pela idade	|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 17/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <locale.h>

/* Tipos pré-definidos */
typedef struct {
   	char   	nome [50+1];
   	int  	idade;
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
      	
      	while(atual > 0 && vet_reg[atual].idade < vet_reg[pai(atual)].idade) 
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
        while ( direito(atual) <= (i-1) && ( vetor[atual].idade > vetor[esquerdo(atual)].idade || vetor[atual].idade > vetor[direito(atual)].idade  ) ) {
            if ( vetor[esquerdo(atual)].idade < vetor[direito(atual)].idade ) 
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
        
        if ( esquerdo(atual) <= i-1 && vetor[atual].idade > vetor[esquerdo(atual)].idade ) {
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
		reg.idade = 0;
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
        
        // Lê idade
	    i=0;
	    do
	    {
	    	ch = fgetc(ArqCsv);
	   	 	aux_cod[i] = ch;
	   	 	i++;
	    }
	    while ( ch != ';'); 
        aux_cod[--i] = '\0';
        reg.idade = atoi(aux_cod);
	    
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
    //getch();
}

void consulta_dat_em_relatorio(void)
{
	FILE 				* ArqDat, *Relat;
	registro			reg;
	long int 			cont=0;
	
	system ("cls"); system ("mode 30, 4"); system ("color 03");

	TAMANHO_VETOR = findSize("FILAVACINA.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);

	ArqDat = fopen ("FILAVACINA.DAT", "rb+");
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
	fprintf (Relat, "    #         	         NomeCompleto                         Idade         CPF	  País       	      Estado                            Município                                            Logradouro                                  Nro         Complemento       			Bairro       			    CEP       		        E-mail       	              TelefoneCelular\n");
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
		reg.idade = 0;
		memset(reg.nome,     '\0', sizeof(reg.nome));
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
			fprintf (Relat,"\n%5i->[%-50s]\t[%-2i]\t[%-11s]\t[%-6s]\t[%-19s]\t[%-40s]\t[%-60s]\t[%4i]\t[%-20s]\t[%-40s]\t[%8i]\t[%-40s]\t[%-11s]", 
			(int)cont, reg.nome, reg.idade, reg.CPF, reg.pais, reg.estado, reg.municipio, reg.logradouro, reg.nro, reg.complemento, reg.bairro, reg.CEP, reg.email, reg.cel);	
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

void abastece_vetor (registro	* vet_reg)
{   
	int i=0;
   	FILE * ArqDat;
	ArqDat = fopen ("FILAVACINA.DAT", "rb+");
	if ( ArqDat==NULL )
	{	
		system ("cls");
		printf ("Erro ao abrir arquivo FILAVACINA.DAT para leitura");
		getch();
		exit(0);
	}
	//printf ("\nSucesso ao abrir arquivo MUNICIPES.DAT para leitura");
	
	while ( !feof(ArqDat) )
	{	
		// Lê um registro do arquivo MUNICIPES.DAT para o vetor (um de cada vez)
	    fread (&vet_reg[i], sizeof(vet_reg[i]), 1, ArqDat);
	    // Testa se deu erro de leitura
   	    if ( ferror(ArqDat) )
   	    {  
		   	system ("cls");
		   	printf ("Erro ao ler arquivo MUNICIPES.DAT no registro [%i]",i);
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

void envia_vet_ordenado_dat (registro	* vet_reg)
{
    long int i;
   	FILE * ArqDat;
	ArqDat = fopen ("FILAVACINA.DAT", "wb+");
	if ( ArqDat==NULL )
	{	system ("cls");
		printf ("Erro ao gerar arquivo FILAVACINA.DAT ordenado!");
		getch();
		exit(0);
	}
    for (i=0; i<qtd_registros; i++)
    {
    	fwrite (&vet_reg[i], sizeof(vet_reg[i]), 1, ArqDat);
    	if ( ferror(ArqDat) )
   	    {  system ("cls");
		   printf ("Erro ao gravar no arquivo FILAVACINA.DAT no registro %li!", i);
		   getch();
		   exit(0);	
		}
	}
	fclose(ArqDat);
	printf ("\n MUNICIPES.DAT ordenado com sucesso! \n FILAVACINA.DAT criado!");
	getch();
}

void teste_heapsort(void)
{
	FILE * ArqDat;
	registro		* vet_reg;

 	TAMANHO_VETOR = findSize("FILAVACINA.DAT");
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
	gera_dat ("MUNICIPES2.CSV", "FILAVACINA.DAT");
	setlocale (LC_ALL, "");  
	teste_heapsort();	
		
    return (0);
}
