#include <stdio.h>
#include <stdlib.h>

typedef struct stk
{
    int data;
    struct stk *next;
} stack;

stack *push(stack **head, int element)
{
    stack *newnode = (stack *)malloc(sizeof(stack)), *temp = *head;
    newnode->data = element;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    temp = newnode;
    return *head;
}

stack *pop(stack **head)
{
    stack *prevend = *head, *end = (*head)->next;
    if((*head)->next == NULL)
    {
        printf("Popped Element: %d\n",(*head)->data);
        free(*head);
        *head = NULL;
    }
    else
    {
        while(end->next!=NULL)
        {
            prevend = prevend->next;
            end = end->next;
        }
        printf("Popped Element: %d\n",end->data);
        prevend->next = NULL;
        free(end);
    }
    return *head;
}

int main()
{
    stack *head = NULL;
    int num = 1, element;

    while (num != 0)
    {
        printf("\nOperations to be performed:\n");
        printf("1. Push elements in the stack.\n");
        printf("2. Push elements in the stack.\n");
        printf("0. Exit.\n");

        printf("\nEnter the operation (1-2 or 0 to exit): ");
        scanf("%d", &num);

        if (num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            head = push(&head, element);
        }
        else if (num == 2)
        {
            if(head == NULL)
            {
                printf("Underflow.\n");
            }
            else
            {
                head = pop(&head);
            }
        }
        else if (num > 2 || num < 0)
        {
            printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}