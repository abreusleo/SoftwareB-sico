#include <stdio.h>
#include "bigint.h"

#include <stdio.h>
#include "bigint.h"

int main(void) {
    
    long numA = 1000000, numB = 1, numC = 1000, numD = 5000;
    
    BigInt bigA, bigB, bigC, bigD; /*BigInts*/
    BigInt compA, compB, compC, compD; /*Complementos*/
    BigInt soma1, soma2, soma3; /*Soma dos BigInts*/
    BigInt sub1, sub2, sub3; /*Subtracao dos BigInts*/
    BigInt mult1, mult2, mult3; /*Multiplicacao dos BigInts*/
    BigInt shiftlA, shiftlB, shiftlC, shiftlD; /*Shift para a esquerda*/
    BigInt shrA, shrB, shrC, shrD; /*Shift logico para a direita*/
    BigInt sarA, sarB, sarC, sarD; /*Shift aritmetico para a direita*/
    
    
    /*- Criando os BigInts, com base nos longs -*/
    
    big_val(bigA, numA);
    big_val(bigB, numB);
    big_val(bigC, numC);
    big_val(bigD, numD);
    
    /*- Visualização dos BigInts -*/
    
    printf("\n\n VISUALIZACAO BIG INTS \n");
    
    printf("\n\nBigInt A: \n");
	print_bigInt(bigA);

	printf("\n\nBigInt B: \n");
	print_bigInt(bigB);

	printf("\n\nBigInt C: \n");
	print_bigInt(bigC);
    
    printf("\n\nBigInt D: \n");
	print_bigInt(bigD);
	
	printf("\n------------------------------------------------\n");
    
    /*- Comparando BigInts -*/
    big_comp2(compA, bigA);
    big_comp2(compB, bigB);
    big_comp2(compC, bigC);
    big_comp2(compD, bigD);
    
    /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO COMP2 \n");
    
	printf("\n\nInverte bigA: \n");
	print_bigInt(compA);

	printf("\n\nInverte bigB: \n");
	print_bigInt(compB);
    
    printf("\n\nInverte bigC: \n");
	print_bigInt(compC);

	printf("\n\nInverte bigD: \n");
	print_bigInt(compD);
	
	printf("\n------------------------------------------------\n");
    
    /*- Soma de BigInts -*/
    
    big_sum(soma1, bigA, bigB);
	big_sum(soma2, bigB, bigC);
	big_sum(soma3, bigB, bigB);
    
    /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO SOMA \n");
    
    printf("\n\nSoma A + B: \n");
	print_bigInt(soma1);

	printf("\n\nSoma B + C: \n");
	print_bigInt(soma2);

	printf("\n\nSoma B + B: \n");
	print_bigInt(soma3);
    
    printf("\n------------------------------------------------\n");
    
    /*- Subtracao de BigInts -*/
    big_sub(sub1, bigA, bigB);
    big_sub(sub2, bigA, bigA);
    big_sub(sub3, bigC, bigA);
    
        /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO SUBTRACAO \n");
    
    printf("\n\nSubtracao A - B: \n");
	print_bigInt(sub1);

	printf("\n\nSubtracao A - A: \n");
	print_bigInt(sub2);

	printf("\n\nSubtracao C - A: \n");
	print_bigInt(sub3);
    
    printf("\n------------------------------------------------\n");

     /*- Multiplicacao de BigInts -*/
    big_mul(mult1, bigA, bigB);
    big_mul(mult2, bigA, bigA);
    big_mul(mult3, bigC, bigA);
    
        /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO MULTIPLICACAO \n");
    
    printf("\n\nMultiplicacao A * B: \n");
	print_bigInt(mult1);

	printf("\n\nMultiplicacao A * A: \n");
	print_bigInt(mult2);

	printf("\n\nMultiplicacao C * A: \n");
	print_bigInt(mult3);
    
    printf("\n------------------------------------------------\n");
    
     /*- Shift de BigInts para a esquerda -*/
    big_shl(shiftlA, bigA, 8);
    big_shl(shiftlB, bigA, 11);
    big_shl(shiftlC, bigC, 16);
    big_shl(shiftlD, bigC, 7);
    
        /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO SHIFT PARA ESQUERDA \n");
    
    printf("\n\nShift A<<8: \n");
	print_bigInt(shiftlA);

	printf("\n\nShift A<<11: \n");
	print_bigInt(shiftlB);

	printf("\n\nShift C<<16: \n");
	print_bigInt(shiftlC);
    
	printf("\n\nShift C<<7: \n");
	print_bigInt(shiftlD);
    
    printf("\n------------------------------------------------\n");
        
     /*- Shift Lógico de BigInts para a direita -*/
    big_shr(shrA, bigA, 16);
    big_shr(shrB, bigA, 3);
    big_shr(shrC, bigD, 8);
    big_shr(shrD, bigD, 21);
    
        /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO SHIFT LOGICO PARA DIREITA \n");
    
    printf("\n\nShift A>>16: \n");
	print_bigInt(shrA);

	printf("\n\nShift A>>3: \n");
	print_bigInt(shrB);

	printf("\n\nShift C>>8: \n");
	print_bigInt(shrC);
    
	printf("\n\nShift C>>21: \n");
	print_bigInt(shrD);
    
    printf("\n------------------------------------------------\n");
    
            
     /*- Shift Lógico de BigInts para a direita -*/
    big_sar(sarA, bigA, 8);
    big_sar(sarB, compA, 26);
    big_sar(sarC, compC, 1);
    big_sar(sarD, bigD, 6);
    
        /*- VISUALIZACAO -*/
    
    printf("\n\n VISUALIZACAO SHIFT ARTMETICO PARA DIREITA \n");
    
    printf("\n\nShift A>>8: \n");
	print_bigInt(sarA);

	printf("\n\nShift (-A)>>26: \n");
	print_bigInt(sarB);

	printf("\n\nShift (-C)>>1: \n");
	print_bigInt(sarC);
    
	printf("\n\nShift D>>6: \n");
	print_bigInt(sarD);
    
    printf("\n------------------------------------------------\n");
    
    return 0;
}
