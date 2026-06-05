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
