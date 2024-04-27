#include <stdio.h>

void bubble_sort(int arr[], int n);
int main()
{
    int arr[10] = {34, 12, 5, 33, 23, 7, 1, 2, 9, 88};
    int n = 10;

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    };

    printf("\n");
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
    }
}