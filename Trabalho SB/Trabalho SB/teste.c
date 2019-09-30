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
 long val1 = 8;
    BigInt a;

    big_val(a, val1);

    printf("Valor da dump usando big_val: %016lx\n", val1);
    printf("Função dump normal:\n");	
    dump(a, 16);

    return 0;
}
