#include <stdio.h>

int linearSearch(int a[], int n, int key);
int binarySearch(int a[], int n, int key);

int main()
{
    int n, key, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Linear Search\n2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result;

    switch(choice)
    {
        case 1:
            result = linearSearch(arr, n, key);
            break;

        case 2:
            result = binarySearch(arr, n, key);
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    if(result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result);

    return 0;
}

int linearSearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
        if(a[i] == key)
            return i;

    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int start = 0, end = n - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(a[mid] == key)
            return mid;
        else if(key > a[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}
