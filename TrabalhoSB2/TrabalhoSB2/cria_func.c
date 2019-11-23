/* JOÃO MARCELLO BESSA RODRIGUES 1720539 3WA */
/*LEONARDO DOS SANTOS ABREU 1720565 3WB */


#include "cria_func.h"
#include <stdio.h>
#include <stdlib.h>


void libera_func(void *func) {
	free(func);	
}


void* cria_func (void* f, DescParam params[], int n) {
	
	unsigned char codigo = (unsigned char *)malloc(1024); //WIP
	
	unsigned char alinhaPilha[4] = {0x55, 0x48, 0x89, 0xe5}; //alinhamento da pilha dando push em %rbp e depois movendo %rsp para %rbp
	unsigned char leave[2] = {0xc9, 0xc3}; //array contendo o leave e ret
	int i, cont;
	

	for (i = 0; i < 4; i++) 
		codigo[i] = alinhaPilha[i]; //inicializa o array com o alinhamento da pilha




	for (cont = 0; cont < 2; cont++, i++)
		codigo[i] = leave[cont]; //desfazendo o registro de ativação (leave)
}
