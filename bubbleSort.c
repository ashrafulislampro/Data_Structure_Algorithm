#include <stdio.h>

void bubble_sort(int arr[], int n);
int main()
{
    int arr[] = {3, 1, 44, 0, 18, 504, 7, 6, 2};
    int i, n = 9;

    bubble_sort(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // printf("%d ", arr[i]);
    }
    printf("\n");
}