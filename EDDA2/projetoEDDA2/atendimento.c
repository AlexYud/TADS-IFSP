/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: Atendimento												|
|	Descrição: módulo responsável pelo menu de atendimento					|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 16/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Biblioteca */
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>

/* Funções */


/* ------------------------------- Constantes pr?-definidas --------------------------------- */
#define MAX       2  /* tamanho m?ximo do vetor est?tico */ 
#define INVALIDO -1

#define false    -1  
#define true      1

/* --------------------- Tipos de dados definidos pelo programador -------------------------- */

/* defini??o do tipo booleano */
typedef int 	bool;

/* defini??o do registro*/
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
registroM;

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
registroVac;

typedef struct
{
   	int		id;
   	int		idLote;
   	int		qtdFrascos;
   	char	dataFabr[10+1];
   	char	dataVenc[10+1];
}
registroLote;

typedef struct   
{         
   	/* campos do registro */ 
   	int			id_frasco;       
   	int       	id_lote;
   	int       	id_vacina; 
} 
REGISTRO;

typedef struct aux
{  
	REGISTRO 	reg;
	struct 		aux	* PROX; /* prox APONTA para o endere?o de mem?ria  */
}                           /* de um elemento com essa mesma estrutura */
ELEMENTO;

typedef ELEMENTO * PONT;  

typedef struct 
{
	PONT topo; /* topo APONTA para o endere?o do ELEMENTO do TOPO da PILHA */
} 
PILHA;

/* variáveis globais */
long int     TAMANHO_VETOR;
long int     qtd_registros;
PILHA pil; 

/* --------------------------- Prot?tipos das fun??es --------------------------------------- */
void inicializarPilha 	(PILHA* p);
int  tamanho 			(PILHA* p);
void exibirPilha 		(PILHA* p);
bool inserirElemPilha	(PILHA* p, REGISTRO reg);
bool excluirElemPilha	(PILHA* p, REGISTRO* reg); 
void reinicializarPilha (PILHA* p);

REGISTRO 	oqueInserir 	(char arq_dat[]);
void 		insereNaPilha 	(PILHA* p, char file_name[]);
void 		excluiDaPilha 	(PILHA* p);

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

/* ----------------------- Rotinas de gerenciamento da Pilha -------------------------------- */

/* 
Para inicializar uma pilha j? criada pelo usu?rio,  precisamos apenas acertar o valor do 
campo topo.
J? que o topo conter? o endere?o do elemento que est? no topo da pilha e apilha est? vazia,  
iniciaremos esse campo com valor NULL. 
*/
void inicializarPilha (PILHA* p)
{
  p->topo = NULL;
}

/* J? que n?o temos um campo com o n?mero de elementos na pilha, 
   precisaremos percorrer todos os elementos para contar quantos s?o.
*/
int tamanho (PILHA* p) 
{  
   	PONT end = p->topo;  
   	int tam = 0;
   	while (end != NULL) 
   	{  
      	tam++;
      	end = end->PROX;
   	}  
   	return tam;
}

/* Se topo est?  armazenando o endere?o NULL, significa que a pilha est? vazia. */
bool estaVazia(PILHA* p) 
{
   	if (p->topo == NULL) 
      	return true;  
   	return false;
}

/* Para exibir os elementos da estrutura precisaremos  percorrer os elementos
(iniciando pelo elemento do topo da pilha) e, por exemplo, imprimir suas chaves. */
void exibirPilha (PILHA* p) 
{  
   	PONT end = p->topo;  
   	system ("cls"); system ("mode 40, 60");
   	printf("\n Suporte:");  
   	printf("\n 	id - lote - frasco\n");
   	while (end != NULL) 
   	{
		printf("\n 	%i   %i    %i", end->reg.id_vacina, end->reg.id_lote, end->reg.id_frasco );  
		end = end->PROX;
   	}
   	printf("\n");
   	getch();
}

/* ------------------------------------------------------------------------------------------------ */

