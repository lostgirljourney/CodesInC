#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createSLL(struct node **head, int size)
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
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;
        }
    }
    return;
}

void traversalSLL(struct node *head)
{
    struct node *loc;
    loc = head;
    printf("List is: ");
    while (loc != NULL)
    {
        printf("%d ", loc->data);
        loc = loc->next;
    }
    printf("\n");
}

//Insertion

struct node *insert_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}

struct node *insert_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)), *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

void insert_before(struct node **head, int item1, int item2)
{
    struct node *newnode = NULL;
    struct node *temp = *head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int flag = 0;

    if (newnode == NULL)
    {
        printf("Failed to insert element. Out of memory");
        return;
    }

    newnode->data = item2;

    if ((*head)->data == item1)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    while (temp && temp->next)
    {
        if (temp->next->data == item1)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        else
        {
            flag = 1;
        }
        temp = temp->next;
    }

    if (flag == 1)
    {
        printf("Element not found before which data to be stored.\n");
    }
}

void insert_after(struct node *head, int item1, int item2)
{
    struct node *newnode = NULL;
    struct node *temp = head;
    int flag = 0;

    while (temp)
    {
        if (temp->data == item1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Failed to insert element. Out of memory.\n");
            }

            newnode->data = item2;
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        else
        {
            flag = 1;
        }
        temp = temp->next;
    }

    if (flag == 1)
    {
        printf("Element not found after which data to be stored.\n");
    }
}

struct node *insert_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)), *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Deletion

struct node *delete_first(struct node *head)
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
        printf("\nInformation on deleted node is %d\n", temp->data);
        free(temp);
    }
    return head;
}

struct node *delete_index(struct node *head, int index)
{
    struct node *p = head, *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    printf("\nInformation on deleted node is %d\n", q->data);
    free(q);
    return head;
}

struct node *delete_key(struct node *head, int value)
{
    struct node *p = head, *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        printf("\nInformation on deleted node is %d\n", value);
        free(q);
    }
    else
    {
        printf("Element not found!\n");
    }
    return head;
}

struct node *delete_last(struct node *head)
{
    struct node *p = head, *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    printf("\nInformation on deleted node is %d\n", q->data);
    free(q);
    return head;
}

// Count number of elements

int count(struct node *head)
{
    int count = 0;
    struct node *loc = head;
    while (loc != NULL)
    {
        count += 1;
        loc = loc->next;
    }
    return count;
}

// Reverse the Linked List

struct node *reverse(struct node *head)
{
    struct node *locp = NULL, *loc = head, *locn;

    if (head == NULL || head->next == NULL)
    {
        printf("Underflow or only one node present.\n");
    }
    else
    {
        while (loc != NULL)
        {
            locn = loc->next;
            loc->next = locp;
            locp = loc;
            loc = locn;
        }
        head = locp;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int size, num, element, info, index;
    printf("Enter the size of Linked node: ");
    scanf("%d", &size);
    createSLL(&head, size);

    do
    {
        printf("\nOperations to be performed:\n");
        printf("1. Insertion at the starting.\n");
        printf("2. Insertion at the end.\n");
        printf("3. Insertion before a specific element.\n");
        printf("4. Insertion after a specific element.\n");
        printf("5. Insertion at a specific index.\n");
        printf("6. Deletion at the starting.\n");
        printf("7. Deletion at the end.\n");
        printf("8. Deletion from a specific index.\n");
        printf("9. Deletion of a specific element.\n");
        printf("10. Reverse the Linked List.\n");
        printf("11. Count the number of elements of the Linked List.\n");
        printf("12. Traverse the Linked List.\n");
        printf("13. Exit.\n");

        printf("\nEnter the operation (1-13): ");
        scanf("%d", &num);

        if (num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            head = insert_first(head, element);
        }
        else if (num == 2)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            head = insert_end(head, element);
        }
        else if (num == 3)
        {
            printf("\nEnter the data to insert: ");
            scanf("%d", &info);
            printf("\nEnter the element before which data is to be insert: ");
            scanf("%d", &element);
            insert_before(&head, element, info);
        }
        else if (num == 4)
        {
            printf("\nEnter the data to insert: ");
            scanf("%d", &info);
            printf("\nEnter the element after which data is to be insert: ");
            scanf("%d", &element);
            insert_after(head, element, info);
        }
        else if (num == 5)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the index: ");
            scanf("%d", &index);
            head = insert_index(head, element, index);
        }
        else if (num == 6)
        {
            head = delete_first(head);
        }
        else if (num == 7)
        {
            head = delete_last(head);
        }
        else if (num == 8)
        {
            printf("Enter the index: ");
            scanf("%d", &index);
            head = delete_index(head, index);
        }
        else if (num == 9)
        {
            printf("\nEnter the element to delete: ");
            scanf("%d", &element);
            head = delete_key(head, element);
        }
        else if (num == 10)
        {
            head = reverse(head);
        }
        else if (num == 11)
        {
            printf("No. of elements present in Linked List is: %d\n", count(head));
        }
        else if (num == 12)
        {
            traversalSLL(head);
        }
        else if (num > 13 || num < 1)
        {
            printf("Invalid option! Try again.\n");
        }
    } while (num != 13);

    return 0;
}