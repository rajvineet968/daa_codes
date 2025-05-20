#include<stdio.h>
#include<sys/time.h>

void toh(int n,char s,char a,char d)
{
    if(n==1){//no use of recursion
        printf("\nMove disk 1 from %c to %c",s,d);
        return;
    }
    toh(n-1,s,a,d);
    printf("\nMove disk %d from %c to %c",n,s,d);
    toh(n-1,a,d,s);
    printf("\nMove disk %d from %c to %c",n,a,s);
}
int main(){
    int n;
    struct timeval start,end;
    struct timezone ind;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    gettimeofday(&start,&ind);
    toh(n,'A','B','C');
    gettimeofday(&end,&ind);
    printf("\nTime taken: %ld microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec));
    return 0;
}