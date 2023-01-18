#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "5b_stack.h"

void StackNew(stack *s) {
    s->logicalLength = 0;
    s->alloclength = 4;
    s->elems = malloc(s->alloclength * sizeof(int));

    assert(s->elems != NULL);
}

void StackDestroy(stack *s) {
    free(s->elems);
}

void StackPush(stack *s, int value) {
    if(s->logicalLength == s->alloclength) {
        s->alloclength *= 2;
        s->elems = realloc(s->elems, s->alloclength * sizeof(int));

        assert(s->elems != NULL);
    }
    s->elems[s->logicalLength] = value;
    s->logicalLength++;
}

int StackPop(stack *s) {
    assert(s->logicalLength != 0);
    s->logicalLength--;
    return s->elems[s->logicalLength];
}

void StackPrint(stack *s) {
    printf("logLen: %d, allocLen: %d\n", s->logicalLength, s->alloclength);
    if(s->logicalLength > 0){ 
        for(int i=0; i < s->logicalLength; i++) {
            printf("%dth elem: %d\n", i+1, s->elems[i]);
        }
    }
}
