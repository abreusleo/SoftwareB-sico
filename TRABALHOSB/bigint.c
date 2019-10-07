//JOÃO MARCELLO BESSA RODRIGUES - 1720539 - 3WA
//LEONARDO DOS SANTOS ABREU - 1720565 - 3WB

#include <stdio.h>
#include "bigint.h"


/* Auxiliares */
void dump(void *p, int n) {
	unsigned char *p1 = (unsigned char *)p;
	while (n--) {
		printf("%p - %02x\n", p1, *p1); /*Printa o endereco de memoria junto com um byte*/
		p1++;
	}
	printf("\n");
}

void big_copy(BigInt res, BigInt a) {
	int i;

	for (i = 0; i < NUM_BITS/8; i++)
		res[i] = a[i]; /*Copia o BigInt a bit a bit*/
	return;
}

/* Principais */

void big_val(BigInt res, long val) {

	unsigned char *p = (unsigned char *)&val;
	int n = 0;

	while (n < 8) { 
		res[n] = *p; /*preenchimento de bits*/
		n++;
		p++;
	} 

	while (n < NUM_BITS / 8) {
		res[n] = 0;	/*preenchimento de bytes*/
		n++;
	}
	return;
}


void big_sum(BigInt res, BigInt a, BigInt b) {
	unsigned char soma, vaiUm = 0;
	int i;

	for (i = 0; i < (NUM_BITS/8); i++) {
		soma = a[i] + b[i] + vaiUm;	/*O vaiUm funciona de maneira semelhante a soma de numeros decimais*/
		if (soma > 0xFF)		
			vaiUm = soma >> 8;	/*Atribuicao do valor de vaiUm, para o proximo loop*/
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
		res[i] = ~a[i];			/*Inverte os bits do numero*/
	}

	big_val(soma_1, 1);
	big_sum(res, res, soma_1);		/*Soma um no bit menos significativo para terminar a troca de sinal*/

	return;
}

void big_sub(BigInt res, BigInt a, BigInt b) {
	BigInt neg;

	big_comp2(neg, b);	/* neg = (-b) */
	big_sum(res, a, neg);	/* a + (-b) = a - b */

	return;
}

void big_shl(BigInt res, BigInt a, int n)
{
	int i = 0;
	int shifter = 0;

	BigInt temp;
	
	if(n % 8 != 0)
	{
		/* Se n não for multiplo de 8, shifta pra esquerda n%8 e depois ajusta o n */
		for(i = 0; i < NUM_BITS/8; i++)
		{
			temp[i] = (a[i] << n%8) + shifter;	/* O shifter funciona de maneira parecida com o vaiUm da soma */
			shifter = a[i] >> (8-(n%8));
		}
		n = n - (n%8);
	}
	else
	{
		big_copy(temp, a);
	}

	/* n é multiplo de 8 agora */
	for(i = 0 ; i < NUM_BITS/8; i++)		/*Essa parte do shift funciona para bytes completos*/
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

void big_shr(BigInt res, BigInt a, int n) {
	int i, aux = n % 8, shifter = 0;
	BigInt temp;

	if (aux != 0)
		/* Shift bit a bit */
		for(i = NUM_BITS / 8 - 1; i >= 0; i--) {	
			temp[i] = a[i];
			temp[i] = temp[i] >> aux;		/* Serve para preencher os bits com zeros */
			temp[i] |= shifter;
			shifter = a[i] << (8 - aux);
		}
	/* Caso n seja multiplo de 8 utiliza-se um auxiliar para shiftar os bytes */
	else
		big_copy(temp, a);		
	/* Shift de byte em byte */
	for (i = 0; i < NUM_BITS / 8; i++) {	
		if (i + (n / 8) < NUM_BITS / 8)
			res[i] = temp[i + (n / 8)];
		else
			res[i] = 0;
	}
	return;
}

void big_sar(BigInt res, BigInt a, int n) {
	int i, aux = n % 8, shifter = 0, byteFF;
	BigInt temp;

	if (aux != 0) {
		for(i = NUM_BITS / 8 - 1; i >= 0; i--) {
		    /* Se bitMaisSignificativo = 0, o shift funciona da memsa maneira que o logico */
		    if(a[NUM_BITS/8 - 1] >> 7 == 0)	
		    {
    			temp[i] = a[i];
    			temp[i] = temp[i] >> aux;
    			temp[i] |= shifter;
    			shifter = a[i] << (8 - aux);
		    } 
		    /* Caso contrario o auxiliar nao eh necessario, por isso completara com 1 */
		    else				
		    {
		        temp[i] = a[i];
    			temp[i] |= shifter;
    			shifter = a[i] << (8 - aux); 
		    }
		}
	}
	else
		big_copy(temp, a);

	/* ByteFF sempre será FF qnd bitMaisSignificativo = 1 */
	if (a[NUM_BITS/8 - 1] >> 7 != 0)
		byteFF = (-a[NUM_BITS/8 - 1] >> 7) + 1;		
	
	/* Caso contrário bitMaisSignificativo = 0*/
	else
		byteFF = a[NUM_BITS/8 - 1] >> 7;		

	/* Shifta os bytes de acordo com o valor byteFF */
	for (i = 0; i <= NUM_BITS / 8; i++) {			
		if (i + (n / 8) < NUM_BITS / 8)
			res[i] = temp[i + (n / 8)];
		else
			res[i] = byteFF;
	}
	return;
}

void big_mul(BigInt res, BigInt a, BigInt b) {

    unsigned char ehImpar = 0x1;
    BigInt num1, num2;
    int i;
    /* Cria 2 valores auxiliares para não alterar os valores originais de a e b */
    big_copy(num1, a);
    big_copy(num2, b);

    /* Inicializa res com 0. Não há problema caso (res = a) ou (res = b) pois os valores das duas foram armazenadas nas auxiliares anteriormente */
    big_val(res, 0);

    for(i = 0; i < NUM_BITS/8; i++) {
        while (num2[i]) {
            if (num2[0] & ehImpar)
                big_sum(res, res, num1);
            big_shl(num1, num1, 1);
            big_shr(num2, num2, 1);
        }
    }
    return;
}
