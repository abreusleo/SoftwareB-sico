//JOÃO MARCELLO BESSA RODRIGUES - 1720539 - 3WA
//LEONARDO DOS SANTOS ABREU - 1720565 - 3WB

//eae men

#include <stdio.h>
void dump (void *p, int n) {
 unsigned char *p1 = p;
 while (n--) {
 printf("%p - %02x\n", p1, *p1);
 p1++;
 }
}


int main() {
 int num = 0x01020304;
dump(&num, sizeof(int));
 return 0;
}
