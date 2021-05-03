/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|	Nome do módulo: pilha													|
|	Descrição: módulo responsável pela organização dos suportes				|
|	Autor: Alexandre Yudi Inokawa de Oliveira								|
|	Prontuário: SP3046923													|
|	Data: 14/03/2021 														|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* --------------------------------------- Bibliotecas -------------------------------------- */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>

/* ------------------------------- Constantes pr?-definidas --------------------------------- */
#define MAX       2  /* tamanho m?ximo do vetor est?tico */ 
#define INVALIDO -1

#define false    -1  
#define true      1

/* --------------------- Tipos de dados definidos pelo programador -------------------------- */

/* defini??o do tipo booleano */
typedef int 	bool;

/* defini??o do registro*/
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

/* --------------------------- Prot?tipos das fun??es --------------------------------------- */
void inicializarPilha 	(PILHA* p);
int  tamanho 			(PILHA* p);
void exibirPilha 		(PILHA* p);
bool inserirElemPilha	(PILHA* p, REGISTRO reg);
bool excluirElemPilha	(PILHA* p, REGISTRO* reg); 
void reinicializarPilha (PILHA* p);

REGISTRO 	oqueInserir 	(void);
void 		insereNaPilha 	(PILHA* p);
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
   	printf("Suporte:");  
   	printf("\n 	id - lote - frasco\n");
   	while (end != NULL) 
   	{
		printf("\n 	%i   %i    %i", end->reg.id_vacina, end->reg.id_lote, end->reg.id_frasco );  
		end = end->PROX;
   	}
   	printf("\n");
}

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
REGISTRO oqueInserir ()
{	REGISTRO r;
	registroLote reg;
	FILE 				* ArqDat;
	long int 			cont=0;
	int op;
	
	system ("cls"); system ("mode 80, 20"); system ("color 03"); setlocale (LC_ALL, "");  

	TAMANHO_VETOR = findSize("LOTESVACINAS.DAT");
	qtd_registros = TAMANHO_VETOR/sizeof(reg);

	ArqDat = fopen ("LOTESVACINAS.DAT", "rb+");
	if ( ArqDat==NULL )
	{
		system ("cls");
		printf ("Erro ao ler arquivo LOTESVACINAS.DAT");
		getch();
		exit(0);
	}
	
	printf ("\n  id  id_vacina  id_lote   Qtd_frascos   DataFabr        DataVenc");
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
			printf ("\n\n [%2i]   [%2i]   [%8i]     [%2i]     [%-10s]    [%-10s]", 
			(int)cont, reg.id, reg.idLote, reg.qtdFrascos, reg.dataFabr, reg.dataVenc);	
		} else {
			break;
		}
				
		if (feof(ArqDat)) break;
	}
	fclose(ArqDat);
	
	printf("\n\n Qual registro deseja alocar? [id]: ");
	printf("\n\n ");
	fflush(stdin); scanf("%d", &op);
	switch (op){
		case 1:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 1 ) {

   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} else {
					break;
				}
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
		
		case 2:
			//printf ("\n dentro do switch");
			cont=0;
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
				printf("\n cont %i", cont);
				fread (&reg, sizeof(reg), 1, ArqDat);
   		
   				if ( !feof(ArqDat) && cont == 2 ) {
   					
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
		
		case 3:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 3 ) {
   					
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
			
		case 4:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 4 ) {
   					
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
			
		case 5:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 5 ) {
   					
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
			
		case 6:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 6 ) {
   				
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
			
		case 7:
			//printf ("\n dentro do switch");
			cont=0;
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
   		
   				if ( !feof(ArqDat) && cont == 7 ) {
   					r.id_vacina = reg.id;
   					r.id_lote = reg.idLote;
   					r.id_frasco = reg.qtdFrascos;
   				
   					//printf("\n switch chave - %i frasco - %i lote - %i vacina - %i \n", r.chave, r.id_frasco, r.id_lote, r.id_vacina);
					return r;	
				} 
				
				if (feof(ArqDat)) break;
			}
			fclose(ArqDat);
			
			break;
	}
		
    getch();
	
	return r;
}

void insereNaPilha (PILHA* p)
{
	REGISTRO	elem;
	elem  = oqueInserir();
	//printf("\n pilha chave - %i frasco - %i lote - %i vacina - %i ", elem.chave, elem.id_frasco, elem.id_lote, elem.id_vacina);
	//int qtdfrasco = elem.id_frasco;
	//elem.id_frasco = 1;
	while (elem.id_frasco > 0) {
		
		//printf("\n frasco %i ", elem.id_frasco);
		inserirElemPilha(p, elem);
		//elem.chave--;
		elem.id_frasco--;
	}
	printf("\n Lote adicionado com sucesso!");
}

void excluiDaPilha (PILHA* p)
{	REGISTRO regExcluido;
 	if ( excluirElemPilha(p, &regExcluido) == true )
	   	printf("[%i-%i-%i] excluído com sucesso", regExcluido.id_vacina, regExcluido.id_lote, regExcluido.id_frasco );  
	else
	   	printf ("\n Nao foi possivel excluir o registro.");
}

/* ---------------------------------- CORPO DO PROGRAMA ------------------------------------ */
int main ()
{
   PILHA pil; 
   int *ant;
   char opc;
   do
   {    system ("color 80"); setlocale (LC_ALL, ""); system ("mode 40, 20");
   		system ("cls");
   		printf ("\n      		SUPORTES    ");
   		printf ("\n --------------------------------------");
   		printf ("\n   1. Inicializar suporte");
   		printf ("\n   2. Exibir quantidade frascos");
   		printf ("\n   3. Exibir suporte");
   		printf ("\n   4. Verificar se o suporte está vazio");
   		printf ("\n   5. Inserir vac no suporte");
   		printf ("\n   6. Excluir vac do suporte");
   		printf ("\n   7. Reinicializa o suporte");
   		printf ("\n   8. Gera Dat");
   		printf ("\n   9. Consulta Dat");
   		printf ("\n   0. RETORNAR");
   		printf ("\n --------------------------------------");
   		printf ("\n    Escolha: "); fflush (stdin); opc = getche();
   		
		switch (opc)
   	    {
   	    	case '1': inicializarPilha(&pil); 								break;
   	    	case '2': printf("\n\n Tamanho da Pilha = %i", tamanho(&pil) ); break;								
			case '3': exibirPilha (&pil);									break;			
   	    	case '4': 	if ( estaVazia (&pil) == true ) 
			        		printf ("\n\n SUPORTE VAZIO");	
					 	else printf ("\n\n SUPORTE CHEIO");		            break;
   	    	case '5': insereNaPilha (&pil);									break;
   	    	case '6': excluiDaPilha (&pil);									break;
   	    	case '7': reinicializarPilha (&pil);							break;
   	    	case '8': geraDat(&pil);										break;
   	    	case '9': consultaDat();										break;
   	    	case '0': exit(0);						
		}

		printf ("\n\nNovo teste? [n/N = NEGATIVO]"); fflush (stdin); opc = getche();
   }
   while ( opc != 'n' && opc != 'N');
   return 0;
}
