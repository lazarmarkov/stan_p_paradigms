#include <stdio.h>
#include <string.h>

// memory
// [c|c|c|c]
// [b|b|b|b]
// [b|b|b|b]
// [a|a|a|a]

struct student {
    char *name;
    char suid[8];
    int numUnits;
};

int main(){
    struct student pupils[4];
    pupils[0].numUnits = 2;
    pupils[1].name = strdup("Jake");
    pupils[2].name = strdup("Adam"); // dynamically allocated in the heap, 5 bytes w/ \0. strdup returns address of 'A'. strdup = malloc + strcpy.
    pupils[3].name = pupils[0].suid + 6; // name points to the memory location of 0.suid's 6th char.
    strcpy(pupils[1].suid, "40415xx");
    strcpy(pupils[3].name, "123456");
    return 0;
}
