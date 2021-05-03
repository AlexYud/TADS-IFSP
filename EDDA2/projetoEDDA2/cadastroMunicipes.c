/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: cadastroMunicipes											|
|	Descrição: módulo responsável pelo cadastro de novos cidadãos				|
|	Autor: Alexandre Yudi Inokawa de Oliveira									|
|	Prontuário: SP3046923														|
|	Data: 17/03/2021 															|
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
	
	TAMANHO_VETOR = findSize("MUNICIPES.DAT");
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
	
	// Lê registro
	printf("\n CADASTRO DE CIDADÃO: \n");
	printf("\n NOME	: ");
	fflush(stdin); scanf("%[^\n]", &reg.nome);
	printf("\n DATANASC	: ");
	fflush(stdin); scanf("%[^\n]", &reg.dataNascimento);
	printf("\n CPF		: ");
	fflush(stdin); scanf("%[^\n]", &reg.CPF);
	printf("\n PAÍS		: ");
	fflush(stdin); scanf("%i", &reg.pais);
	printf("\n ESTADO	: ");
	fflush(stdin); scanf("%[^\n]", &reg.estado);
	printf("\n MUNICÍPIO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.municipio);
	printf("\n LOGRADOURO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.logradouro);
	printf("\n NÚMERO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.nro);
	printf("\n COMPLEMENTO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.complemento);
	printf("\n BAIRRO  : ");
	fflush(stdin); scanf("%[^\n]", &reg.bairro);
	printf("\n CEP  : ");
	fflush(stdin); scanf("%[^\n]", &reg.CEP);
	printf("\n EMAIL  : ");
	fflush(stdin); scanf("%[^\n]", &reg.email);
	printf("\n CELULAR  : ");
	fflush(stdin); scanf("%[^\n]", &reg.cel);
	
	op: ;
	system("cls");  system ("mode 80, 10");
	printf("\n Deseja cadastrar [S/N]: ");
	printf ("\n\n [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%i] [%s] [%s] [%i] [%s] [%s]", reg.nome, reg.dataNascimento, reg.CPF, reg.pais, reg.estado, reg.municipio, reg.logradouro, reg.nro, reg.complemento, reg.bairro, reg.CEP, reg.email, reg.cel);
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
	printf("\n\n Cidadão cadastrado com sucesso!");
	getch();
}

/* Corpo Programa */
int main(void) {
	
	system ("cls"); system ("mode 60, 20"); system ("color 03"); setlocale (LC_ALL, ""); 
	cadastrar("MUNICIPES.DAT");

	return 0;
}
