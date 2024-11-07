#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
void selectionSort(int *a, int n)
{
    int indexofmin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
}
int main()
{
    int a[] = {3, 5, 2, 13, 9};
    int n = 5;
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}