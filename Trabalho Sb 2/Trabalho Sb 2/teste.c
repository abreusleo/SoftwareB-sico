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

int main(void) {
	long val1 = 1, n = 1;
    BigInt a, b, res;

    big_val(a, val1);
	big_shl(res, a, n);


	print_bigInt(res);


    return 0;
}