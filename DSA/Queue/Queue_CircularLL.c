#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
    int data;
    struct que *next;
} queue;

int isEmpty(queue *front)
{
    if (front == NULL)
        return 1;
    return 0;
}

void enqueue(queue **front, queue **rear, int element)
{
    queue *newnode = (queue *)malloc(sizeof(queue));

    if (newnode == NULL)
    {
        printf("Overflow!\n");
        return;
    }

    newnode->data = element;
    newnode->next = NULL;

    if (*front == NULL)
    {
        *front = newnode;
    }
    else
    {
        (*rear)->next = newnode;

    }
    *rear = newnode;
    (*rear)->next = *front;
}

void dequeue(queue **front, queue **rear)
{
    queue *temp = *front;
    if (*front == NULL)
    {
        printf("Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", (*front)->data);

    if(*front == *rear)
    {
        *front = *rear = NULL;
        return;
    }
    *front = temp->next;
    (*rear)->next = *front;
    free(temp);
}

int main()
{
    queue *front = NULL, *rear = NULL;
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
            enqueue(&front, &rear, element);
        }
        else if (num == 2)
        {
            dequeue(&front, &rear);
        }
        else if (num > 2 || num < 0)
        {
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}