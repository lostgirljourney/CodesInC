#include <stdio.h>
#include <stdlib.h>

typedef struct stk
{
    int size, top, *arr;
} stack;

int is_full(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int is_empty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *s, int element)
{
    if (is_full(s))
    {
        printf("Overflow.\n");
        return;
    }
    s->top += 1;
    s->arr[s->top] = element;
}

void pop(stack *s)
{
    if (is_empty(s))
    {
        printf("Underflow.\n");
        return;
    }
    printf("Popped Element is: %d\n", s->arr[s->top]);
    s->top -= 1;
}

void print_stack_top(stack *s)
{
    printf("Top Element is: %d\n", s->arr[s->top]);
}

int main()
{
    stack ps, *s = &ps;
    s->top = -1;
    int num = 1, element;
    printf("Enter the size of arr: ");
    scanf("%d", &s->size);
    s->arr = (int *)malloc(s->size*sizeof(int));

    while (num != 0)
    {
        printf("\nOperations to be performed:\n");
        printf("1. Push elements in the stack.\n");
        printf("2. Push elements in the stack.\n");
        printf("3. Print the stack top elements.\n");
        printf("0. Exit.\n");

        printf("\nEnter the operation (1-3 or 0 to exit): ");
        scanf("%d", &num);

        if (num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            push(s, element);
        }
        else if (num == 2)
        {
            pop(s);
        }
        else if (num == 3)
        {
            print_stack_top(s);
        }
        else if (num > 3 || num < 0)
        {
            printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}