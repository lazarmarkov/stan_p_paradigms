#include <stdio.h>
#include <string.h>

int lsearch(int key,
            int array[],
            int size)
{
    for(int i=0; i < size; i++) {
        if(array[i] == key) {
            return i;
        }
    }
    return -1;
}

int intCmp(void *elem1, void *elem2) {
    int *ip1 = elem1;
    int *ip2 = elem2;
    return *ip1 - *ip2;
}

void *lsearchg(void *key,
             void *base,
             int n,
             int elemSize,
             int (*cmpfn)(void*, void*)
             )
{
    for(int i=0; i<n; i++) {
        // The compiler won't let you do pointer arithmetic against a void*. That's why the (char*) is required so that it knows how to use `+ i * elemSize`.
        void *elemAddr = (char*)base + i * elemSize; 
        if(cmpfn(key, elemAddr) == 0) {
            return elemAddr;
        }
    }
    return NULL;
}

int StrCmp(void *vp1, void *vp2) {
    char *s1 = *(char**)vp1;
    char *s2 = *(char**)vp2;
    return strcmp(s1, s2);
}


int main() {
    int arr[6] = {4,2,3,7,11,6};
    int size = 6;
    int number = 7;

    printf("Location of %d in arr: %d\n", number, lsearch(number, arr, size));

    int* found = lsearchg(&number, arr, size, sizeof(int), intCmp);
    if(found != NULL) {
        printf("%d found in array\n", number);
    }

    // **char = pointer to a char*.

    char *notes[] = {"Ab", "F#", "B", "Gb", "D"};
    char *favoriteNote = "F#";

    // Passing the address of favioriteNote allows StrCmp to receive identical data types (char**).
    char **found2 = lsearchg(&favoriteNote, notes, 5, sizeof(char*), StrCmp);
    if (found2 != NULL) {
        printf("%s found in array\n", *found2);
    }

    return 0;
}