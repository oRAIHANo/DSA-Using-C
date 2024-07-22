/*

Bubble sort gets its name from the fact that lighter data(bubbles) floats at the top of the dataset.
Bubble sort is alternatively called "sinking sort" for the opposite reason, which is that some elements of data sink to the bottom of the dataset.
Example - In an array of elements {1,2,3,4,5}
1 is lighter thus comes first or top
5 is hevier thus comes last or bottm

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

Bubble Sort works on the basic principle of swapping

Bubble Sort Algorithm
1) Traverse from left and compare adjacent elements and the higher one is placed at right side.
2) In this way, the largest element is moved to the rightmost end at first.
3) This process is then continued to find the second largest and place it and so on until the data is sorted.

Total no. of passes - n-1 - If the size of the array is 5 then total number of passes is 4
Total no. of comparisons - n*(n-1)/2
Time complexity - o(n*n)
Bubble Sort is a stable algorithm
Bubble Sort is not Adaptive by default but we convert it to an adaptive sorting algorithm

*/

#include <stdio.h>

int array[] = {1, 9, 8, 7, 6, 10, 2, 3, 4, 5};
// int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = 10;
int temp;
int IsSorted = 0;

// code for Bubble Sort
void BubbleSort()
{
    for (int i = 0; i < size - 1; i++) // for number of pass
    {
        for (int j = 0; j < size - 1 - i; j++) // for comparison in each pass
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// code for Bubble Sort adaptive
void BubbleSortAdaptive()
{
    for (int i = 0; i < size - 1; i++) // for number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        IsSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) // for comparison in each pass
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                IsSorted = 0;
            }
        }
        if (IsSorted)
        {
            return;
        }
    }
}

// code for array traversal
void ArrayTraversal()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    printf("Running Bubble Sort...\n");
    printf("Before Sorting\n");
    ArrayTraversal();
    BubbleSort();
    printf("After Sorting\n");
    ArrayTraversal();
    return 0;
}