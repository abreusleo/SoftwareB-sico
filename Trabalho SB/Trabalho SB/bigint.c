//JOÃO MARCELLO BESSA RODRIGUES - 1720539 - 3WA
//LEONARDO DOS SANTOS ABREU - 1720565 - 3WB

#include <stdio.h>
#include "bigint.h"



/* Auxiliares */
void dump(void *p, int n) {
	unsigned char *p1 = p;
	while (n--) {
		printf("%p - %02x\n", p1, *p1);
		p1++;
	}
	printf("\n");
}

/* Principais */


/*-----------------------SUA BIG_VAL----------------------
(não consegui fazer o teste com ela)*/

void big_val(BigInt res, long val) {

	unsigned char *p = &val;
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
