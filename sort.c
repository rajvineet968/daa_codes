#include<stdio.h>
#include<sys/time.h>

void sort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        int min=i;//Keep in mind
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct timeval start, end;
    struct timezone ind;
    gettimeofday(&start, &ind);
    sort(arr,n);
    gettimeofday(&end, &ind);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken to sort the array: %ld microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec));
    return 0;
}