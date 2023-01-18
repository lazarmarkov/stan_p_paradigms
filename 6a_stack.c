#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
} stack;

void StackNew(stack *s, int elemSize) {
    s->logLength = 0;
    s->allocLength = 4;
    s->elems = malloc(4 * elemSize);
    s->elemSize = elemSize;

    assert(s->elems != NULL);
}

void StackDestroy(stack *s) {
    free(s->elems);
}

void StackPush(stack *s, void *elemAddr) {
    if(s->logLength == s->allocLength) {
        s->allocLength *= 2;
        s->elems = realloc(s->elems, s->allocLength * s->elemSize);

        assert(s->elems != NULL);
    }
    void *target = (char*)s->elems + s->logLength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logLength++;
}

void StackPop(stack *s, void *elemAddr) {
    assert(s->logLength != 0);

    s->logLength--;
    void *source = (char*)s->elems + s->logLength * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
}

int main() {
    stack s;
    double d = 3.4;

    StackNew(&s, sizeof(double));
    StackPush(&s, &d);
    
    double result;
    StackPop(&s, &result);

    printf("stack pop: %lf\n", result);
    return 0;
}
