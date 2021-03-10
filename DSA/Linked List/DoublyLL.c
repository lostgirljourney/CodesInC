#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void createDLL(struct node **head, int size)
{
    struct node *newnode, *temp;
    if (*head != NULL)
    {
        printf("Already created!\n");
        return;
    }
    else
    {
        for (int i = 1; i <= size; i++)
        {
            printf("Enter the element: ");
            newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            if (*head == NULL)
            {
                *head = newnode;
                newnode->prev = NULL;
            }
            else
            {
                temp->next = newnode;
                newnode->prev = temp;
            }
            temp = newnode;
        }
    }
    return;
}

void traversalDLL(struct node *head)
{
    struct node *loc, *current;
    loc = head;
    printf("List is (from left to right): ");
    while (loc != NULL)
    {
        printf("%d ", loc->data);
        current = loc;
        loc = loc->next;
    }
    printf("\n");
    loc = current;
    printf("List is (from right to left): ");
    while (loc != NULL)
    {
        printf("%d ", loc->data);
        loc = loc->prev;
    }
    printf("\n");
}

//Insertion

struct node *insert_start(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return head;
}

struct node *insert_end(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)), *loc = head;
    newnode->data = data;

    while (loc->next != NULL)
    {
        loc = loc->next;
    }
    newnode->prev = loc;
    loc->next = newnode;
    newnode->next = NULL;
    return head;
}

// Deletion

struct node *delete_start(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Empty List. Deletion is impossible!\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        printf("\nInformation on deleted note is %d\n", temp->data);
        free(temp);
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *loc = head, *locn = head->next;
    if (head == NULL)
    {
        printf("Empty List. Deletion is impossible!\n");
    }
    else
    {
        while (locn->next != NULL)
        {
            loc = locn;
            locn = locn->next;
        }
        loc->next = NULL;
        locn->prev = NULL;
        printf("\nInformation on deleted note is %d\n", locn->data);
        free(locn);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int size, num, element, info, index;
    printf("Enter the size of Linked node: ");
    scanf("%d", &size);
    createDLL(&head,size);

    do
    {
        printf("\nOperations to be performed:\n");
        printf("1. Insertion at the starting.\n");       
        printf("2. Insertion at the end.\n");
        printf("3. Deletion at the starting.\n");       
        printf("4. Deletion at the end.\n");
        printf("5. Traverse the Linked List.\n");        
        printf("6. Exit.\n");        

        printf("\nEnter the operation (1-6): ");
        scanf("%d", &num);

        if(num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            head = insert_start(head, element);
        }
        else if(num == 2)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            head = insert_end(head, element);
        }
        else if(num == 3)
        {
            head = delete_start(head);
        }
        else if(num == 4)
        {
            head = delete_end(head);
        }
        else if(num == 5)
        {
            traversalDLL(head);
        }
        else if(num > 6 || num < 1)
        {
            printf("Invalid option! Try again.\n");
        }
    }while(num != 6);

    return 0;
}