typedef struct {
    int *elems;
    int logicalLength;
    int alloclength;
} stack;

void *StackNew(stack *s);