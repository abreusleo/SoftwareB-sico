//JOÃO MARCELLO BESSA RODRIGUES - 1720539 - 3WA
//LEONARDO DOS SANTOS ABREU - XXXXXXXX - 3WB

#include "bigint.h"
#include <stdio.h>


/* Auxiliares */


/* Principais */

void big_val(BigInt res, long val) {

	/* p recebe o endereço do long val e percorre os bytes copiando o valor do mesmo para o BigInt*/
	unsigned int *p = (unsigned int *)&val;
	int n = 0;

	while (n < 8) { 
		res[n] = *p;
		n++;
		p++;
	}
	for (; n < 16; n++) 
		res[n] = 0;
	return;
}

void big_sum(BigInt res, BigInt a, BigInt b) {
	unsigned int soma, vaiUm = 0;
	int i;

	for (i = 0; i < (NUM_BITS/8); i++) {
		soma = a[i] + b[i] + vaiUm;
		if (soma > 0xFF)
			vaiUm = soma >> 8;
		else
			vaiUm = 0;
		res[i] = soma;
	}
}

void big_comp2(BigInt res, BigInt a) {
	int i;
	BigInt soma_1;

	for (i = 0; i < (NUM_BITS/8); i++) {
		res[i] = ~a[i];
	}

	big_val(soma_1, 1);
	big_sum(res, res, soma_1);

}