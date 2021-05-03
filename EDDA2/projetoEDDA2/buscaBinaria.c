/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: buscaBinaria											|
|	Descrição: módulo responsável por buscar usuário no registro de médicos	|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 06/03/2021 														|
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

typedef struct
{
   	int    crm;
   	char   nome [50+1];	
}
login;

/* variável global */
int     TAMANHO_VETOR;

/* Funções */

login solicita_elemento_para_busca()
{   
	system("cls"); system ("mode 80,10"); system ("color 90");
	login vet_login;
	memset(vet_login.nome,     '\0', sizeof(vet_login.nome));
	vet_login.crm = 0;
	// Lê registro
	
	printf("\n 		USUÁRIO		: ");
	fflush(stdin); scanf("%[^\n]", &vet_login.nome);
	printf("\n 		CRM		: ");
	fflush(stdin); scanf("%i", &vet_login.crm);
	
	return vet_login;
}

long int findSize(char file_name[]) 
{ 
    FILE* fp = fopen(file_name, "r");   

    if (fp == NULL) { 
        system ("cls"); system ("mode 60,5"); system ("color 0c"); 
		printf ("\n\n	 ARQUIVO MEDICOSCREMESP.DAT INEXISTENTE!");
        return -1; 
    } 
    fseek(fp, 0L, SEEK_END); 
    
    long int res = ftell(fp); 
    
    fclose(fp); 
    return res; 
}

void mostra_codigos  (int qtd_registros, registro	* vet_reg)
{
    long int i;
    printf ("\n_______________________________________________________________________\n");
	for (i=0; i<qtd_registros; i++)
    {
       	printf ("%i;%s;%s;%s;%s;%s;%s;%s", 
	   	vet_reg[i].crm, vet_reg[i].nome, vet_reg[i].campC, vet_reg[i].campD, vet_reg[i].campE, vet_reg[i].campF, vet_reg[i].campG, vet_reg[i].campH);
	   	if (i<qtd_registros-1) printf ("\n");
    }
    printf ("\n_______________________________________________________________________\n");
}

int contaStr(int index, int index2, login  vet_login, registro * vet_reg) {
	
	while( vet_login.nome[index2] == vet_reg[index].nome[index2] )
	{
    	// Verifica se alguma das strings terminou.
    	// Se sim, sai do loop. Caso contrario, analisa o próximo carácter.
    	if( vet_login.nome[index2] == '\0' || vet_reg[index].nome[index2] == '\0' ) {
    		break;	
		}	
    	++index2;
	}
	
	return index2;
}

int comparaStr(int index, login  vet_login, registro * vet_reg) {
	int index2 = 0, qtdCLog;
	// Enquanto os caracteres forem iguais, corre os vectores.
	qtdCLog = strlen(vet_login.nome);
	
	index2 = contaStr(index, index2,vet_login, vet_reg);
	fflush(stdin);
	// Se ambos terminaram, as strings contidas são iguais.
	if( qtdCLog == index2 ) {
		return 0;
	} else {
		return -1;	
	}  	
}

int busca_binaria    (int qtd_reg, login  vet_login, registro * vet_reg) 
{        
  	int ini=0, fim=qtd_reg, meio, result;   
  	while (ini<=fim) {        
    	meio=(ini+fim)/2; 
    	
    	result = comparaStr(meio, vet_login, vet_reg);
    	
    	if(vet_reg[meio].crm == vet_login.crm && result == 0) {
			if (vet_reg[meio].campC[0] == 'A') {
				return meio;	
			} else {
				system ("cls"); system ("mode 50,5"); system ("color c0");
				printf("\n 		USUÁRIO INATIVO!");
				return -1;
			}		
		}   	        
    	if(vet_reg[meio].crm > vet_login.crm) {
    		
     		fim=meio-1;
		} else {
    		          
     		ini=meio+1;  
     	}
   	}  

	system ("cls"); system ("mode 50,5"); system ("color c0");
	printf("\n     	   MÉDICO E/OU CRM INVÁLIDO!");	    
   	return -1; /* só retorna -1 quando fez sucessivas divisões do vetor e NÃO ACHOU o que se busca */
}

void abastece_vetor (registro	* vet_reg)
{   
	int i=0;
   	FILE * ArqDat;
	ArqDat = fopen ("REGISTROS.DAT", "rb+");
	if ( ArqDat==NULL )
	{	
		system ("cls"); system ("mode 50,5"); system ("color 0c"); 
		printf ("\n	ARQUIVO MEDICOSCREMESP.DAT INEXISTENTE!");
		getch();
		exit(0);
	}
	
	
	while ( !feof(ArqDat) ) {	
		// Lê um registro do arquivo REGISTROS.DAT para o vetor (um de cada vez)
	    fread (&vet_reg[i], sizeof(vet_reg[i]), 1, ArqDat);
	    // Testa se deu erro de leitura
   	    if ( ferror(ArqDat) ) {  
		   	system ("cls");
		   	printf ("\n Erro ao ler arquivo REGISTROS.DAT no registro [%i]",i);
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

int qtd_reg (void) {
	
	long int qtd_registros;
	registro		* vet_reg;
	
	TAMANHO_VETOR = findSize("REGISTROS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registro);
    
	/* Tenta alocar um vetor com o tamanho do arquivo */   
    vet_reg = (registro *) malloc (qtd_registros * sizeof (registro)); 
    if (vet_reg == NULL)
    {
        printf ("\n 	malloc devolveu NULL!", 
		(qtd_registros * sizeof (registro)) );
        getch();
        exit (EXIT_FAILURE);
    }
	 
	return qtd_registros;
}

/* CORPO DO PROGRAMA */
int main()
{
   	registro   * vet_reg;
  	login       vet_login;
   	int posicao;
   	char resp;
   	long int qtd_registros;
   	
   	system ("cls"); setlocale (LC_ALL, "");  
   	op:  	
	TAMANHO_VETOR = findSize("REGISTROS.DAT");
	if (TAMANHO_VETOR == -1) {
		getch();
		exit(0);
	}
	qtd_registros = TAMANHO_VETOR/sizeof(registro);
    
	/* Tenta alocar um vetor com o tamanho do arquivo */   
    vet_reg = (registro *) malloc (qtd_registros * sizeof (registro)); 
    if (vet_reg == NULL)
    {
        printf ("\n 	malloc devolveu NULL!", 
		(qtd_registros * sizeof (registro)) );
        getch();
        exit (EXIT_FAILURE);
    } 
        
    abastece_vetor(vet_reg);                     
    vet_login = solicita_elemento_para_busca();   
        
    posicao = busca_binaria(qtd_registros, vet_login, vet_reg);
    if (posicao == -1) {
    	getch();
        goto op;
	}
	free(vet_reg);                                  
	system("adm");
    
    return 0;
}
