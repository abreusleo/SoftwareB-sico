/* JOÃO MARCELLO BESSA RODRIGUES 1720539 3WA */
/*LEONARDO DOS SANTOS ABREU 1720565 3WB */


#include "cria_func.h"
#include <stdio.h>
#include <stdlib.h>


void libera_func(void *func) {
	free(func);	
}

bool check_ptr(int i)
{
	return params[i].tipo_val == PTR_PAR;
}

bool check_param(int i)
{
	return params[i].orig_val == PARAM;
}

void* cria_func (void* f, DescParam params[], int n) {
	
	unsigned char codigo = (unsigned char *)malloc(1024); //WIP
	
	unsigned char alinhaPilha[4] = {0x55, 0x48, 0x89, 0xe5}; //alinhamento da pilha dando push em %rbp e depois movendo %rsp para %rbp
	unsigned char leave[2] = {0xc9, 0xc3}; //array contendo o leave e ret
	int i, cont;
	

	for (i = 0; i < 4; i++) 
		codigo[i] = alinhaPilha[i]; //inicializa o array com o alinhamento da pilha



	/*
	O programa deve ser dividido de acordo com a quantidade de parâmetros(n) passados,
	*/
	switch(n)
	{
		case(2):
			if(!check_param(0) && check_param(1)) //Primeiro parametro Amarrado e o segundo não Amarrado
			{
				if(check_ptr(1))
				{
					codigo[i] = 0x48;
					i++;
				}

				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfe;
				i++;
			}
		break;

		case(3):
			if(check_param(0) && !check_param(1) && check_param(2)) //Primeiro caso
			{
				if(check_ptr(2))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xf2;
				i++;
			}

			else if(!check_param(0) && check_param(1) && !check_param(2))
			{
				if(check_ptr(2))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfe;
				i++;
			}

			else if(!check_param(0) && !check_param(1) && check_param(2))
			{
				if(check_ptr(2))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfa;
				i++;
			}

			else if(!check_param(0) && check_param(1) && check_param(2))
			{
				if(check_ptr(2))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xf2;
				i++;

				if(check_ptr(1))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfe;
				i++;
			}
		break;
		
		default:
			printf("Aconteceu algo inesperado.\n");
		break;
	}

	

	for (cont = 0; cont < 2; cont++, i++)
		codigo[i] = leave[cont]; //desfazendo o registro de ativação (leave)
}
