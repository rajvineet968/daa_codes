#include<stdio.h>
#include<sys/time.h>

void swap(int *a ,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int part(int arr[],int l, int r){
    int pivot=arr[r];
    int i=l-1,j;
    for(j=l;j<r;j++){
        if(pivot>arr[j])
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
}
void quick(int arr[],int l,int r){
    if (l<r){
        int pat=part(arr,l,r);
        quick(arr,l,pat-1);
        quick(arr,pat+1,r);
    }
}
int uniqueness(int arr[],int s)
{
    for(int i=0;i<s-1;i++){
        if(arr[i]==arr[i+1])
            return 1;
    }
    return 0;
}
int main(){
    struct timeval start,end;
    struct timezone ind;
    int s,i;
    printf("Enter the size of array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter elts!!\n");
    for(i=0;i<s;i++){
        scanf("%d",&arr[i]);
    }
    gettimeofday(&start,&ind);
    quick(arr,0,s-1);
    gettimeofday(&end,&ind);
    printf("Sorted Array!!\n");
    for(i=0;i<s;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Time reqd in us: %lf",((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1e6));
    int a=uniqueness(arr,s);
    if (a==1){
        printf("Not Unique");
    }
    else{
        printf("Unique");
    }
    return 0;
}