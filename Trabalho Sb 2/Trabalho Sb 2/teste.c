
#include <stdio.h>
#include "bigint.h"

int main(void) {
    
    long val1 = 1, n = 8;
    // int shift = 13;
    BigInt a, res, res2;

    big_val(a, val1);
    print_bigInt(a);
    big_shl(res, a, n);
    printf("\n\n");
    
    print_bigInt(res);
    
    big_sar(res2, res, n);
    print_bigInt(res2); 

    return 0;
}
