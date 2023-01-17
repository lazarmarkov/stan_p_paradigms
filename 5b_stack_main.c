#include <stdio.h>
#include "lecture5_ii_stack.h"

int main() {
    stack s;

    printf("Creating empty stack...\n");
    StackNew(&s);
    StackPrint(&s);

    printf("\nAdding elems to stack...\n");

    for(int i=0; i<5; i++){
        StackPush(&s, i);
    }

    StackPrint(&s);

    printf("\nRemoving elems...\n");

    for(int i=0; i<5; i++){
        StackPop(&s);
    }

    StackPrint(&s);

    return 0;
}