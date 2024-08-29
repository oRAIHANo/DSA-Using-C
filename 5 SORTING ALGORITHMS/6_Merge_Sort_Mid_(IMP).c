#include <stdio.h>

int array[] = {100, 50, 90, 30, 80, 10, 20, 70, 40, 60};
int size = sizeof(array) / sizeof(array[0]);

void Merge(int array[], int low, int mid, int high)
{
    int i, j, k;
    int merged_array[size];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            merged_array[k] = array[i];
            i++;
            k++;
        }
        else
        {
            merged_array[k] = array[j];
            j++;
            k++;
        } 
    }

    while (i <= mid)
    {
        merged_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        merged_array[k] = array[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++)
    {
        array[low + i] = merged_array[i];
    }
}

void MergeSort(int array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, mid, high);
    }
}

void ArrayTraversal()
{
    for (int a = 0; a < size; a++)
    {
        printf("%d ", array[a]);
    }
    printf("\n");
}

int main()
{
    printf("Running Merge Sort...\n");
    printf("Before Sorting\n");
    ArrayTraversal();
    MergeSort(array, 0, size - 1);
    printf("After Sorting\n");
    ArrayTraversal();
    return 0;
}
