#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
    int size, f, r, *arr;
} queue;

int isFull(queue *q)
{
    if ((q->f == 0 && q->r == q->size - 1) || (q->r == q->f - 1))
        return 1;
    return 0;
}

int isEmpty(queue *q)
{
    if (q->f == -1)
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

    if (q->f == -1)
    {
        q->f = q->r = 0;
    }
    else
    {
        if (q->r == q->size - 1)
        {
            q->r = 0;
        }
        else
        {
            q->r = q->r + 1;
        }
    }
    q->arr[q->r] = val;
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow!\n");
        return;
    }
    
    printf("Deleted Element: %d\n", q->arr[q->f]);

    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
    {
        if (q->f == q->size - 1)
        {
            q->f = 0;
        }
        else
        {
            q->f = q->f + 1;
        }
    }
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
            printf("Enter the element to insert: ");
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