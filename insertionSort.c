#include <stdio.h>

void insertion_sort(int arr[], int n);
int main()
{
    int arr[] = {5, 3, 6};
    int i, n = 3;
    // , 6, 2, 4, 1
    insertion_sort(arr, n);
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}

void insertion_sort(int arr[], int n)
{
    int i, j, item;
    // {5, 3, 6, 2, 4, 1}
    // {3, 5,  , 6, 4, 1}
    // {2, 3, 5, 6, 4, 1}
    for (i = 1; i < n; i++)
    {
        item = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = item;
    }
}