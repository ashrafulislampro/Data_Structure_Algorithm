#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int i, j, index_min, temp;

    for (i = 0; i < n - 1; i++)
    {
        index_min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }
        if (index_min != i)
        {
            temp = arr[i];
            arr[i] = arr[index_min];
            arr[index_min] = temp;
        }
    }
}

int main()
{
    int arr[] = {23, 44, 5, 2, 8, 10, 12, 3, 1, 4};
    int n = 10;

    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    return 0;
}