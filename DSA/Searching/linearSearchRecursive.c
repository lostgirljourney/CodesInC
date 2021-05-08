#include<stdio.h>

int linearSearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return linearSearch(arr, l + 1, r - 1, x);
}

int main()
{
    int element, size, searchIndex;
    
    printf("Give the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the array element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &element);
    
    searchIndex = linearSearch(arr, 0, size-1, element);
    
    if (searchIndex == -1)
    {
        printf("Element not found.");
    }
    else
    {
        printf("Index is %d.", searchIndex);
    }
    return 0;
}