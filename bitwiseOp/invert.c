#include <stdio.h>

unsigned int getbits(unsigned int bitfield, int pos, int num);
unsigned int invert(unsigned int bitfield, int pos, int num);

int main(void)
{
    printf("%d\n", invert(182, 4, 3));
    return 0;
}

/* getbits: get num bits from position pos */
unsigned int getbits(unsigned int bitfield, int pos, int num)
{
    return (bitfield >> (pos+1-n)) & ~(~0 << num);
}

/* invert: flip pos-num bits in bitfield */
unsigned int invert(unsigned int bitfield, int pos, int num)
{
    unsigned int mask;
    unsigned int bits = getbits(bitfield,pos,num);

    mask = (bits << (num-1)) | ((~bits << (pos+1)) >> num);

    return bitfield ^ mask;
}
