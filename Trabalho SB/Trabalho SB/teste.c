#include <stdio.h>
#include "bigint.h"

int main(void) {
	long val = 1;
	BigInt a;
	int i;


	big_val(a, val);

	for(i = 0; i < NUM_BITS / 8; i++)
		printf("%02x", a[i]);

	return 0;
}