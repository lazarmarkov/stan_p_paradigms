#include <stdio.h>
#include <string.h>

int main(){
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

    return 0;
}
