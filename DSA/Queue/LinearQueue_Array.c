#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
    int size, f, r, *arr;
} queue;

int isFull(queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("Overflow!\n");
        return;
    }
    q->r = q->r + 1;
    q->arr[q->r] = val;
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow!\n");
        return;
    }
    q->f = q->f + 1;
    printf("Deleted Element: %d\n", q->arr[q->f]);
    return;
}

int main()
{
    queue q;
    printf("Enter the size of Queue: ");
    scanf("%d", &q.size);
    q.f = q.r = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);
    int num = 1, element;

    while (num != 0)
    {
        printf("\nOperations to be performed:\n");
        printf("1. Insertion.\n");
        printf("2. Deletion.\n");
        printf("0. Exit.\n");

        printf("\nEnter the operation (1-2 or 0 to exit): ");
        scanf("%d", &num);

        if (num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            enqueue(&q, element);
        }
        else if (num == 2)
        {
            dequeue(&q);
        }
        else if (num > 2 || num < 0)
        {
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}