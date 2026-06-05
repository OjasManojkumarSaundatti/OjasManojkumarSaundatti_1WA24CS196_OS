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
