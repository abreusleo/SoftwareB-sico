//JO�O MARCELLO BESSA RODRIGUES - 1720539 - 3WA
//LEONARDO DOS SANTOS ABREU - 1720565 - 3WB

#include <stdio.h>
#include "bigint.h"


/* Auxiliares */
void dump(void *p, int n) {
	unsigned char *p1 = (unsigned char *)p;
	while (n--) {
		printf("%p - %02x\n", p1, *p1);
		p1++;
	}
	printf("\n");
}

void big_copy(BigInt res, BigInt a) {
	int i;

	for (i = 0; i < NUM_BITS/8; i++)
		res[i] = a[i];
	return;
}

/* Principais */


/*-----------------------SUA BIG_VAL----------------------
(n�o consegui fazer o teste com ela)*/

void big_val(BigInt res, long val) {

	unsigned char *p = (unsigned char *)&val;
	int n = 0;

	while (n < 8) { 
		res[n] = *p;
		n++;
		p++;
	} 

	while (n < NUM_BITS / 8) {
		res[n] = 0;
		n++;
	}
	return;
}


void big_sum(BigInt res, BigInt a, BigInt b) {
	unsigned char soma, vaiUm = 0;
	int i;

	for (i = 0; i < (NUM_BITS/8); i++) {
		soma = a[i] + b[i] + vaiUm;
		if (soma > 0xFF)
			vaiUm = soma >> 8;
		else
			vaiUm = 0;

		res[i] = soma;
	}

	return;
}

void big_comp2(BigInt res, BigInt a) {
	int i;
	BigInt soma_1;

	for (i = 0; i < (NUM_BITS/8); i++) {
		res[i] = ~a[i];
	}

	big_val(soma_1, 1);
	big_sum(res, res, soma_1);

	return;
}

void big_sub(BigInt res, BigInt a, BigInt b) {
	BigInt neg;   /* neg = -b -> complemento a 2 */

	big_comp2(neg, b);
	big_sum(res, a, neg);

	return;
}

void big_shl(BigInt res, BigInt a, int n)
{
	int i = 0;
	int shifter = 0;

	BigInt temp;
	
	//Usei de exemplo um c�digo, ele chamou isso de subshift(Fiquei meio na duvida, ve se vc entende)
	if(n % 8 != 0)
	{
		//Se n n�o for multiplo de 8, shifta pra esquerda n%8 e depois ajusta o n
		for(i = 0; i < NUM_BITS/8; i++)
		{
			temp[i] = (a[i] << n%8) + shifter;
			shifter = a[i] >> (8-(n%8));
		}
		n = n - (n%8);
	}
	else
	{
		big_copy(temp, a);
	}

	//N � multiplo de 8 agora
	for(i = 0 ; i < NUM_BITS/8; i++)
	{
		if(i - (n/8) >= 0)
		{
			res[i] = temp[i - (n/8)];
		}
		else
		{
			res[i] = 0;
		}
	}
	

	return;
}