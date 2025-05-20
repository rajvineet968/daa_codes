#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
// int n;
// int arr[n];
void mergesort(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *arr1 = (int *)malloc(sizeof(int) * n1);
    int *arr2 = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[m+ 1+i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];

    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];
    free(arr1);
    free(arr2);
}

void merge(int arr[], int l, int r)
{
    if (l < r){
        int m = l + (r - l) / 2;
        merge(arr, l, m);
        merge(arr, m + 1, r);
        mergesort(arr, l, m, r);
    }
}

int main()
{
    int i, j,n;
    struct timeval start, end;
    struct timezone ind;
    printf("Enter  number of elts:");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elts:!");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    gettimeofday(&start, &ind);
    merge(arr, 0, n - 1);
    gettimeofday(&end, &ind);
    printf("Sorted Array!!");
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    double time = (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec)*1e6;
    printf("Time : %lf us", time);
    return 0;
}