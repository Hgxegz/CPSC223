#include <stdio.h>

#define BYTESIZE 8

unsigned rightrot(unsigned x, int n);

int main(void)
{
     unsigned x;
     int n;

     x = 10111001;
     n = 2;

     printf("%x\n", rightrot(x, n));

     return 0;
}

unsigned rightrot(unsigned x, int n) {
    int size;
    unsigned y;

    size = 0;
    y = x;

    while (y != 0) {
    y = y << BYTESIZE;
    size++;
    }
    size = size * BYTESIZE;

    return (x << (size-n)) | (x >> n);
}
