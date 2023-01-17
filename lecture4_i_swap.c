#include <string.h>
#include <stdio.h>

// Integer swap function.
// ap and bp are pointers to the memory location of x and y. By *ap, I'm going returning the value at that location.
// allude to generic swap function in next lecture.
void swap(int *ap, int *bp){
    int temp = *ap;

    // The space addressed by ap is identified as the l-value (recipient) of whatever the righthand side evals to.
    *ap = *bp;

    *bp = temp;
}

// Generic swap function.
// Generic pointer type void* mean it points to something that it doesn't have type information for.
// The third argument specifies the number of bytes the function should swap.
void swapg(void *vp1, void *vp2, int size) {
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

// The perk in C, swapg results in a single assembly code.
// In C++ templates, swapg extends to a swapg of int or swapg of double and compiles to a int-specific domain or double-specific domain. If you call swap on 50 different types, you get 50 copies of the function in your executible. 
// C is very lean.
// The problem is that it's very easy to make a mistake in a generic C implementation. It's even easier to pass the wrong arguments, as void* "sedates" the compiler to not complain, where otherwise it would complain. You *do* want the compiler to aid you, but in C you're risking more.
int main() {
    int x = 7;
    int y = 117;
    printf("x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    swapg(&x, &y, sizeof(int));
    printf("x: %d, y: %d\n", x, y);

    double d = 3.14;
    double e = 1.59;
    swapg(&d, &e, sizeof(double));
    printf("d: %f, e: %f\n", d, e);

    // On BE system, it'll put the5 in the upper half of i and not touch the 44.
    // On LE system, it'll get it right but it'll be a miracle.
    int i = 44;
    short s = 5;
    swapg(&i, &s, sizeof(short));
    printf("i: %d, s: %d\n", i, s);

    char* husband = strdup("Fred");
    char* wife = strdup("Wilma");

    swapg(&husband, &wife, sizeof(char*));
    printf("husband: %s, wife: %s\n", husband, wife);

    // In the lecture evaluating the char* instead of passing the address of husband and wife should replace sizeof(char*) bytes in the actual strings, 
    // resulting in "Wilm" and "Freda", but when I ran it on MacOS with gcc it outputs "Wilma" and "Fred" as above.
    swapg(husband, wife, sizeof(char*));
    printf("husband: %s, wife: %s\n", husband, wife);


    return 0;
}