void consultaDat () {
	
	FILE 				* ArqDat;
	REGISTRO			reg;
	char 				arquivo_dat[14];
	int					cont=0;
	
	system ("mode 40, 60");
	//consulta
	
	printf("\n nome arquivo: ");
	scanf("%s", &arquivo_dat);
	
	ArqDat = fopen (arquivo_dat, "rb+");

	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo %s.DAT", arquivo_dat);
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {	
		// Limpa o registro 
		reg.id_frasco = 0;
		reg.id_lote = 0;
		reg.id_vacina = 0;
			
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
			printf ("\n [%2i][%8i][%2i]", 
			reg.id_vacina, reg.id_lote, reg.id_frasco);	
		} else {
			break;
		}
	
		if (feof(ArqDat)) break;
	}
    fclose(ArqDat);
    getch();
}

void geraDat (PILHA* p) {
	
	FILE 				* ArqDat;
	REGISTRO			reg;
	char 				arquivo_dat[14];
	int					cont=0;
	PONT end = p->topo; 
	
	printf("\n nome arquivo: ");
	scanf("%s", &arquivo_dat);
	
	ArqDat = fopen (arquivo_dat, "wb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("\n Erro ao criar arquivo %s", arquivo_dat);
		getch();
		exit(0);
	}
	
	while (end != NULL) 
   	{
		//printf("\n[%i-%i-%i-%i]", end->reg.chave, end->reg.id_vacina, end->reg.id_lote, end->reg.id_frasco );  
		if ( fwrite (&end->reg, sizeof(end->reg), 1, ArqDat) != 1 ) {
	   		printf ("\n Erro ao gravar em %s!\a\a\a", arquivo_dat);
		}
		end = end->PROX;
   	}
	
	fclose(ArqDat);
	printf("\n\n %s gerado!", arquivo_dat);
}

/* 
Inser??o de um elemento (push)
O usu?rio passa como par?metro um registro a ser inserido na pilha
O elemento ser? inserido no topo da pilha, ou  melhor, 
?acima? do elemento que est? no topo da  pilha.
O novo elemento ir? apontar para o elemento que estava no topo da pilha
*/
bool inserirElemPilha(PILHA* p, REGISTRO reg) 
{  
   	PONT novo  = (PONT) malloc(sizeof(ELEMENTO));  
   	novo->reg  = reg;
   	novo->PROX = p->topo;  
   	p->topo    = novo;  
   	return true;
}

/*
Exclus?o de um elemento (pop)
O usu?rio solicita a exclus?o do elemento do topo da pilha:
Se a pilha n?o estiver vazia, al?m de excluir esse elemento da pilha 
iremos copi?-lo para um local indicado pelo usu?rio.
*/
bool excluirElemPilha(PILHA* p, REGISTRO* reg) 
{  
   	if ( p->topo == NULL) 
      	return false;
   	*reg        = p->topo->reg;  
   	PONT apagar = p->topo;
   	p->topo     = apagar->PROX; 
   	free(apagar);
   	return true;
}

/* 
S? tem sentido, se a pilha foi inicializada alguma vez.
Para reinicializar a pilha, precisamos excluir todos os seus elementos 
e colocar NULL no campo topo 
*/
void reinicializarPilha (PILHA* p) 
{  
   	PONT apagar;
   	PONT posicao = p->topo;  
   	while (posicao != NULL) 
   	{
      	apagar  = posicao;  
      	posicao = posicao->PROX;  
      	free(apagar);
   	}
   	p->topo = NULL;
}
/*------------------*/
/* Fun??es de apoio */
/*------------------*/

void insereNaPilha (PILHA* p, char arq_dat[])
{
	REGISTRO			elem;
	REGISTRO 			r;
	FILE 				* ArqDat;
	long int 			cont=0;
	int op;
	
	system ("cls"); system ("mode 80, 50"); system ("color 03"); setlocale (LC_ALL, "");  

	TAMANHO_VETOR = findSize(arq_dat);
	qtd_registros = TAMANHO_VETOR/sizeof(r);

	ArqDat = fopen (arq_dat, "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo %s", arq_dat);
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {	
		// Limpa o registro 
		r.id_frasco = 0;
		r.id_lote = 0;
		r.id_vacina = 0;
		
		cont++;
		fread (&r, sizeof(r), 1, ArqDat);
   		
   		if ( !feof(ArqDat) ) {
   			printf ("\n [%2i][%8i][%2i]", 
			r.id_vacina, r.id_lote, r.id_frasco);	
			elem = r;
			inserirElemPilha(p, elem);	
		} else {
			break;
		}
				
		if (feof(ArqDat)) break;
	}
	fclose(ArqDat);
	getch();
	printf("\n\n Lote adicionado com sucesso!");
	getch();
}

