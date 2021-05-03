/* bibliotecas */
#include <stdio.h>
#define N 4

typedef struct endereco
{
	char rua[20];
	int num;
	char cidade[20];
	int cep;
}endereco;

typedef struct
{
	char name [20];
	int eng, math, phys;
	struct endereco endereco;
}student;

/* variáveis */

student data [N] = 
{
	{"Evandro", 82, 72, 58, {"Vinte e Tres", 255, "SP", 43310201} },
	{"Thomas", 77, 82, 79, {"Praca Coronel", 256, "SP", 43310202} },
	{"Sabrina", 52, 62, 39, {"Fernando Prestes", 257, "SP", 43310203} },
	{"Melinda", 61, 82, 88, {"ABC", 258, "SP", 43310204} }
};

/* corpo do programa */
int main() {
	int i;
	for (i=0; i<N; i++) {
		printf("%7s: Eng = %3d Math =%3d Phys = %3d\n", data[i].name, data[i].eng, data[i].math, data[i].phys );
		printf("Rua = %15s num = %4d cidade = %2s CEP = %8d\n", data[i].endereco.rua, data[i].endereco.num, data[i].endereco.cidade, data[i].endereco.cep );
	}
	
	return 0;
}
