#include <stdio.h>

void insertion_sort(int arr[], int n);

int main()
{
    int arr[10] = {34, 12, 5, 33, 23, 7, 1, 2, 9, 88};
    int i, n = 10;

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

    for (i = 1; i < n; i++)
    {

        // {34, 12, 5, 33, 23, 7, 1, 2, 9, 88};
        // { 12, 34, 5, 33, 23, 7, 1, 2, 9, 88};
        // { 12, 5, 34,  33, 23, 7, 1, 2, 9, 88};
        // { 5,12, 34,  33, 23, 7, 1, 2, 9, 88};
        item = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = item;
    }
};