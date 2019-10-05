#include <stdio.h>
#include "bigint.h"

int main(void) {
    
    long val1 = 10, n = 3;
    // int shift = 13;
    BigInt a, b, res;

    big_val(a, val1);

    print_bigInt(a);
	big_sar(res, a, n);
    dump(res, 16);

    return 0;
}
