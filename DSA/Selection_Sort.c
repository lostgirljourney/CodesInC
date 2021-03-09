#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, temp, loc;
    for (i = 0; i < n - 1; i++)
    {
        loc = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[loc])
            {
                loc = j;
            }
        }
        if (loc != i)
        {
            temp = arr[i];
            arr[i] = arr[loc];
            arr[loc] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element (%d): ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}