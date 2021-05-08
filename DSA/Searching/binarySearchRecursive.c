#include<stdio.h>

int binarySearch(int arr[], int low, int high, int element)
{
    int mid;
    if(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] < element)
        {
            return binarySearch(arr, mid+1, high, element);
        }
        else
        {
            return binarySearch(arr, low, mid-1, element);
        }
    }
    return -1;
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
    
    searchIndex = binarySearch(arr, 0, size-1, element);
    
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