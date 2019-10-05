#include <stdio.h>
#include "bigint.h"

/*
COMENTEI A SUA MAIN, SEGUI O MESMO MODELO QUE ELES USARAM PARA TESTAR
int main(void) {
	long val = 8;
	BigInt a;


	big_val(a, val);

	dump(a, val);

	return 0;
}
*/
void print_bigInt(BigInt res) {
	int i = 16;

	while(i--)
		printf("%02x ", res[i]);
	printf("\n\n");
}


int main(void) {
	long val1 = 4095, n = 8;
    BigInt a, b, res;

    big_val(a, val1);
	big_shr(res, a, n);


	print_bigInt(res);


    return 0;
}