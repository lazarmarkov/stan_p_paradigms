typedef struct {
    int *elems;
    int logicalLength;
    int alloclength;
} stack;

void StackNew(stack *s);
void StackDestroy(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);
void StackPrint(stack *s);