#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createCLL(struct node **head, int size)
{
    struct node *newnode, *temp;
    if(*head != NULL)
    {
        printf("Already Created.\n");
    }
    else
    {
        for (int i = 1; i <= size; i++)
        {
            printf("Enter the element: ");
            newnode = (struct node*)malloc(sizeof(struct node));
            scanf("%d", &newnode->data);
            if(*head == NULL)
            {
                *head = newnode;
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;
        }
        newnode->next = *head;
    }
    return;
}

void traversalCLL(struct node *head)
{
    struct node *loc = head;
    if(head == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        printf("List is: ");
        do
        {
            printf("%d ", loc->data);
            loc = loc->next;
        } while (loc != head);
        printf("\n");
    }
    return;
}

// Insertion

struct node *insert_start(struct node *head, int element)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node)), *loc;
    newnode->data = element;
    newnode->next = head;
    loc = head;
    while(loc->next!=head)
    {
        loc = loc->next;
    }
    head = newnode;
    loc->next = newnode;
    return head;
}

struct node *insert_end(struct node *head, int element)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node)), *loc;
    if(head == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        newnode->data = element;
        newnode->next = head;
        loc = head;
        while(loc->next!=head)
        {
            loc = loc->next;
        }
        loc->next = newnode;
    }
    return head;
}

// Deletion

struct node *delete_start(struct node *head)
{
    struct node *loc, *temp;
    if(head == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        printf("Deleted element: %d\n", head->data);
        loc = head;
        temp = head;
        while(loc->next!=head)
        {
            loc = loc->next;
        }
        if(loc == head)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            loc->next = head;
        }
        temp->next = NULL;
        free(temp);
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *locc, *locp;
    if(head == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        locc = head;
        while(locc->next!=head)
        {
            locp = locc;
            locc = locc->next;
        }
        if(locc == head)
        {
            head = NULL;
        }
        else
        {
            locp->next = head;
        }
        locc->next = NULL;
        printf("Deleted element: %d\n", locc->data);
        free(locc);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int size, num, element, info, index;
    printf("Enter the size of Linked node: ");
    scanf("%d", &size);
    createCLL(&head,size);

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
            traversalCLL(head);
        }
        else if(num > 6 || num < 1)
        {
            printf("Invalid option! Try again.\n");
        }
    }while(num != 6);

    return 0;
}