/* bibliotecas */
#include <stdio.h>
#define N 4

typedef struct
{
	char name [20];
	int eng, math, phys;
	float med;
}student;

/* variáveis */
float med (eng, math, phys) {
	int add = eng + math + phys;
	float med = add / 3;
	return med;
}
student data [N] = 
{
	{"Evandro", 82, 72, 58 },
	{"Thomas", 77, 82, 79 },
	{"Sabrina", 52, 62, 39 },
	{"Melinda", 61, 82, 88 }
};

/* corpo do programa */
int main() {
	int i;
	for (i=0; i<N; i++) {
		printf("%7s: Eng = %3d Math =%3d Phys = %3d Media = %3.0f\n", data[i].name, data[i].eng, data[i].math, data[i].phys, med(data[i].eng, data[i].math, data[i].phys));
	}
	
	return 0;
}
