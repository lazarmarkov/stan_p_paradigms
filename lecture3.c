#include <stdio.h>
#include <string.h>

// Structs.

// memory
// [bbbb]
// [aaaa]

struct fraction {
    int num;
    int denum;
};


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

void defineFraction(){
    struct fraction pi;
    pi.num = 22;
    pi.denum = 7;

    printf("num: %d, denum: %d\n", pi.num, pi.denum);

    // store num in denum as "fraction" is pointing at original + offet(4).
    ((struct fraction*)&pi.denum)->num = 12;

    printf("num: %d, denum: %d\n", pi.num, pi.denum);

   // not concerned that I do not own the address below fraction.denum and will store denum representation in end+4 bytes from my struct.
   ((struct fraction*)&pi.denum)->denum = 12;
}

void arrays101(){
    // array = &array[0] - array variable is equal to the address of the 1st element in the array. You can reference anything pass that, as long as length of array is known.
    // i.e. `array + k = &array[k]`, where array is int* and k is scaled by size of int.
    int array[10];
    array[0] = 44;
    array[9] = 100;
    //array[10] = 1; // writes beyond the array.

    // [ 0, 0, 0, 128, 0 ]
    // [ 0, 0, 0, ]
    int arr[5];
    for (int i=0; i<5; i++) 
        arr[i] = 0;

    arr[3] = 128;
    ((short*)arr)[7] = 1;
    printf("%d\n", arr[3]);

    // writes at the most significant short in array[4];
    ((short*)((char*)&arr[1] +8))[2] = 100;
}

void student(){
    struct student pupils[4];
    pupils[0].numUnits = 2;
    pupils[1].name = strdup("Jake");
    pupils[2].name = strdup("Adam"); // dynamically allocated in the heap, 5 bytes w/ \0. strdup returns address of 'A'. strdup = malloc + strcpy.
    pupils[3].name = pupils[0].suid + 6; // name points to the memory location of 0.suid's 6th char.
    strcpy(pupils[1].suid, "40415xx");
    strcpy(pupils[3].name, "123456");
}

// ap and bp are pointers to the memory location of x and y. By *ap, I'm going returning the value at that location.
// allude to generic swap function in next lecture.
void swap(int *ap, int *bp){
    int temp = *ap;

    // The space addressed by ap is identified as the l-value (recipient) of whatever the righthand side evals to.
    *ap = *bp;

    *bp = temp;
}

int main(){
    defineFraction();
    arrays101();
    student();
    
    // int swap
    int x = 7;
    int y = 117;

    return 0;
}
