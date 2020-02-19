#include <stdio.h>

#define BINARYSIZE 8
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, const char* argv[]){
  unsigned x = 213;
  unsigned y = 121;
  int p = 4;
  int n = 4;

  x = setbits(x, p, n, y);
  printf("%u\n", x);

  return 0;
}
unsigned setbits(unsigned x, int p, int n, unsigned y){
  return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}
