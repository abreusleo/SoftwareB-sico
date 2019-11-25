/* JOÃO MARCELLO BESSA RODRIGUES 1720539 3WA */
/*LEONARDO DOS SANTOS ABREU 1720565 3WB */


#include "cria_func.h"
#include <stdio.h>
#include <stdlib.h>


void libera_func(void *func) 
{
	free(func);	
}

int check_ptr(int i, DescParam * params)
{
	return params[i].tipo_val == PTR_PAR;
}

int check_int(int i, DescParam * params)
{	
	return params[i].tipo_val == INT_PAR;
}

int check_fix(int i, DescParam * params)
{	
	return params[i].orig_val == FIX;
}

int check_ind(int i, DescParam * params)
{
	return params[i].orig_val == IND;
}

int check_param(int i, DescParam * params)
{
	return params[i].orig_val == PARAM;
}

void* cria_func (void* f, DescParam params[], int n) 
{
	
	unsigned char* codigo = (unsigned char *)malloc(1024); //WIP
	
	unsigned char alinhaPilha[4] = {0x55, 0x48, 0x89, 0xe5}; //alinhamento da pilha dando push em %rbp e depois movendo %rsp para %rbp
	unsigned char leave[2] = {0xc9, 0xc3}; //array contendo o leave e ret
	unsigned char instrucoes[5] = {0x48, 0x89, 0xfe, 0xfa, 0xf2}; // Instrucoes utilizadas
	unsigned char ajudante[] = {0xb9, 0xba, 0xbb};
	unsigned char ajudanteMov[] = {0x39, 0x32, 0x13};
	unsigned char registradores[3] = {0xbf, 0xba, 0xbe}; // EDI, EDX, ESI
	unsigned long ptr = (unsigned long) f, var_ptr, ptr_par;
	int i, cont, byteCont, supp;

	for (i = 0; i < 4; i++) 
		codigo[i] = alinhaPilha[i]; //inicializa o array com o alinhamento da pilha

	/*
	O programa deve ser dividido de acordo com a quantidade de parâmetros(n) passados,
	*/
	switch(n)
	{
		case(2):
			if(!check_param(0, params) && check_param(1, params)) //Primeiro parametro Amarrado e o segundo não Amarrado
			{
				if(check_ptr(1, params))
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
			if(check_param(0, params) && !check_param(1, params) && check_param(2, params)) //Primeiro caso
			{
				if(check_ptr(2, params))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xf2;
				i++;
			}

			else if(!check_param(0, params) && check_param(1, params) && !check_param(2, params))
			{
				if(check_ptr(2, params))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfe;
				i++;
			}

			else if(!check_param(0, params) && !check_param(1, params) && check_param(2, params))
			{
				if(check_ptr(2, params))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xfa;
				i++;
			}

			else if(!check_param(0, params) && check_param(1, params) && check_param(2, params))
			{
				if(check_ptr(2, params))
				{
					codigo[i] = 0x48;
					i++;
				}
				codigo[i] = 0x89;
				i++;
				codigo[i] = 0xf2;
				i++;

				if(check_ptr(1, params))
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
	
	while(supp < n) //seliganessa
	{
		if(check_fix(supp, params))
		{
			if(check_int(supp, params))
			{
				codigo[i] = registradores[supp];
				i++;

				for(byteCont = 0; byteCont <= 24; byteCont = byteCont + 8)
				{
					codigo[i] = (params[supp].valor.v_int >> byteCont) & 0xff;
					i++;
				}
			}

			else if(check_ptr(supp, params))
			{
				codigo[i] = 0x49;
				i++;
				codigo[i] = ajudante[supp];
				i++;

				ptr_par = (unsigned long) params[supp].valor.v_ptr;
				
				for(byteCont = 0; byteCont <= 56; byteCont = byteCont + 8)
				{
					codigo[i] = (ptr_par >> byteCont) & 0xff;
					i++;
				}
				
			}

		}

		if(check_ind(supp, params))
		{
			if(check_int(supp, params))
			{
				codigo[i] = 0x49;
				i++;
				codigo[i] = ajudante[supp];
				i++;

				var_ptr  = (unsigned long) params[supp].valor.v_ptr;

				for(byteCont = 0; byteCont <= 56; byteCont = byteCont + 8)
				{
					codigo[i] = (var_ptr  >> byteCont) & 0xff;
					i++;
				}
				
				codigo[i] = 0x41;
				i++;
				codigo[i] = 0x8b;
				i++;
				codigo[i] = ajudanteMov[supp];
				i++;
			}

			if(check_ptr(supp, params))
			{
				codigo[i] = 0x49;
				i++;
				codigo[i] = ajudante[supp];
				i++;

				ptr_par = (unsigned long) params[supp].valor.v_ptr;

				for(byteCont = 0; byteCont <= 56; byteCont = byteCont + 8)
				{
					codigo[i] = (ptr_par >> byteCont) & 0xff;
					i++;
				}

				codigo[i] = 0x49;
				i++;
				codigo[i] = 0x8b;
				i++;
				codigo[i] = ajudanteMov[supp];
				i++;

			}
		}

		supp++;
	}

	for (cont = 0; cont < 2; cont++, i++)
	{
		codigo[i] = leave[cont]; //desfazendo o registro de ativação (leave)
	}
	
	return codigo;
}
