#include <stdio.h>

int main(){
    // No cast needed, as short take on the value of char 'A' which is 65.
    // In terms of memory allocation, char is 1 byte and short is 2 bytes, 
    // but since 'A' bit pattern starts with zero - 01000001, the second new byte is 0x00 and it works.
    char ch = 'A';
    short s = ch;
    printf("%d\n", s);

    // convert 2 byte into 1byte - C only looks at the smallest byte. Prints "C".
    short s2 = 67;
    char ch2 = s2;
    printf("%c\n", ch2);

    // "Sign extend:"
    // -1 bit pattern: 11111111 11111111
    // assigning to int, it puts the sign bit all the way to the left:
    // 1---0 0---0 01111111 11111111
    short s3 = -1;
    int i = s3;
    printf("%d\n", i);

    i = 5;
    float f = i;
    printf("%f\n", f);

    // the bit pattern doesn't change, i is seduced to think it's a float* and then dereferenced.
    i = 37;
    f = *(float *)&i;
    printf("%f\n", f);

    // Float is 4-byte:
    // [a][b][c][d]
    // Short is copied as 2-byte:
    // [a][b]
    float f2 = 7.0;
    s2 = *(short*)&f2;
    printf("float to short: %d\n", s2);

    return 0;
}