void excluiDaPilha (PILHA* p)
{	REGISTRO regExcluido;
 	if ( excluirElemPilha(p, &regExcluido) == true )
	   	printf("[%i-%i-%i] excluído com sucesso", regExcluido.id_vacina, regExcluido.id_lote, regExcluido.id_frasco );  
	else
	   	printf ("\n Nao foi possivel excluir o registro.");
}

int get_size(char file_name[]) {
    
	FILE *file = fopen(file_name, "rb+");

    if(file == NULL){
    	return 0;
	}

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

void supDisp () {	
	
	if (get_size("SUPORTE_1.DAT") == 0) {
		printf("\n SUPORTE_1 vazio!");
		if (get_size("SUPORTE_2.DAT") == 0) {
			printf("\n SUPORTE_2 vazio!");
			if (get_size("SUPORTE_3.DAT") == 0) {
				printf("\n SUPORTE_3 vazio!");
				if (get_size("SUPORTE_4.DAT") == 0) {
					printf("\n SUPORTE_4 vazio!");
					if (get_size("SUPORTE_5.DAT") == 0) {
						system("cls"); system ("mode 70, 5"); system ("color c0");
						printf("\n\n		ATENÇÃO! NÃO HÁ VACINAS DISPONÍVEIS!");
						getch();
					} else {
						printf("\n SUPORTE_5 disponível!");
						getch();
						inicializarPilha(&pil);
						insereNaPilha (&pil, "SUPORTE_5.DAT");
						exibirPilha (&pil);
					}
				} else {
					printf("\n SUPORTE_4 disponível!");
					getch();
					inicializarPilha(&pil);
					insereNaPilha (&pil, "SUPORTE_4.DAT");
					exibirPilha (&pil);
				}
			} else {
				printf("\n SUPORTE_3 disponível!");
				getch();
				inicializarPilha(&pil);
				insereNaPilha (&pil, "SUPORTE_3.DAT");
				exibirPilha (&pil);
			}
		} else {
			printf("\n SUPORTE_2 disponível!");
			getch();
			inicializarPilha(&pil);
			insereNaPilha (&pil, "SUPORTE_2.DAT");
			exibirPilha (&pil);
		}
	} else {
		printf("\n SUPORTE_1 disponível!");
		getch();
		inicializarPilha(&pil);
		insereNaPilha (&pil, "SUPORTE_1.DAT");
		exibirPilha (&pil);
	}
}

registroVac encontraVac () {
	FILE 				* ArqDat;
	registroVac			reg;
	long int 			cont=0;

	TAMANHO_VETOR = findSize("VACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(registroVac);

	ArqDat = fopen ("VACINAS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo VACINAS.DAT");
		getch();
		exit(0);
	}
	
	while ( cont != 6 ) {	
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
			
		if (cont == 6) {
			return reg;
		}
	}
    fclose(ArqDat);
	
	return reg;
}

REGISTRO encontraLote () {
	FILE 				* ArqDat;
	REGISTRO			reg;
	long int cont=0;

	TAMANHO_VETOR = findSize("SUPORTE_1.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(REGISTRO);

	ArqDat = fopen ("SUPORTE_1.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo SUPORTE_1.DAT");
		getch();
		exit(0);
	}
	
	while ( !feof(ArqDat) ) {	
		// Limpa o registro 
		reg.id_frasco = 0;
		reg.id_lote = 0;
		reg.id_vacina = 0;
		
		cont++;
		fread (&reg, sizeof(reg), 1, ArqDat);
		
		return reg;
				
		if (feof(ArqDat)) break;
	}
    fclose(ArqDat);
	
	return reg;
}

void atende() {
	
	registroM			reg;
	REGISTRO			vet_reg;
	registroVac			vet_vac;
	FILE 				* filaVacDat;
	FILE				* VacDat;
	FILE 				* loteVacDat;
	FILE				* Relat;
	long int 			cont=0;
	
	system ("cls"); system ("mode 50, 20"); system ("color 72"); setlocale (LC_ALL, "");  
	
	vet_vac = encontraVac();
	vet_reg = encontraLote(); 
	 
	TAMANHO_VETOR = findSize("FILAVACINA.DAT");	
	qtd_registros = TAMANHO_VETOR/sizeof(registroM);
	filaVacDat = fopen ("FILAVACINA.DAT", "rb+");
	if ( filaVacDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo FILAVACINA.DAT");
		getch();
		exit(0);
	}
	
	while ( !feof(filaVacDat) ) {	
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
		fread (&reg, sizeof(reg), 1, filaVacDat);
			
   		if ( !feof(filaVacDat) ) {
   			system("cls");
   			printf("\n 		  ATENDIMENTO");
   			printf("\n");
   			printf("\n__________________________________________________");
			printf("\n\n NOME: %-25s [%i/%i]", reg.nome, cont, qtd_registros);	
			printf("\n\n\n CPF : %s", reg.CPF);
			printf("\n\n\n %-20s [Lote: %i/Frasco:%2i]", vet_vac.nome, vet_reg.id_lote, vet_reg.id_frasco+cont-1);
			printf("\n\n\n Primeira dose: 19/03/2021");
			printf("\n\n\n Segunda dose: 19/04/2021");
			getch();
			Relat = fopen ("RELAT_ATENDIMENTO.TXT", "wt");
			if ( Relat==NULL ) {
				system ("cls");
				printf ("\n Erro ao gerar arquivo RELAT_ATENDIMENTO.TXT");
				getch();
				exit(0);
			}
			fprintf(Relat,"\n		  ATENDIMENTO");
			fprintf(Relat,"\n");
   			fprintf(Relat,"\n__________________________________________________");
			fprintf(Relat,"\n\n NOME: %-25s [%i/%i]", reg.nome, cont, qtd_registros);	
			fprintf(Relat,"\n\n\n CPF : %s", reg.CPF);
			fprintf(Relat,"\n\n\n %-20s [Lote: %i/Frasco:%2i]", vet_vac.nome, vet_reg.id_lote, vet_reg.id_frasco+cont-1);
			fprintf(Relat,"\n\n\n Primeira dose: 19/03/2021");
			fprintf(Relat,"\n\n\n Segunda dose: 19/04/2021"); 
			fclose(Relat);
    		system("notepad RELAT_ATENDIMENTO.TXT");
			
		} else {
			break;
		}
				
		if (feof(filaVacDat)) break;
	}
    fclose(filaVacDat);
    getch();
	
}

char menu (void)
{   char op;
	do
	{	system ("cls"); system ("mode 48, 20"); system ("color A0");
		printf ("\n		  					 					   ");
		printf ("\n        	  ATENDIMENTO         ");
		printf ("\n		  					 					   ");
		printf ("\n________________________________________________");
		printf ("\n		  					 					   ");
		printf ("\n    	  1. Verifica suporte disponível");
		printf ("\n    	  2. Ordena munícipes por idade");
		printf ("\n    	  3. ATENDE");
		printf ("\n    	  0. RETORNAR							   ");
		printf ("\n		  					 					   ");
		printf ("\n   	 Opção desejada: "); fflush(stdin); op = getche(); 
		if (  (op <'0' || op >'3')  ) {  	
			system ("cls");
			printf ("\n OPÇÃO INVÁLIDA!");
			getch();
		}
	} while (  (op <'0' || op >'3')  );
	return (op);
}

void analisa (char op)
{
	switch (op) { 
	   	case '1': supDisp();							break;
	   	case '2': system("ordenaRegistrosM");			break;
	   	case '3': atende();								break;
	   	case '0': exit(0);			
	}
}

/* Corpo do programa */
int main(void) {
	
	char opc;
    system("cls"); setlocale (LC_ALL, "");  
    do
    {
    	opc = menu();
    	analisa (opc);
	}
	while (opc!='S');
	
	
	return 0;
}
