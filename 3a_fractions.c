#include <stdio.h>
#include <string.h>

// memory
// [bbbb]
// [aaaa]

struct fraction {
    int num;
    int denum;
};


int main(){
    struct fraction pi;
    pi.num = 22;
    pi.denum = 7;

    printf("num: %d, denum: %d\n", pi.num, pi.denum);

    // store num in denum as "fraction" is pointing at original + offet(4).
    ((struct fraction*)&pi.denum)->num = 12;

    printf("num: %d, denum: %d\n", pi.num, pi.denum);

   // not concerned that I do not own the address below fraction.denum and will store denum representation in end+4 bytes from my struct.
   ((struct fraction*)&pi.denum)->denum = 12;
    return 0;
}
