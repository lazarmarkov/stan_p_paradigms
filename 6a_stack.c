#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
    void (*freefn)(void*);
} stack;

void StackNew(stack *s, int elemSize, void (*freefn)(void*)) {
    s->logLength = 0;
    s->allocLength = 4;
    s->elems = malloc(4 * elemSize);
    s->elemSize = elemSize;
    s->freefn = freefn;

    assert(s->elems != NULL);
}

void StackDestroy(stack *s) {
    if(s->freefn != NULL) {
        for(int i=0; i < s->logLength; i++){
            void *elemAddr = (char*)s->elems + i * s->elemSize;
            s->freefn(elemAddr);
        }
    }
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

void StrDispose(void *vp){
    printf("freeing %s from StrDispose\n", *(char**)vp);
    free(*(char**)vp);
}

int main() {
    // Double stack
    stack s;
    double d = 3.4;

    StackNew(&s, sizeof(double), NULL);
    StackPush(&s, &d);
    
    double result;
    StackPop(&s, &result);

    printf("stack pop: %lf\n", result);

    //String stack
    char *friends[] = {"Al", "Bob", "Chris", "Dean"};
    stack stringStack;
    StackNew(&stringStack, sizeof(char*), StrDispose);

    for(int i=0; i<4; i++){
        char *copy = strdup(friends[i]);
        StackPush(&stringStack, &copy); }

    char *popped;
    for(int i=0; i<2; i++) {
        StackPop(&stringStack, &popped);
        printf("freeing %s from main\n", popped);
        free(popped);
    }
    StackDestroy(&stringStack);

    return 0;
}
