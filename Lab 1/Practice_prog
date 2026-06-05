Practice Program

Practice Program 1

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

OUTPUT:

Enter size of array: 5
Enter elements:
1
2
4
5
6

1. Linear Search
2. Binary Search
Enter choice: 1
Enter element to search: 2
Element found at position 1

Enter size of array: 5
Enter elements:
1
2
3
4
5

1. Linear Search
2. Binary Search
Enter choice: 2
Enter element to search: 5
Element found at position 4

Practice Program 2

#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int smallest = arr[0];
    int position = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            position = i;
        }
    }

    printf("Smallest element is %d\n", smallest);
    printf("Position is %d\n", position);

    return 0;
}

OUTPUT:

Enter size of array: 5
Enter elements:
1
2
3
4
5
Smallest element is 1
Position is 0

Practice Program 3

#include <stdio.h>

int main()
{
    int n, flag = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1)
        printf("Duplicates exist\n");
    else
        printf("No duplicates found\n");

    return 0;
}

OUTPUT:

Enter size of array: 4
Enter elements:
1
2
3
3
Duplicates exist
