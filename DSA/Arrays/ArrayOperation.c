#include<stdio.h>

void display(int arr[], int n)  // Traversal
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size-1; i >= index; i--)
        {
            arr[i+1] = arr[i];

        }
        arr[index] = element;
        return 0;
    }
}

int indDeletion(int arr[], int size, int capacity, int index)
{
    if(index>=capacity)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        return 0;
    }
}

int main()
{
    int size, num, element, index, arr[100];
    
    printf("Give the size of the array (upto 99): ");
    scanf("%d", &size);

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the array element: ", i);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nOperations to be performed:\n");
        printf("1. Insertion at a specific index.\n");       
        printf("2. Deletion from a specific index.\n");        
        printf("3. Reverse the array.\n");        
        printf("4. Traverse the array.\n");        
        printf("5. Exit.\n");        

        printf("\nEnter the operation (1-5): ");
        scanf("%d", &num);

        if(num == 1)
        {
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the index: ");
            scanf("%d", &index);
            int res = indInsertion(arr, size, element, 100, index);
            if(res == -1)
            {
                printf("Insertion failed. :(\n");
            }
            else
            {
                printf("Insertion done. :)\n");
                size++;
            }
        }
        else if(num == 2)
        {
            printf("\nEnter the index: ");
            scanf("%d", &index);
            int res = indDeletion(arr, size, 100, index);
            if(res == -1)
            {
                printf("Deletion failed. :(\n");
            }
            else
            {
                printf("Deletion done. :)\n");
                size--;
            }
        }
        else if(num == 3)
        {
            printf("Printing array in the reverse manner!\n");
            for (int i = size-1; i >= 0; i--)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if(num == 4)
        {
            printf("Printing array!\n");
            display(arr,size);
        }

    }while(num != 5);

    return 0;
}

/*
OUTPUT:
Give the size of the array (upto 99): 5

Enter the array element: 1
Enter the array element: 2
Enter the array element: 3
Enter the array element: 4
Enter the array element: 5

Operations to be performed:       
1. Insertion at a specific index. 
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 1

Enter the element to insert: 6
Enter the index: 5
Insertion done. :)

Operations to be performed:
1. Insertion at a specific index.
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 4
Printing array!
1 2 3 4 5 6

Operations to be performed:
1. Insertion at a specific index.
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 3
Printing array in the reverse manner!
6 5 4 3 2 1

Operations to be performed:
1. Insertion at a specific index.
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 2

Enter the index: 5
Deletion done. :)

Operations to be performed:
1. Insertion at a specific index.
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 4
Printing array!
1 2 3 4 5

Operations to be performed:
1. Insertion at a specific index.
2. Deletion from a specific index.
3. Reverse the array.
4. Traverse the array.
5. Exit.

Enter the operation (1-5): 5
*/