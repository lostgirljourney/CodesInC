#include<stdio.h>

int binarySearch(int arr[], int low, int high, int element)
{
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] < element)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[100], element, size, searchIndex;
    
    printf("Give the size of the array (upto 100): ");
    scanf("%d", &size);

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the array element: ", i);
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